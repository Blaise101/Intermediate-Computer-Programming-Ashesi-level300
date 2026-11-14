#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdexcept>

using namespace std;

// a. Course and Student structs
struct Course
{
  string code;
  string title;
  double credits;
  int score;
};

struct StudentRecord
{
  long id;
  string name;
  vector<Course> courses;
};

// a. Custom Exceptions
class InvalidScoreException : public invalid_argument
{
public:
  explicit InvalidScoreException(const string &msg) : invalid_argument(msg) {}
};

class UnknownStudentException : public runtime_error
{
public:
  explicit UnknownStudentException(const string &msg) : runtime_error(msg) {}
};

// Helper lookup for grades
char getGradeLetter(int score)
{
  if (score >= 80)
    return 'A';
  if (score >= 75)
    return 'B';
  if (score >= 70)
    return 'B';
  if (score >= 65)
    return 'C';
  if (score >= 60)
    return 'C';
  if (score >= 55)
    return 'D';
  if (score >= 50)
    return 'D';
  return 'F';
}

int main()
{
  ifstream infile("records.txt");
  ofstream errfile("errors.log");

  if (!infile.is_open())
  {
    cerr << "Error opening records.txt\n";
    return 1;
  }

  vector<StudentRecord> students;
  string line;
  int lineNum = 0;

  while (getline(infile, line))
  {
    lineNum++;
    if (line.empty())
      continue;

    try
    {
      stringstream ss(line);
      string type;
      ss >> type;

      if (type == "STUDENT")
      {
        long id;
        string name;
        ss >> id >> quoted(name);
        students.push_back({id, name, {}});
      }
      else if (type == "COURSE" || type == "GRADE")
      {
        long id;
        string code, title;
        double credits;
        int score;
        ss >> id >> code >> quoted(title) >> credits >> score;

        if (score < 0 || score > 100)
        {
          throw InvalidScoreException("Invalid score: " + to_string(score));
        }

        // Find student
        StudentRecord *targetStudent = nullptr;
        for (auto &s : students)
        {
          if (s.id == id)
          {
            targetStudent = &s;
            break;
          }
        }

        if (!targetStudent)
        {
          throw UnknownStudentException("Unknown student ID: " + to_string(id));
        }

        targetStudent->courses.push_back({code, title, credits, score});
      }
      else
      {
        throw runtime_error("Invalid line start identifier: " + type);
      }
    }
    catch (const InvalidScoreException &e)
    {
      errfile << "Line " << lineNum << ": " << e.what() << "\n";
    }
    catch (const UnknownStudentException &e)
    {
      errfile << "Line " << lineNum << ": " << e.what() << "\n";
    }
    catch (const exception &e)
    {
      errfile << "Line " << lineNum << ": " << e.what() << "\n";
    }
  }

  // d. Write transcript files for each student
  for (const auto &student : students)
  {
    string filename = "transcript_" + to_string(student.id) + ".txt";
    ofstream outfile(filename);

    outfile << "Name: " << student.name << " ID: " << student.id << "\n\n";
    outfile << left << setw(10) << "Code"
            << setw(35) << "Title"
            << setw(10) << "Credits"
            << setw(8) << "Score"
            << "Grade\n";

    double totalPoints = 0.0;
    double totalCredits = 0.0;
    double creditsEarned = 0.0;

    for (const auto &c : student.courses)
    {
      char grade = getGradeLetter(c.score);
      double points = (grade == 'A') ? 4.0 : (grade == 'B' ? 3.0 : (grade == 'C' ? 2.0 : (grade == 'D' ? 1.0 : 0.0)));

      totalPoints += (points * c.credits);
      totalCredits += c.credits;
      if (grade != 'F')
      {
        creditsEarned += c.credits;
      }

      outfile << left << setw(10) << c.code
              << setw(35) << c.title
              << setw(10) << c.credits
              << setw(8) << c.score
              << grade << "\n";
    }

    double gpa = (totalCredits == 0) ? 0.0 : (totalPoints / totalCredits);
    string standing = (gpa < 2.00) ? "Academic Probation" : "Good Standing";

    outfile << "\nGPA: " << fixed << setprecision(2) << gpa
            << " | Credits earned: " << creditsEarned
            << " | Standing: " << standing << "\n";
  }

  return 0;
}
#include <iostream>
#include <string>
#include <iomanip>

using namespace std; // Or use std:: explicitly

// a. Struct Definitions
struct Date
{
  int day;
  int month;
  int year;
};

struct CourseRecord
{
  string code;
  double credits;
  int score;
};

struct GradeBand
{
  int minScore;
  char letter;
  double points;
};

// Table 1 lookup array
const GradeBand GRADE_TABLE[8] = {
    {80, 'A', 4.0},
    {75, 'B', 3.5},
    {70, 'B', 3.0}, // Note: B is 70-74, B+ is 75-79 handled by threshold ordering if done top-down
    {65, 'C', 2.5},
    {60, 'C', 2.0},
    {55, 'D', 1.5},
    {50, 'D', 1.0},
    {0, 'F', 0.0}};

// Better lookup function matching exact ranges from Table 1
GradeBand lookupGrade(int score)
{
  if (score >= 80)
    return {80, 'A', 4.0};
  if (score >= 75)
    return {75, 'B', 3.5}; // B+
  if (score >= 70)
    return {70, 'B', 3.0}; // B
  if (score >= 65)
    return {65, 'C', 2.5}; // C+
  if (score >= 60)
    return {60, 'C', 2.0}; // C
  if (score >= 55)
    return {55, 'D', 1.5}; // D+
  if (score >= 50)
    return {50, 'D', 1.0}; // D
  return {0, 'F', 0.0};
}

// b. Student Class
class Student
{
private:
  long id;
  string name;
  Date admissionDate;
  CourseRecord courses[10];
  int courseCount;
  static int studentCount;

public:
  // Member-initializer list constructor
  Student(long studentId, string studentName, Date date)
      : id(studentId), name(studentName), admissionDate(date), courseCount(0)
  {
    studentCount++;
  }

  // Const getters
  long getId() const { return id; }
  string getName() const { return name; }
  int getCourseCount() const { return courseCount; }

  static int getCount()
  {
    return studentCount;
  }

  bool addCourse(const CourseRecord &course)
  {
    if (course.score < 0 || course.score > 100)
    {
      cout << "Invalid score " << course.score << " for " << course.code << "; course skipped\n";
      return false;
    }
    if (courseCount < 10)
    {
      courses[courseCount++] = course;
      return true;
    }
    return false;
  }

  double computeGPA(double &totalCreditsEarned) const
  {
    double totalPoints = 0.0;
    double totalCredits = 0.0;
    totalCreditsEarned = 0.0;

    for (int i = 0; i < courseCount; ++i)
    {
      GradeBand gb = lookupGrade(courses[i].score);
      totalPoints += (gb.points * courses[i].credits);
      totalCredits += courses[i].credits;
      if (gb.letter != 'F')
      {
        totalCreditsEarned += courses[i].credits;
      }
    }
    if (totalCredits == 0)
      return 0.0;
    return totalPoints / totalCredits;
  }

  void printTranscript() const
  {
    double creditsEarned = 0.0;
    double gpa = computeGPA(creditsEarned);

    // Formatting name output split if needed, or printing directly based on sample
    cout << "Name: " << name << "\nID: " << id
         << " | Admitted: " << (admissionDate.day < 10 ? "0" : "") << admissionDate.day
         << "/" << (admissionDate.month < 10 ? "0" : "") << admissionDate.month
         << "/" << admissionDate.year << "\n\n";

    cout << left << setw(10) << "Course"
         << setw(10) << "Credits"
         << setw(8) << "Score"
         << setw(6) << "Grade"
         << "Points\n\n";

    for (int i = 0; i < courseCount; ++i)
    {
      GradeBand gb = lookupGrade(courses[i].score);
      cout << left << setw(10) << courses[i].code
           << setw(10) << courses[i].credits
           << setw(8) << courses[i].score
           << setw(6) << gb.letter
           << fixed << setprecision(2) << gb.points << "\n";
    }

    string standing = (gpa < 2.00) ? "Academic Probation" : "Good Standing";
    cout << "\nGPA: " << fixed << setprecision(2) << gpa
         << " | Credits earned: " << creditsEarned
         << " | Standing: " << standing << "\n\n";
  }
};

int Student::studentCount = 0;

// c. Main execution loop
int main()
{
  long id;

  cout << "Enter student ID: ";
  while (cin >> id && id != 0)
  {
    string firstName, lastName;
    cout << "Enter student' s both names: ";
    cin >> firstName >> lastName;
    string fullName = firstName + " " + lastName;

    Date d;
    cout << "Enter date admitted (dd mm yyyy): ";
    cin >> d.day >> d.month >> d.year;

    Student student(id, fullName, d);

    string code;
    cout << "Enter course code (or 'END' to stop): ";
    while (cin >> code && code != "END")
    {
      double credits;
      int score;
      cout << "Enter course credits and scores: ";
      cin >> credits >> score;
      CourseRecord cr = {code, credits, score};
      student.addCourse(cr);
    }

    student.printTranscript();
    cout << "Students processed: " << Student::getCount() << "\n";
  }
  return 0;
}

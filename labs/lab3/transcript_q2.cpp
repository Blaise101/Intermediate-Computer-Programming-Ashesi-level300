#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Date
{
  int day, month, year;
};
struct CourseRecord
{
  string code;
  double credits;
  int score;
};
struct GradeBand
{
  char letter;
  double points;
};

GradeBand lookupGradeQ2(int score)
{
  if (score >= 80)
    return {'A', 4.0};
  if (score >= 75)
    return {'B', 3.5};
  if (score >= 70)
    return {'B', 3.0};
  if (score >= 65)
    return {'C', 2.5};
  if (score >= 60)
    return {'C', 2.0};
  if (score >= 55)
    return {'D', 1.5};
  if (score >= 50)
    return {'D', 1.0};
  return {'F', 0.0};
}

// a. Transcript class with dynamic array management
class Transcript
{
private:
  CourseRecord *courses;
  int capacity;
  int size;

  void resize()
  {
    capacity *= 2;
    CourseRecord *temp = new CourseRecord[capacity];
    for (int i = 0; i < size; ++i)
    {
      temp[i] = courses[i];
    }
    delete[] courses;
    courses = temp;
  }

public:
  Transcript() : capacity(2), size(0)
  {
    courses = new CourseRecord[capacity];
  }

  // Destructor
  ~Transcript()
  {
    delete[] courses;
  }

  // Disable copying
  Transcript(const Transcript &) = delete;
  Transcript &operator=(const Transcript &) = delete;

  // c. Operator += implementation
  Transcript &operator+=(const CourseRecord &c)
  {
    if (size >= capacity)
    {
      resize();
    }
    courses[size++] = c;
    return *this;
  }

  int getSize() const { return size; }
  CourseRecord getCourse(int index) const { return courses[index]; }

  double getGPA(double &creditsEarned) const
  {
    double totalPoints = 0.0;
    double totalCredits = 0.0;
    creditsEarned = 0.0;

    for (int i = 0; i < size; ++i)
    {
      GradeBand gb = lookupGradeQ2(courses[i].score);
      totalPoints += (gb.points * courses[i].credits);
      totalCredits += courses[i].credits;
      if (gb.letter != 'F')
      {
        creditsEarned += courses[i].credits;
      }
    }
    if (totalCredits == 0)
      return 0.0;
    return totalPoints / totalCredits;
  }

  // d. printWhere function using a function pointer
  void printWhere(bool (*keep)(const CourseRecord &)) const
  {
    for (int i = 0; i < size; ++i)
    {
      if (keep(courses[i]))
      {
        GradeBand gb = lookupGradeQ2(courses[i].score);
        cout << courses[i].code << "\t" << courses[i].credits << "\t" << courses[i].score << "\t" << gb.letter << "\t" << fixed << setprecision(2) << gb.points << "\n";
      }
    }
  }

  // c. Friend operator << for Transcript
  friend ostream &operator<<(ostream &os, const Transcript &t)
  {
    os << "Course\tCredits Score Grade\tPoints\n";
    for (int i = 0; i < t.size; ++i)
    {
      GradeBand gb = lookupGradeQ2(t.courses[i].score);
      os << t.courses[i].code << "\t" << t.courses[i].credits << "\t" << t.courses[i].score << "\t" << gb.letter << "\t" << fixed << setprecision(2) << gb.points << "\n";
    }
    double earned = 0;
    double gpa = t.getGPA(earned);
    os << "GPA: " << fixed << setprecision(2) << gpa << " Credits earned: " << earned << "\n";
    return os;
  }
};

// b. Base class Student
class Student
{
protected:
  long id;
  string name;
  Date admittedDate;
  Transcript transcript;

public:
  Student(long id, string name, Date date) : id(id), name(name), admittedDate(date) {}
  virtual ~Student() {}

  virtual void printHeader() const
  {
    cout << "Name: " << name << " ID: " << id << " Admitted: "
         << (admittedDate.day < 10 ? "0" : "") << admittedDate.day << "/"
         << (admittedDate.month < 10 ? "0" : "") << admittedDate.month << "/"
         << admittedDate.year << "\n";
  }

  Student &addCourse(const CourseRecord &c)
  {
    transcript += c;
    return *this;
  }

  double getGPA() const
  {
    double dummy;
    return transcript.getGPA(dummy);
  }

  // c. Operator < for comparing GPAs
  bool operator<(const Student &other) const
  {
    return this->getGPA() < other.getGPA();
  }

  Transcript &getTranscript() { return transcript; }
  string getName() const { return name; }
};

// b. Derived class UndergraduateStudent
class UndergraduateStudent : public Student
{
private:
  string major;
  int level;

public:
  UndergraduateStudent(long id, string name, Date date, string major, int level)
      : Student(id, name, date), major(major), level(level) {}

  void printHeader() const override
  {
    Student::printHeader();
    cout << "Programme: " << major << " Level: " << level << "\n";
  }

  // c. Prefix increment operator (++a)
  UndergraduateStudent &operator++()
  {
    if (level < 400)
    {
      level += 100;
    }
    return *this;
  }

  // c. Postfix increment operator (a++)
  int operator++(int)
  {
    int oldLevel = level;
    if (level < 400)
    {
      level += 100;
    }
    return oldLevel;
  }

  int getLevel() const { return level; }
};

// d. isFailing helper function
bool isFailing(const CourseRecord &c)
{
  GradeBand gb = lookupGradeQ2(c.score);
  return gb.letter == 'F';
}

int main()
{
  UndergraduateStudent ama(61242027, "Ama Serwaa Mensah", {12, 8, 2024}, "Computer Science", 200);
  ama.addCourse({"CS313", 1.0, 84})
      .addCourse({"MATH221", 1.0, 72})
      .addCourse({"CS341", 1.0, 47});

  UndergraduateStudent kwame(75112027, "Kwame Boateng", {14, 8, 2023}, "Business Administration", 300);
  kwame.addCourse({"ECON101", 1.0, 63})
      .addCourse({"BUSA221", 1.0, 58});

  ama.printHeader();
  cout << ama.getTranscript();
  cout << "\n";

  kwame.printHeader();
  cout << kwame.getTranscript();

  if (ama < kwame)
  {
    cout << "Higher GPA: " << kwame.getName() << "\n";
  }
  else
  {
    cout << "Higher GPA: " << ama.getName() << "\n";
  }

  cout << "Ama's failed courses:\n";
  ama.getTranscript().printWhere(isFailing);

  ++ama;
  cout << "After ++ama, level is " << ama.getLevel() << "\n";

  int oldLvl = ama++;
  cout << "ama++ returned " << oldLvl << "; level is now " << ama.getLevel() << "\n";

  return 0;
}
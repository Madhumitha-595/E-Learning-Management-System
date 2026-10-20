#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <string>
using namespace std;

// ================= COURSE CLASS =================
class Course
{
private:
    int courseID;
    string courseName;
    string instructor;

public:
    Course(int id, string name, string teacher)
    {
        courseID = id;
        courseName = name;
        instructor = teacher;
    }

    void displayCourse()
    {
        cout << "Course ID   : " << courseID << endl;
        cout << "Course Name : " << courseName << endl;
        cout << "Instructor  : " << instructor << endl;
        cout << "-----------------------------" << endl;
    }

    int getCourseID()
    {
        return courseID;
    }

    string getCourseName()
    {
        return courseName;
    }
};

// ================= STUDENT CLASS =================
class Student
{
private:
    int studentID;
    string name;
    string email;
    string department;

public:
    Student(int id, string n, string e, string dept)
    {
        studentID = id;
        name = n;
        email = e;
        department = dept;
    }

    void displayStudent()
    {
        cout << "Student ID  : " << studentID << endl;
        cout << "Name        : " << name << endl;
        cout << "Email       : " << email << endl;
        cout << "Department  : " << department << endl;
        cout << "-----------------------------" << endl;
    }

    int getStudentID()
    {
        return studentID;
    }

    string getName()
    {
        return name;
    }
};

// ================= ENROLLMENT CLASS =================
class Enrollment
{
private:
    int studentID;
    int courseID;
    string studentName;
    string courseName;

public:
    Enrollment(int sid, int cid, string sname, string cname)
    {
        studentID = sid;
        courseID = cid;
        studentName = sname;
        courseName = cname;
    }

    void displayEnrollment()
    {
        cout << "Student ID   : " << studentID << endl;
        cout << "Student Name : " << studentName << endl;
        cout << "Course ID    : " << courseID << endl;
        cout << "Course Name  : " << courseName << endl;
        cout << "-----------------------------" << endl;
    }
};

// ================= ELMS CLASS =================
class ELMS
{
private:

    // DSA 1: Vector
    vector<Course> courses;

    // DSA 2: Vector
    vector<Student> students;

    // DSA 3: Vector
    vector<Enrollment> enrollments;

    // DSA 4: Queue
    queue<int> enrollmentQueue;

    // DSA 5: Stack
    stack<int> recentStudents;

public:

    // Add default courses
    void addCourses()
    {
        courses.push_back(
            Course(101, "C++ Programming", "Mr. Kumar"));

        courses.push_back(
            Course(102, "Java Programming", "Ms. Priya"));

        courses.push_back(
            Course(103, "Data Structures", "Mr. Arun"));

        courses.push_back(
            Course(104, "Web Development", "Ms. Divya"));
    }

    // ================= VIEW COURSES =================
    void viewCourses()
    {
        cout << "\n========================================\n";
        cout << "             AVAILABLE COURSES\n";
        cout << "========================================\n";

        if (courses.empty())
        {
            cout << "No courses available.\n";
            return;
        }

        for (int i = 0; i < courses.size(); i++)
        {
            courses[i].displayCourse();
        }
    }

    // ================= REGISTER STUDENT =================
    void registerStudent()
    {
        int id;
        string name, email, department;

        cout << "\n========================================\n";
        cout << "           STUDENT REGISTRATION\n";
        cout << "========================================\n";

        cout << "Enter Student ID: ";
        cin >> id;

        // Searching student ID
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getStudentID() == id)
            {
                cout << "Student ID already exists!\n";
                return;
            }
        }

        cin.ignore();

        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Email: ";
        getline(cin, email);

        cout << "Enter Department: ";
        getline(cin, department);

        students.push_back(
            Student(id, name, email, department));

        cout << "\nStudent registered successfully!\n";
    }

    // ================= VIEW STUDENTS =================
    void viewStudents()
    {
        cout << "\n========================================\n";
        cout << "           REGISTERED STUDENTS\n";
        cout << "========================================\n";

        if (students.empty())
        {
            cout << "No students registered.\n";
            return;
        }

        for (int i = 0; i < students.size(); i++)
        {
            students[i].displayStudent();
        }
    }

    // ================= ENROLL STUDENT =================
    void enrollStudent()
    {
        int studentID, courseID;

        cout << "\n========================================\n";
        cout << "             COURSE ENROLLMENT\n";
        cout << "========================================\n";

        if (students.empty())
        {
            cout << "Please register a student first.\n";
            return;
        }

        cout << "Enter Student ID: ";
        cin >> studentID;

        int studentIndex = -1;

        // Search student
        for (int i = 0; i < students.size(); i++)
        {
            if (students[i].getStudentID() == studentID)
            {
                studentIndex = i;
                break;
            }
        }

        if (studentIndex == -1)
        {
            cout << "Student not found!\n";
            return;
        }

        viewCourses();

        cout << "Enter Course ID: ";
        cin >> courseID;

        int courseIndex = -1;

        // Search course
        for (int i = 0; i < courses.size(); i++)
        {
            if (courses[i].getCourseID() == courseID)
            {
                courseIndex = i;
                break;
            }
        }

        if (courseIndex == -1)
        {
            cout << "Course not found!\n";
            return;
        }

        enrollments.push_back(
            Enrollment(
                studentID,
                courseID,
                students[studentIndex].getName(),
                courses[courseIndex].getCourseName()
            )
        );

        // Queue operation
        enrollmentQueue.push(studentID);

        // Stack operation
        recentStudents.push(studentID);

        cout << "\nEnrollment successful!\n";
    }

    // ================= VIEW ENROLLMENTS =================
    void viewEnrollments()
    {
        cout << "\n========================================\n";
        cout << "              ENROLLMENTS\n";
        cout << "========================================\n";

        if (enrollments.empty())
        {
            cout << "No enrollments available.\n";
            return;
        }

        for (int i = 0; i < enrollments.size(); i++)
        {
            enrollments[i].displayEnrollment();
        }
    }

    // ================= QUEUE =================
    void showEnrollmentQueue()
    {
        cout << "\n========================================\n";
        cout << "          ENROLLMENT QUEUE\n";
        cout << "========================================\n";

        if (enrollmentQueue.empty())
        {
            cout << "Queue is empty.\n";
            return;
        }

        queue<int> temp = enrollmentQueue;

        while (!temp.empty())
        {
            cout << "Student ID: "
                 << temp.front() << endl;

            temp.pop();
        }
    }

    // ================= STACK =================
    void showRecentStudents()
    {
        cout << "\n========================================\n";
        cout << "        RECENTLY ENROLLED STUDENTS\n";
        cout << "========================================\n";

        if (recentStudents.empty())
        {
            cout << "Stack is empty.\n";
            return;
        }

        stack<int> temp = recentStudents;

        while (!temp.empty())
        {
            cout << "Student ID: "
                 << temp.top() << endl;

            temp.pop();
        }
    }
};

// ================= MAIN FUNCTION =================
int main()
{
    ELMS system;

    system.addCourses();

    int choice;

    do
    {
        cout << "\n\n========================================\n";
        cout << "       EDULEARN - ELMS SYSTEM\n";
        cout << "========================================\n";

        cout << "1. View Courses\n";
        cout << "2. Register Student\n";
        cout << "3. View Students\n";
        cout << "4. Enroll Student\n";
        cout << "5. View Enrollments\n";
        cout << "6. View Enrollment Queue\n";
        cout << "7. View Recent Enrollments\n";
        cout << "8. Exit\n";

        cout << "========================================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            system.viewCourses();
            break;

        case 2:
            system.registerStudent();
            break;

        case 3:
            system.viewStudents();
            break;

        case 4:
            system.enrollStudent();
            break;

        case 5:
            system.viewEnrollments();
            break;

        case 6:
            system.showEnrollmentQueue();
            break;

        case 7:
            system.showRecentStudents();
            break;

        case 8:
            cout << "\nThank you for using EduLearn ELMS!\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 8);

    return 0;
}
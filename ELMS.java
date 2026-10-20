package backend.java;

import java.util.ArrayList;
import java.util.Scanner;

public class ELMS {

    static ArrayList<Student> students = new ArrayList<>();
    static ArrayList<Course> courses = new ArrayList<>();
    static ArrayList<Enrollment> enrollments = new ArrayList<>();

    // Add sample courses
    public static void addCourses() {

        courses.add(new Course(
                101,
                "Java Programming",
                "Programming",
                6
        ));

        courses.add(new Course(
                102,
                "C++ Programming",
                "Programming",
                5
        ));

        courses.add(new Course(
                103,
                "Data Structures & Algorithms",
                "DSA",
                8
        ));

        courses.add(new Course(
                104,
                "Web Development",
                "Web Development",
                9
        ));
    }

    // Display all courses
    public static void displayCourses() {

        System.out.println("\n===== AVAILABLE COURSES =====");

        for (Course course : courses) {
            course.displayCourse();
        }
    }

    // Register a student
    public static void registerStudent(Scanner scanner) {

        System.out.println("\n===== STUDENT REGISTRATION =====");

        System.out.print("Enter Student ID: ");
        int id = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter Name: ");
        String name = scanner.nextLine();

        System.out.print("Enter Email: ");
        String email = scanner.nextLine();

        System.out.print("Enter College: ");
        String college = scanner.nextLine();

        System.out.print("Enter Department: ");
        String department = scanner.nextLine();

        System.out.print("Enter Year: ");
        int year = scanner.nextInt();

        Student student = new Student(
                id,
                name,
                email,
                college,
                department,
                year
        );

        students.add(student);

        System.out.println("\nStudent registered successfully!");
    }

    // Display students
    public static void displayStudents() {

        System.out.println("\n===== REGISTERED STUDENTS =====");

        if (students.isEmpty()) {
            System.out.println("No students registered.");
            return;
        }

        for (Student student : students) {
            student.displayStudent();
        }
    }

    // Enroll student
    public static void enrollStudent(Scanner scanner) {

        if (students.isEmpty()) {
            System.out.println("\nPlease register a student first.");
            return;
        }

        displayStudents();

        System.out.print("\nEnter Student ID: ");
        int studentId = scanner.nextInt();

        displayCourses();

        System.out.print("\nEnter Course ID: ");
        int courseId = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter Enrollment Date: ");
        String date = scanner.nextLine();

        Enrollment enrollment = new Enrollment(
                enrollments.size() + 1,
                studentId,
                courseId,
                date
        );

        enrollments.add(enrollment);

        System.out.println("\nStudent enrolled successfully!");
    }

    // Display enrollments
    public static void displayEnrollments() {

        System.out.println("\n===== ENROLLMENTS =====");

        if (enrollments.isEmpty()) {
            System.out.println("No enrollments available.");
            return;
        }

        for (Enrollment enrollment : enrollments) {
            enrollment.displayEnrollment();
        }
    }

    // Main method
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        addCourses();

        int choice;

        do {

            System.out.println("\n================================");
            System.out.println("          ELMS SYSTEM");
            System.out.println("================================");
            System.out.println("1. View Courses");
            System.out.println("2. Register Student");
            System.out.println("3. View Students");
            System.out.println("4. Enroll Student");
            System.out.println("5. View Enrollments");
            System.out.println("6. Exit");
            System.out.println("================================");

            System.out.print("Enter your choice: ");

            choice = scanner.nextInt();

            switch (choice) {

                case 1:
                    displayCourses();
                    break;

                case 2:
                    registerStudent(scanner);
                    break;

                case 3:
                    displayStudents();
                    break;

                case 4:
                    enrollStudent(scanner);
                    break;

                case 5:
                    displayEnrollments();
                    break;

                case 6:
                    System.out.println("\nThank you for using ELMS!");
                    break;

                default:
                    System.out.println("\nInvalid choice.");
            }

        } while (choice != 6);

        scanner.close();
    }
}

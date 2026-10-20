package backend.java;
public class Student extends User {

    private String college;
    private String department;
    private int year;

    public Student(
            int userId,
            String name,
            String email,
            String college,
            String department,
            int year) {

        super(userId, name, email);

        this.college = college;
        this.department = department;
        this.year = year;
    }

    public String getCollege() {
        return college;
    }

    public String getDepartment() {
        return department;
    }

    public int getYear() {
        return year;
    }

    public void displayStudent() {

        System.out.println("\n===== STUDENT DETAILS =====");

        displayUser();

        System.out.println("College    : " + college);
        System.out.println("Department : " + department);
        System.out.println("Year       : " + year);
    }
}
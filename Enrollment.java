package backend.java;

public class Enrollment {

    private int enrollmentId;
    private int studentId;
    private int courseId;
    private String date;
    private String status;

    public Enrollment(
            int enrollmentId,
            int studentId,
            int courseId,
            String date) {

        this.enrollmentId = enrollmentId;
        this.studentId = studentId;
        this.courseId = courseId;
        this.date = date;
        this.status = "Active";
    }

    public void updateStatus(String status) {

        if (status.equalsIgnoreCase("Active")
                || status.equalsIgnoreCase("Completed")
                || status.equalsIgnoreCase("Cancelled")) {

            this.status = status;

        } else {

            System.out.println("Invalid status.");
        }
    }

    public void displayEnrollment() {

        System.out.println("\n===== ENROLLMENT DETAILS =====");

        System.out.println("Enrollment ID : " + enrollmentId);
        System.out.println("Student ID    : " + studentId);
        System.out.println("Course ID     : " + courseId);
        System.out.println("Date          : " + date);
        System.out.println("Status        : " + status);
    }
}

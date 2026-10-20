package backend.java;
public class Course {

    private int courseId;
    private String courseName;
    private String category;
    private int duration;
    private int progress;

    public Course(
            int courseId,
            String courseName,
            String category,
            int duration) {

        this.courseId = courseId;
        this.courseName = courseName;
        this.category = category;
        this.duration = duration;
        this.progress = 0;
    }

    public int getCourseId() {
        return courseId;
    }

    public String getCourseName() {
        return courseName;
    }

    public String getCategory() {
        return category;
    }

    public int getDuration() {
        return duration;
    }

    public int getProgress() {
        return progress;
    }

    public void updateProgress(int progress) {

        if (progress >= 0 && progress <= 100) {
            this.progress = progress;
        } else {
            System.out.println("Progress must be between 0 and 100.");
        }
    }

    public void displayCourse() {

        System.out.println("\n===== COURSE DETAILS =====");

        System.out.println("Course ID   : " + courseId);
        System.out.println("Course Name : " + courseName);
        System.out.println("Category    : " + category);
        System.out.println("Duration    : " + duration + " hours");
        System.out.println("Progress    : " + progress + "%");
    }
}
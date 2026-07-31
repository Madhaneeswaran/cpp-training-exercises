// CollegeCourse Class
#include <iostream>
#include <string>

class CollegeCourse {
    // your code here
    public:
        std::string courseID;
        char grade;
        int credits;
        
        int gradePoints;
        float honorPoints;
        
        void set_CourseId(std::string CID) {
            courseID = CID;
        }
        
        void set_Grade(char g) {
            grade = g;
        }
        
        void set_Credit(int cr) {
            credits = cr;
        }
        
        int calculateGradePoints(char g) {
            switch (g) {
                case 'a': 
                case 'A': {
                    return 10;
                }
                case 'b':
                case 'B': {
                    return 9;
                }
                case 'c':
                case 'C': {
                    return 8;
                } 
                case 'd':
                case 'D': {
                    return 7;
                }
                case 'e':
                case 'E': {
                    return 6;
                } 
                case 'f':
                case 'F': {
                    return 5;
                }
                default : {
                    std::cout << "Warning: Invalid grade";
                    return -1
                }
            }
        }
        
        float calculateHonorPoints(int gp, int cr) {
            return gp * cr;
        }
        
        void display() {
            std::cout << gradePoints << "\t" << honorPoints << std::endl;
        }
};

int main () {
    CollegeCourse course;
    
    std::string course_name;
    char grade;
    int credits;
    
    std::cout << "Enter course: ";
    std::getline(std::cin, course_name);
    
    std::cout << "Enter grade: ";
    std::cin >> grade;
    
    std::cout << "Enter credits: ";
    std::cin >> credits;
    
    course.set_CourseId(course_name);
    
    course.set_Grade(grade);
    course.gradePoints = course.calculateGradePoints(grade);
    
    course.set_Credit(credits);
    course.honorPoints = course.calculateHonorPoints(course.gradePoints, credits);
    
    course.display();
    
    return 0;
}
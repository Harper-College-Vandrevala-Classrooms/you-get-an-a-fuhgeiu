#include <vector>
#include <string>
#include <iostream>

class Student {                             // class for student data, name, id
    std::string name;
    size_t id;

public:
    std::vector<size_t> grade_points;              // grades must be a positive int
    
    Student (const std::string& Name,size_t id) {this->name = Name; this->id = id;}
    const std::string access_name() const { return name; }
    size_t access_id () const {return id;}
};

class Assignment {                          // class for assignment data, name, total points
    std::string name;
    size_t total_points;

public:
    Assignment (const std::string& Name, size_t points) {this->name = Name; this->total_points = points;}
    const std::string access_name() const { return name; }
    size_t acess_total_points() const { return total_points; } // Get total points for validation
};

// Class for the classroom gradebook
// use vector to store student objects and assignment objects
// use emplace_back() to pass in constructor arguments, and constructs objects
class Classroom {
    std::vector<Student> students;
    std::vector<Assignment> assignments;

public:
    void add_student(const std::string& name, size_t ID) {students.emplace_back(name, ID);}

    void add_assignment(const std::string& name, size_t Points) {assignments.emplace_back(name, Points);}

    void enter_grade(const std::string& student_name, const std::string& assignment_name, size_t Points) {
        for (auto& assignment : assignments) {
            if (assignment.access_name() == assignment_name) {
                for (auto& student : students) {
                    if (student.access_name() == student_name) {
                        student.grade_points.push_back(Points);
                        return;
                    }
                }
            }
        }
        std::cout << "Error: Student or assignment not found." << std::endl;
    }

    void report() {

        std::cout << "name , id number , grade name , points assigned\n";

        for (const auto& student : students) {
            std::cout << student.access_name() << ", " << student.access_id() << ", ";
            for (size_t i = 0; i < assignments.size(); ++i) {
                if (i < student.grade_points.size()) {
                    std::cout << student.grade_points[i] << ", ";
                }
            }
            std::cout << "\n";
        }
    }
};


int main() {
    Classroom gradebook;

    gradebook.add_student("Bob Bobberson", 111045);
    gradebook.add_student("Sam Sammerson", 111029);
    gradebook.add_student("Jess Jesserson", 493062);

    gradebook.add_assignment("Quiz 1", 100);
    gradebook.add_assignment("Lab 1", 50);

    gradebook.enter_grade("Sam Sammerson", "Quiz 1", 95);
    gradebook.enter_grade("Bob Bobberson", "Quiz 1", 85);
    gradebook.enter_grade("Jess Jesserson", "Lab 1", 49);
    gradebook.enter_grade("Jess Jesserson", "Quiz 1", 93);
    gradebook.enter_grade("Bob Bobberson", "Lab 1", 0);

    gradebook.report(); // Generate the report

    return 0;
}

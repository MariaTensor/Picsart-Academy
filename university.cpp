#include <iostream>
#include <memory>
#include <vector>
#include <string>



class Course;

class Student: public std::enable_shared_from_this<Student>
{
private:
    int _id;
    std::string _name;
    std::vector<std::shared_ptr<Course>> _courses;

    friend class Course;

public:
    Student() = default;
    Student(int id, const std::string& name) : _id(id), _name(name) {};
    void set_name(const std::string& name)
    {
        _name = name;
    }
    void set_id(int id)
    {
        _id = id;
    }
    std::string get_name() const
    {
        return _name;
    }
    int get_id() const
    {
        return _id;
    }

    void display_details()
    {
        std::cout<< "Student's name:"<<_name<<std::endl;
        std::cout<< "Student's id:"<<_id<<std::endl;
    }

    void enroll_course(std::shared_ptr<Course> course);

    void display_enrolled_courses();

};



class Course:public std::enable_shared_from_this<Course>
{
private:
    std::string _course_code;
    std::string _course_name;
    std::vector<std::shared_ptr<Student>> _students;

    friend class Student;

public:
    Course() = default;
    Course(const std::string& course_code, const std::string& course_name): _course_code(course_code), _course_name(course_name){}
    void set_course_code(const std::string& course_code)
    {
        _course_code = course_code;
    }
    void set_course_name(const std::string& course_name)
    {
        _course_name = course_name;
    }
    std::string get_course_code() const
    {
        return _course_code;
    }
    std::string get_course_name() const
    {
        return _course_name;
    }

    void display_details()
    {
        std::cout<< "Course's code:"<<_course_code<<std::endl;
        std::cout<< "Course's name:"<<_course_name<<std::endl;
    }

    void enroll_student(std::shared_ptr<Student> student);

    void display_enrolled_students();

};


void Student::enroll_course(std::shared_ptr<Course> course)
{
    _courses.push_back(course);
    course->_students.push_back(shared_from_this());  // Correct usage
}

void Course::enroll_student(std::shared_ptr<Student> student)
{
    _students.push_back(student);
    student->_courses.push_back(shared_from_this());  // Correct usage
}

void Student::display_enrolled_courses()
{   
        for(const auto& course: _courses)
        {
            course->display_details();
        }
}

void Course::display_enrolled_students()
{
    for(const auto& student : _students)
    {
            student->display_details();
    }
}


int main()
{
    auto student1 = std::make_shared<Student>(1, "John Doe");
    auto student2 = std::make_shared<Student>(2, "Jane Smith");

    auto course1 = std::make_shared<Course>("CS101", "Introduction to Computer Science");
    auto course2 = std::make_shared<Course>("MATH101", "Mathematics for Computer Science");

    student1->enroll_course(course1);
    student2->enroll_course(course2);

    course1->enroll_student(student1);
    course2->enroll_student(student2);

    std::cout << "Student 1 details:\n";
    student1->display_details();
    student1->display_enrolled_courses();

    std::cout << "\nStudent 2 details:\n";
    student2->display_details();
    student2->display_enrolled_courses();

    return 0;
}
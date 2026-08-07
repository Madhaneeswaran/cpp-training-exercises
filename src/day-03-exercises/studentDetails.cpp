#include <iostream>
#include <string>

class Person {    
    public:
        std::string name;
        int age;

        Person(const std::string& name, int age) {
            this->name = name;
            this->age = age;
        }

        void Show_Name() {
            std::cout << "The Name is " << name << '\n';
        }

        void Show_Details() {
            std::cout << "The Name is " << name << ". He/She is " << age << " years old. \n";
        }

        ~Person() {
            std::cout << "Person Destructor \n";
        }
};

class Student : public Person {
    private:
        std::string qualification;

    public:
        Student(const std::string& qua, const std::string& name, int age) : Person(name, age), qualification(qua){}

        void Show_Details() {
            std::cout << "The Name is " << name << ". He/She is " << age << " years old. His/Her Qualification is " << qualification << '\n';
        }

        ~Student () {
            std::cout << "Student Destructor \n";
        }
};

int main () {
    Student student1("1st Grade", "Disham", 6);

    student1.Show_Details();

    return 0;
}
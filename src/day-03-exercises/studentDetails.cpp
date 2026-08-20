#include <iostream>
#include <string>
#include <memory>

class Person {    
    protected:
        std::string name;
        int age;
    
    public:
        Person(const std::string& name, int age): name(name), age(age) {}

        void Show_Name() const {
            std::cout << "The Name is " << name << '\n';
        }

        virtual void Show_Details() {
            std::cout << "The Name is " << name << ". He/She is " << age << " years old. \n";
        }

        virtual ~Person() {
            std::cout << "Person Destructor \n";
        }
};

class Student : public Person {
    private:
        std::string qualification;

    public:
        Student(const std::string& qua, const std::string& name, int age) : Person(name, age), qualification(qua){}

        void Show_Details() override {
            std::cout << "The Name is " << name << ". He/She is " << age << " years old. His/Her Qualification is " << qualification << '\n';
        }

        ~Student () {
            std::cout << "Student Destructor \n";
        }
};

int main () {
    auto student1 = std::make_unique<Student>("1st Grade", "Disham", 6);

    student1->Show_Name();

    student1->Show_Details();

    return 0;
}
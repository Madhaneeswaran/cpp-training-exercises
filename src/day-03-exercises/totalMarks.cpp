#include <iostream>
#include <string>

class Subject {
    private:
        std::string Subject_Name;
        int Marks;

    public:
        Subject() {}

        Subject(std::string sub, int mark): Subject_Name(sub), Marks(mark) {}

        Subject operator+(const Subject& x) const {
            Subject newSubject;
            newSubject.Marks = Marks + x.Marks;

            return newSubject;
        }

        void print() {
            std::cout << "Subject name: " << Subject_Name << " Marks: " << Marks << '\n';
        }
};

int main() {
    Subject english("english", 90);
    Subject maths("maths", 80);
    Subject total("", 0);

    total = english + maths;
    total.print();

    return 0;
}
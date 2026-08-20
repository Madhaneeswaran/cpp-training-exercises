#include <iostream>
#include <string>

class Subject {
    private:
        std::string Subject_Name;
        int Marks;

    public:
        Subject(): Subject_Name(""), Marks(0) {}

        Subject(const std::string& sub, int mark): Subject_Name(sub), Marks(mark) {}

        Subject operator+(const Subject& x) const {
            return Subject("Total", Marks + x.Marks);
        }

        void print() const {
            std::cout << "Subject name: " << Subject_Name << ", Marks: " << Marks << '\n';
        }
};

int main() {
    Subject english("english", 90);
    Subject maths("maths", 80);
    Subject total("Total", 0);

    total = english + maths;
    total.print();

    return 0;
}
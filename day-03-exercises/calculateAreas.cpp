#include <iostream>
#include <cmath> 

class Shapes {
    public: 
        virtual double Calculate_Area() = 0;
};

class Square : public Shapes {
    private:
        double side;
    public:
        Square(double s) : side(s) {}

        double Calculate_Area() override {
            return (side * side);
        }
};

class Circle : public Shapes {
    private:
        double radius;
    public:
        Circle(double r) : radius(r) {}

        double Calculate_Area() override {
            double pi = M_PI; 
            return (pi * radius * radius);
        }
};

int main() {
    Shapes *shape;

    Circle c(4);

    Square sq(4);

    shape = &c;
    std::cout << "Area of the circle :- " << shape->Calculate_Area() << "\n";

    shape = &sq;
    std::cout << "Area of the square :- " << shape->Calculate_Area() << "\n";

    return 0;
}
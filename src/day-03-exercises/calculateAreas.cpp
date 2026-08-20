#include <iostream>
#include <numbers>

class Shapes {
    public: 
        virtual double Calculate_Area() const = 0;

        virtual ~Shapes() {
            std::cout << "Shapes Destructor \n";
        }
};

class Square : public Shapes {
    private:
        double side;
    
    public:
        Square(double s) : side(s) {
            if (side < 0) {
                throw std::invalid_argument("Square side length cannot be negative: " + std::to_string(side));
            }
        }

        double Calculate_Area() const override {
            return (side * side);
        }
};

class Circle : public Shapes {
    private:
        double radius;
    
    public:
        Circle(double r) : radius(r) {
            if (radius < 0) {
                throw std::invalid_argument("Circle radius cannot be negative: " + std::to_string(radius));
            }
        }

        double Calculate_Area() const override {
            double pi = std::numbers::pi; 
            return (pi * radius * radius);
        }
};

int main() {
    Shapes* shape;

    Circle c(4);

    Square sq(4);

    shape = &c;
    std::cout << "Area of the circle :- " << shape->Calculate_Area() << "\n";

    shape = &sq;
    std::cout << "Area of the square :- " << shape->Calculate_Area() << "\n";

    return 0;
}
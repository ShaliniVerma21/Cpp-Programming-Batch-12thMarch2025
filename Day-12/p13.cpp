//Shape Area, circumstance, surface Calculator

#include <iostream>
#include <cmath> // For mathematical functions
#include <iomanip> // For setting precision
#include <string>

using namespace std;

// Enumeration for shape types
enum class ShapeType {
    CIRCLE,
    RECTANGLE,
    SPHERE
};

// Base class for Shape
class Shape {
public:
    // Virtual function to calculate area
    virtual double area() const = 0;

    // Virtual function to calculate circumference or perimeter
    virtual double perimeter() const = 0;

    // Virtual function to calculate surface area (for 3D shapes)
    virtual double surfaceArea() const = 0;

    // Virtual destructor
    virtual ~Shape() {}
};

// Derived class for Circle
class Circle : public Shape {
private:
    double radius; // Radius of the circle

public:
    // Constructor for Circle
    Circle(double r) : radius(r) {}

    // Function to calculate area of the circle
    double area() const override {
        return M_PI * radius * radius; // Area = πr²
    }

    // Function to calculate circumference of the circle
    double perimeter() const override {
        return 2 * M_PI * radius; // Circumference = 2πr
    }

    // Function to calculate surface area (not applicable for Circle)
    double surfaceArea() const override {
        return 0; // Not applicable
    }
};

// Derived class for Rectangle
class Rectangle : public Shape {
private:
    double width; // Width of the rectangle
    double height; // Height of the rectangle

public:
    // Constructor for Rectangle
    Rectangle(double w, double h) : width(w), height(h) {}

    // Function to calculate area of the rectangle
    double area() const override {
        return width * height; // Area = width * height
    }

    // Function to calculate perimeter of the rectangle
    double perimeter() const override {
        return 2 * (width + height); // Perimeter = 2(width + height)
    }

    // Function to calculate surface area (not applicable for Rectangle)
    double surfaceArea() const override {
        return 0; // Not applicable
    }
};

// Derived class for Sphere
class Sphere : public Shape {
private:
    double radius; // Radius of the sphere

public:
    // Constructor for Sphere
    Sphere(double r) : radius(r) {}

    // Function to calculate surface area of the sphere
    double surfaceArea() const override {
        return 4 * M_PI * radius * radius; // Surface Area = 4πr²
    }

    // Function to calculate area (not applicable for Sphere)
    double area() const override {
        return 0; // Not applicable
    }

    // Function to calculate circumference (not applicable for Sphere)
    double perimeter() const override {
        return 0; // Not applicable
    }
};

int main() {
    // Create instances of shapes
    Circle circle(5.0); // Circle with radius 5.0
    Rectangle rectangle(4.0, 6.0); // Rectangle with width 4.0 and height 6.0
    Sphere sphere(3.0); // Sphere with radius 3.0

    // Display area and perimeter for Circle
    cout << "Circle:\n";
    cout << "Area: " << fixed << setprecision(2) << circle.area() << endl;
    cout << "Circumference: " << fixed << setprecision(2) << circle.perimeter() << endl;
    cout << endl;

    // Display area and perimeter for Rectangle
    cout << "Rectangle:\n";
    cout << "Area: " << fixed << setprecision(2) << rectangle.area() << endl;
    cout << "Perimeter: " << fixed << setprecision(2) << rectangle.perimeter() << endl;
    cout << endl;

    // Display surface area for Sphere
    cout << "Sphere:\n";
    cout << "Surface Area: " << fixed << setprecision(2) << sphere.surfaceArea() << endl;

    return 0;
}

#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;

class Complex {
private:
    double real, imag;

public:
    // Default constructor
    Complex() : real(0), imag(0) {}

    // Real number constructor
    Complex(double r) : real(r), imag(0) {}

    // Real and imaginary constructor
    Complex(double r, double i) : real(r), imag(i) {}

    // Addition
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Subtraction
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Multiplication
    Complex operator*(const Complex& other) const {
        return Complex(
            real * other.real - imag * other.imag,
            real * other.imag + imag * other.real
        );
    }

    // Division
    Complex operator/(const Complex& other) const {
        double denominator =
            other.real * other.real + other.imag * other.imag;

        if (denominator == 0) {
            throw runtime_error("Division by zero is not allowed");
        }

        return Complex(
            (real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator
        );
    }

    // Equality
    bool operator==(const Complex& other) const {
        const double EPSILON = 1e-9;

        return abs(real - other.real) < EPSILON &&
               abs(imag - other.imag) < EPSILON;
    }

    // Magnitude
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }

    // Output stream operator
    friend ostream& operator<<(ostream& out, const Complex& c) {
        out << c.real;

        if (c.imag >= 0)
            out << " + " << c.imag << "i";
        else
            out << " - " << -c.imag << "i";

        return out;
    }
};

int main() {
    try {
        // Resistor impedance: ZR = R
        Complex ZR(10, 0);

        // Inductor impedance: ZL = j20
        Complex ZL(0, 20);

        // Capacitor impedance: ZC = -j10
        Complex ZC(0, -10);

        // Series impedance
        Complex series = ZR + ZL + ZC;

        cout << "Resistor Impedance: " << ZR << endl;
        cout << "Inductor Impedance: " << ZL << endl;
        cout << "Capacitor Impedance: " << ZC << endl;

        cout << "\nSeries Impedance: " << series << endl;
        cout << "Series Magnitude: " << series.magnitude() << endl;

        // Parallel impedance: (Z1 * Z2) / (Z1 + Z2)
        Complex parallel = (ZR * ZL) / (ZR + ZL);

        cout << "\nParallel Impedance: " << parallel << endl;
        cout << "Parallel Magnitude: "
             << parallel.magnitude() << endl;

        // Other operator demonstrations
        Complex a(5, 3);
        Complex b(2, 1);

        cout << "\nAddition: " << a + b << endl;
        cout << "Subtraction: " << a - b << endl;
        cout << "Multiplication: " << a * b << endl;
        cout << "Division: " << a / b << endl;

        cout << boolalpha;
        cout << "Are a and b equal? " << (a == b) << endl;

        // Division by zero test
        Complex zero(0, 0);

        cout << "\nDivision by Zero Test: ";
        cout << a / zero << endl;
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }

    return 0;
}

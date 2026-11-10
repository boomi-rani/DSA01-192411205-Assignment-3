
#include <iomanip>
#include <iostream>
using namespace std;

class Money {
private:
    long long paise;

public:
    Money(long long rupees = 0, int p = 0)
        : paise(rupees * 100 + p) {
    }

    // Overload + operator
    Money operator+(const Money& other) const {
        return Money(0, static_cast<int>(paise + other.paise));
    }

    // Overload - operator
    Money operator-(const Money& other) const {
        return Money(0, static_cast<int>(paise - other.paise));
    }

    // Overload += operator
    Money& operator+=(const Money& other) {
        paise += other.paise;
        return *this;
    }

    // Overload == operator
    bool operator==(const Money& other) const {
        return paise == other.paise;
    }

    // Overload < operator
    bool operator<(const Money& other) const {
        return paise < other.paise;
    }

    // Overload << operator
    friend ostream& operator<<(ostream& out, const Money& m) {
        long long rupees = m.paise / 100;
        long long cents = m.paise % 100;

        if (cents < 0) {
            cents = -cents;
        }

        out << "Rs " << rupees << "."
            << setw(2) << setfill('0') << cents
            << setfill(' ');

        return out;
    }

    // Overload >> operator
    friend istream& operator>>(istream& in, Money& m) {
        long long rupees;
        int p;

        in >> rupees >> p;

        if (in) {
            m.paise = rupees * 100 + p;
        }

        return in;
    }
};

int main() {
    Money a(120, 75);
    Money b(79, 25);

    Money c = a + b;

    cout << "Total Amount: " << c << endl;
    cout << boolalpha << "Amounts are equal: "
         << (c == Money(200)) << endl;

    // Addition with paise carry
    Money x(0, 75);
    Money y(0, 50);

    cout << "Paise Carry: " << x + y << endl;

    // Subtraction producing a negative amount
    Money z(10, 0);
    Money w(15, 50);

    cout << "Negative Amount: " << z - w << endl;

    // Using += operator
    a += b;
    cout << "Using += : " << a << endl;

    // Using < operator
    cout << "Is a less than b? "
         << (a < b) << endl;

    return 0;
}

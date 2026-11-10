
#include <iostream>
#include <cstring>
using namespace std;

class Text {
private:
    char* data;

public:
    // Constructor
    Text(const char* str = "") {
        data = new char[strlen(str) + 1];
        strcpy(data, str);
    }

    // Copy constructor
    Text(const Text& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
        cout << "Copy constructor called" << endl;
    }

    // Copy assignment operator
    Text& operator=(const Text& other) {
        if (this != &other) {
            char* newData = new char[strlen(other.data) + 1];
            strcpy(newData, other.data);

            delete[] data;
            data = newData;
        }
        return *this;
    }

    // Destructor
    ~Text() {
        delete[] data;
    }

    // Concatenation operator
    Text operator+(const Text& other) const {
        int length = strlen(data) + strlen(other.data);
        char* temp = new char[length + 1];

        strcpy(temp, data);
        strcat(temp, other.data);

        Text result(temp);
        delete[] temp;

        return result;
    }

    // Equality operator
    bool operator==(const Text& other) const {
        return strcmp(data, other.data) == 0;
    }

    // Not equal operator
    bool operator!=(const Text& other) const {
        return !(*this == other);
    }

    // Output stream operator
    friend ostream& operator<<(ostream& out, const Text& t) {
        out << t.data;
        return out;
    }
};

int main() {
    Text a("Hello ");
    Text b("World");
    Text c("!");

    cout << "Text A: " << a << endl;
    cout << "Text B: " << b << endl;

    // Concatenation
    Text result = a + b + c;
    cout << "\nConcatenated Text: " << result << endl;

    // Comparison
    cout << boolalpha;
    cout << "\nA == B: " << (a == b) << endl;
    cout << "A != B: " << (a != b) << endl;

    // Copy constructor
    Text copy = a;
    cout << "\nCopied Text: " << copy << endl;

    // Copy assignment
    Text assigned;
    assigned = b;
    cout << "Assigned Text: " << assigned << endl;

    // Self-assignment
    assigned = assigned;
    cout << "After Self Assignment: " << assigned << endl;

    // Empty text
    Text empty("");
    cout << "Empty Text: [" << empty << "]" << endl;

    // Long message
    Text longText("This is a dynamically allocated long message.");
    cout << "Long Text: " << longText << endl;

    return 0;
}

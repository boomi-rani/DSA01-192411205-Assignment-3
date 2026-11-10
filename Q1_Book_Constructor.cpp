
#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class Book {
private:
    string title;
    string author;
    int copies;

    int validateCopies(int count) {
        if (count < 0) {
            throw invalid_argument("Number of copies cannot be negative.");
        }
        return count;
    }

public:
    // Default constructor
    Book() : Book("Unknown", "Unknown", 0) {}

    // Explicit constructor for a donated book with only a title
    explicit Book(string t) : Book(t, "Unknown", 0) {}

    // Parameterized constructor
    Book(string t, string a, int c)
        : title(t), author(a), copies(validateCopies(c)) {}

    // Display book details
    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Copies: " << copies << endl;
        cout << "-------------------" << endl;
    }
};

int main() {
    try {
        // Object created using default constructor
        Book book1;

        // Object created using title-only constructor
        Book book2("The Alchemist");

        // Object created using parameterized constructor
        Book book3("Wings of Fire", "A.P.J. Abdul Kalam", 5);

        cout << "Book 1 - Empty Record" << endl;
        book1.display();

        cout << "Book 2 - Donated Book" << endl;
        book2.display();

        cout << "Book 3 - Full Book Record" << endl;
        book3.display();

        // Testing negative number of copies
        cout << "Testing Invalid Copies:" << endl;
        Book book4("Invalid Book", "Unknown", -3);
        book4.display();
    }
    catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}


#include <iostream>
#include <string>
using namespace std;

class Auditorium {
private:
    int rows;
    int seatsPerRow;
    char** seatMap;
    int bookedCount;
    string eventName;

public:
    // Dynamic constructor
    Auditorium(string name, int r, int s)
        : rows(r), seatsPerRow(s), seatMap(nullptr),
          bookedCount(0), eventName(name) {

        if (rows < 0 || seatsPerRow < 0) {
            rows = 0;
            seatsPerRow = 0;
        }

        if (rows > 0 && seatsPerRow > 0) {
            seatMap = new char*[rows];

            for (int i = 0; i < rows; i++) {
                seatMap[i] = new char[seatsPerRow];

                for (int j = 0; j < seatsPerRow; j++) {
                    seatMap[i][j] = 'O';
                }
            }
        }

        cout << "Event created: " << eventName << endl;
    }

    // Book a seat
    void bookSeat(int row, int seat) {
        if (row < 1 || row > rows ||
            seat < 1 || seat > seatsPerRow) {
            cout << "Invalid seat number." << endl;
            return;
        }

        if (seatMap[row - 1][seat - 1] == 'O') {
            seatMap[row - 1][seat - 1] = 'X';
            bookedCount++;
            cout << "Seat booked successfully." << endl;
        } else {
            cout << "Seat is already booked." << endl;
        }
    }

    // Cancel a seat
    void cancelSeat(int row, int seat) {
        if (row < 1 || row > rows ||
            seat < 1 || seat > seatsPerRow) {
            cout << "Invalid seat number." << endl;
            return;
        }

        if (seatMap[row - 1][seat - 1] == 'X') {
            seatMap[row - 1][seat - 1] = 'O';
            bookedCount--;
            cout << "Booking cancelled successfully." << endl;
        } else {
            cout << "Seat is not booked." << endl;
        }
    }

    // Display seat map
    void displaySeats() const {
        cout << "Seat Map for " << eventName << ":" << endl;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < seatsPerRow; j++) {
                cout << seatMap[i][j] << " ";
            }
            cout << endl;
        }
    }

    // Destructor
    ~Auditorium() {
        for (int i = 0; i < rows; i++) {
            delete[] seatMap[i];
        }

        delete[] seatMap;

        cout << "Event closed: " << eventName << endl;
        cout << "Total booked seats: " << bookedCount << endl;
    }
};

// Logger class from the assignment
struct Logger {
    string n;

    Logger(const string& s) : n(s) {
        cout << '+' << n << ' ';
    }

    Logger(const Logger& o) : n(o.n + "c") {
        cout << "copy" << n << ' ';
    }

    ~Logger() {
        cout << '-' << n << ' ';
    }
};

void use(Logger) {
    cout << "use ";
}

int main() {
    cout << "STACK OBJECT" << endl;

    Auditorium a("Music Event", 2, 3);
    a.bookSeat(1, 1);
    a.bookSeat(1, 2);
    a.displaySeats();
    a.cancelSeat(1, 2);

    cout << endl << "BLOCK OBJECT" << endl;

    {
        Auditorium b("Dance Event", 2, 2);
        b.bookSeat(2, 1);
        b.displaySeats();
    }

    cout << endl << "HEAP OBJECT" << endl;

    Auditorium* p = new Auditorium("Drama Event", 2, 2);
    p->bookSeat(1, 1);
    p->displaySeats();
    delete p;

    cout << endl << "ZERO ROW EVENT" << endl;

    Auditorium empty("Empty Event", 0, 0);

    cout << endl << "LOGGER OUTPUT" << endl;

    Logger x("A");

    {
        Logger y("B");
    }

    use(x);

    Logger* q = new Logger("P");
    delete q;

    cout << "end ";

    return 0;
}


#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <stdexcept>
using namespace std;

class Time {
private:
    int totalSeconds;

public:
    Time(int h = 0, int m = 0, int s = 0) {
        totalSeconds = h * 3600 + m * 60 + s;
    }

    // Prefix increment
    Time& operator++() {
        ++totalSeconds;
        return *this;
    }

    // Postfix increment
    Time operator++(int) {
        Time old = *this;
        ++totalSeconds;
        return old;
    }

    bool operator==(const Time& other) const {
        return totalSeconds == other.totalSeconds;
    }

    bool operator<(const Time& other) const {
        return totalSeconds < other.totalSeconds;
    }

    void display() const {
        int h = totalSeconds / 3600;
        int m = (totalSeconds % 3600) / 60;
        int s = totalSeconds % 60;

        cout << setfill('0')
             << setw(2) << h << ":"
             << setw(2) << m << ":"
             << setw(2) << s
             << setfill(' ');
    }
};

class Playlist {
private:
    vector<string> tracks;

public:
    Playlist(vector<string> t) : tracks(t) {}

    // Non-const version
    string& operator[](int index) {
        if (index < 0 || index >= static_cast<int>(tracks.size())) {
            throw out_of_range("Invalid playlist index");
        }
        return tracks[index];
    }

    // Const version
    const string& operator[](int index) const {
        if (index < 0 || index >= static_cast<int>(tracks.size())) {
            throw out_of_range("Invalid playlist index");
        }
        return tracks[index];
    }

    int size() const {
        return static_cast<int>(tracks.size());
    }
};

int main() {
    Time t(0, 0, 5);

    cout << "Initial Time: ";
    t.display();

    Time a = t++;
    Time b = ++t;

    cout << "\nAfter Postfix Increment, a = ";
    a.display();

    cout << "\nAfter Prefix Increment, b = ";
    b.display();

    cout << "\nCurrent Time: ";
    t.display();

    cout << "\n\nTime Comparison:\n";
    cout << boolalpha;
    cout << "a == b: " << (a == b) << endl;
    cout << "a < b: " << (a < b) << endl;

    // Test minute and hour rollover
    Time rollover(0, 59, 59);
    ++rollover;

    cout << "\nAfter 59:59 rollover: ";
    rollover.display();

    // Playlist demonstration
    Playlist playlist({"Song One", "Song Two", "Song Three"});

    cout << "\n\nPlaylist:\n";

    for (int i = 0; i < playlist.size(); i++) {
        cout << i << ": " << playlist[i] << endl;
    }

    // Modify a track using non-const operator[]
    playlist[1] = "Updated Song";

    cout << "\nUpdated Track: " << playlist[1] << endl;

    // Test invalid index
    try {
        cout << playlist[5] << endl;
    }
    catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}

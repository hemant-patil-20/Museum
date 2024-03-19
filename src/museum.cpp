#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

// Define the Time class with comparison operators

class Time {
private:
    int hour;
    int minute;

public:
    Time(int h, int m) : hour(h), minute(m) {}

    // Getters for hour and minute
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
	
    // Comparison operators
    bool operator<(const Time& other) const {
        if (hour != other.hour) {
            return hour < other.hour;
        }
        return minute < other.minute;
    }

    bool operator==(const Time& other) const {
        return hour == other.hour && minute == other.minute;
    }

    friend ostream& operator<<(ostream& os, const Time& time) {
        os << time.hour << ":" << time.minute;
        return os;
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: " << argv[0] << " <input_file>\n";
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cout << "Error: Failed to open input file.\n";
        return 1;
    }

    map<Time, int> visitorCount;
    Time startTime(0, 0), endTime(0, 0);
    int maxCount = 0;

    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string start, end;
        getline(iss, start, ',');
        getline(iss, end, ',');

        int startHour, startMinute, endHour, endMinute;
        sscanf(start.c_str(), "%d:%d", &startHour, &startMinute);
        sscanf(end.c_str(), "%d:%d", &endHour, &endMinute);

        Time enterTime(startHour, startMinute);
        Time leaveTime(endHour, endMinute);

        // Increment count for each minute between entering and leaving time
        for (Time time = enterTime; time < leaveTime; ) {
            visitorCount[time]++;
            if (visitorCount[time] > maxCount) {
                maxCount = visitorCount[time];
                startTime = time;
                endTime = time;
            } else if (visitorCount[time] == maxCount) {
                endTime = time;
            }
            // Increment time by one minute
            if (time.getMinute() == 59) {
                time = Time((time.getHour() + 1) % 24, 0);
            } else {
                time = Time(time.getHour(), time.getMinute() + 1);
            }
        }
    }

    cout << startTime << ";" << endTime << ";" << maxCount << endl;

    return 0;
}


// ABCUadvising.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

int key;

struct courseInfo {
    string courseID;
    string courseName;
    //stores pre-reqs in a vector
    vector<std::string> prereqs;
};

class Hashtable {
private:
    size_t numBuckets;
    vector<vector<courseInfo>> table; //Vector of buckets (each bucket is a vector of courseInfo)

    //Hash function to map values to key
    size_t hashFunction(const int key) const {
        return key % numBuckets;
    }

public:
    //inserts a key into Hash table
    void insertItem(string courseID, courseInfo course) {
        int cID; //course id as an int
        cID = stoi(courseID.substr(4, 6));
        key = cID;
        //index = hashFunction(key);
        //stores course id to a bucket
        course.courseID = key;
    }

    //Constructor to initialize bucket count and table
    int  HashTable(int b) {
        this->numBuckets = b;
        table.resize(numBuckets);
    }
};

//menu method
void menu() {
    int userVal;
    courseInfo newCourse;

    cout << "1. Load Data Structure.";
    cout << "2. Print Course List.";
    cout << "3. Print Course.";
    cout << "9. Exit";

    cin >> userVal;
    if (userVal == 1) {
        openFile(newCourse);
    }
    else if (userVal == 2) {
        alphaNum(newCourse);
    }
    else if (userVal == 3) {
        printCourse(newCourse);
    }
    else if (userVal == 9) {
        cout << "Thank you for using the course planner!";
    }
    else {
        cout << userVal << " is not a valid option.";
    }
}

void openFile(courseInfo newCourse) {
    string fileName;

    cout << "Enter name of file";
    cin >> fileName;

    ifstream file(fileName);

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return;
    }
    else { // file does open
        string line;
        vector<string>row;

        char delim = ',';
        while (getline(file, line)) {
            //Process each line here separated by commas
            stringstream ss(line);

            string token;
            while (getline(ss, token, delim)) {
                row.push_back(token);
            }
            newCourse.courseID = row[0];
            newCourse.courseName = row[1];
            for (int i = 2; i < row.size(); i++) {
                newCourse.prereqs.push_back(row[i]);

            }
        }

        file.close();
        return;

        cout << "Finished reading file.";
        menu();
    }
}
//method to print every courseID in alpha-numeric order
//with corresponding information
void alphaNum(courseInfo newCourse) {
    HashTable newTable;
    for (int i = 0; i < newTable; i++) {
        cout << newCourse;

void printCourse(courseInfo newCourse) {

}

int main() {
    std::cout << "Welcome to the course planner.";
    cout;
    menu();
}

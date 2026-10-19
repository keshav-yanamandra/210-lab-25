// Keshav Yanamandra
// COMSC-210-5293, Fall 2026
// Lab 25

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main() {
    vector<string> vectorCodes;
    list<string> listCodes;
    set<string> setCodes;

    string code;

    long long vectorTime;
    long long listTime;
    long long setTime;

    // Race 1: READING
    // File is opened before timing so only the reading is timed.

    ifstream finVector("codes.txt");

    auto start = high_resolution_clock::now();

    while (getline(finVector, code)) {
        vectorCodes.push_back(code);
    }

    auto end = high_resolution_clock::now();

    vectorTime = duration_cast<nanoseconds>(end - start).count();

    finVector.close();


    ifstream finList("codes.txt");

    start = high_resolution_clock::now();

    while (getline(finList, code)) {
        listCodes.push_back(code);
    }

    end = high_resolution_clock::now();

    listTime = duration_cast<nanoseconds>(end - start).count();

    finList.close();


    ifstream finSet("codes.txt");

    start = high_resolution_clock::now();

    while (getline(finSet, code)) {
        setCodes.insert(code);
    }

    end = high_resolution_clock::now();

    setTime = duration_cast<nanoseconds>(end - start).count();

    finSet.close();


    cout << "Vector size: " << vectorCodes.size() << endl;
    cout << "List size: " << listCodes.size() << endl;
    cout << "Set size: " << setCodes.size() << endl;

    cout << endl;

    cout << "Vector reading time: " << vectorTime << " ns" << endl;
    cout << "List reading time: " << listTime << " ns" << endl;
    cout << "Set reading time: " << setTime << " ns" << endl;

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/
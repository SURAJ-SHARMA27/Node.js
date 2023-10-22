#include <iostream>
#include <string>
#include <map>
#include <sstream>

using namespace std;

map<string, char> digitMap = {
    {"zero", '0'},
    {"one", '1'},
    {"two", '2'},
    {"three", '3'},
    {"four", '4'},
    {"five", '5'},
    {"six", '6'},
    {"seven", '7'},
    {"eight", '8'},
    {"nine", '9'}
};

string getPhoneNumber(string input) {
    istringstream iss(input);
    string word;
    string number = "";
    bool d = false, t = false;
    
    while (iss >> word) {
        if (d) {
            number += digitMap[word];
            number += digitMap[word];
            d = false;
        } else if (t) {
            number += digitMap[word];
            number += digitMap[word];
            number += digitMap[word];
            t = false;
        } else if (word == "double") {
            d = true;
        } else if (word == "triple") {
            t = true;
        } else {
            number += digitMap[word];
        }
    }

    return number;
}

int main() {
    string input = "two one nine six eight one six four six zero";
    string phoneNumber = getPhoneNumber(input);
    cout << phoneNumber << endl;

    return 0;
}

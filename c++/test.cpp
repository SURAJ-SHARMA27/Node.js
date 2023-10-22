#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>
#include <algorithm>

using namespace std;

string CorrectPath(string s) {
    while (true) {
        string route;
        vector<pair<int, int>> tracepos;
        int x = 1, y = 5;
        int answer = 1;

        for (char i : s) {
            if (i == '?') {
                char directions[] = {'l', 'r', 'u', 'd'};
                i = directions[rand() % 4];
            }
            if (i == 'u') {
                y += 1;
            } else if (i == 'd') {
                y -= 1;
            } else if (i == 'r') {
                x += 1;
            } else if (i == 'l') {
                x -= 1;
            }

            if (x == 6 || x == 0 || y == 0 || y == 6) {
                answer = 0;
                break;
            }

            pair<int, int> pos = make_pair(x, y);

            if (find(tracepos.begin(), tracepos.end(), pos) != tracepos.end()) {
                answer = 0;
                break;
            } else {
                tracepos.push_back(pos);
            }
            route.push_back(i);
        }

        if (x == 5 && y == 1 && answer == 1) {
            return route;
        }
    }
    
    return "No valid path found";
}

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Seed the random number generator
    string input;
    cin >> input;
    string result = CorrectPath(input);
    cout << result << endl;
    return 0;
}

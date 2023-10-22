#include <iostream>
#include <vector>
#include <sstream>
#include <map>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

string formatOutput(double value) {
    stringstream ss;
    ss << fixed << setprecision(1) << value;
    string formatted = ss.str();
    if (formatted.find('.') != string::npos) {
        while (formatted.back() == '0') {
            formatted.pop_back();
        }
        if (formatted.back() == '.') {
            formatted.pop_back();
        }
    }
    return formatted;
}

string mean_median_mode(string input_string) {
    vector<int> small;
    stringstream ss(input_string);
    int num;
    
    while (ss >> num) {
        small.push_back(num);
    }

    double sum = 0;
    for (int num : small) {
        sum += num;
    }
    double mean_value = ceil(sum / small.size() * 10) / 10;

    sort(small.begin(), small.end());
    int n = small.size();
    double median_value;
    if (n % 2 == 0) {
        median_value = ceil((small[n / 2 - 1] + small[n / 2]) / 2.0 * 10) / 10;
    } else {
        median_value = small[n / 2];
    }

    map<int, int> counts;
    int max_count = 0;
    int mode_value = small[0];

    for (int num : small) {
        counts[num]++;
        if (counts[num] > max_count || (counts[num] == max_count && num > mode_value)) {
            max_count = counts[num];
            mode_value = num;
        }
    }

    string result = "Mean: " + formatOutput(mean_value) + " Median: " + formatOutput(median_value) + " Mode: " + to_string(mode_value);
    return result;
}

int main() {
    string input_string = "2 4 5 6 7 8 2 4 5 2 3 8";
    string result = mean_median_mode(input_string);
    cout << result << endl;
    return 0;
}

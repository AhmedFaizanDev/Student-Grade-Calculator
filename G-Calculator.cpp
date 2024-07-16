#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

void inputGrades(vector<int>& grades) {
    int grade;

    cout << "Enter student grades (enter -1 to finish):\n";

    while (true) {
        if (!(cin >> grade)) {
            cout << "Invalid input. Please enter numeric grades only.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (grade == -1)
            break;
        grades.push_back(grade);
    }
}

void calculateStatistics(const vector<int>& grades) {
    if (grades.empty()) {
        cout << "No grades entered. Exiting.\n";
        return;
    }

    int sum = 0;
    for (int g : grades) {
        sum += g;
    }
    double average = static_cast<double>(sum) / grades.size();

    auto min_grade = *min_element(grades.begin(), grades.end());
    auto max_grade = *max_element(grades.begin(), grades.end());

    cout << "Average grade: " << average << "\n";
    cout << "Highest grade: " << max_grade << "\n";
    cout << "Lowest grade: " << min_grade << "\n";
}

int main() {
    vector<int> grades;

    inputGrades(grades);
    calculateStatistics(grades);

    return 0;
}

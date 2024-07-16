#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> grades;
    int grade;

    cout << "Enter student grades (enter -1 to finish):\n";

    while (true) {
        cin >> grade;
        if (grade == -1)
            break;
        grades.push_back(grade);
    }

    if (grades.empty()) {
        cout << "No grades entered. Exiting.\n";
        return 1;
    }

    // Calculate average
    int sum = 0;
    for (int g : grades) {
        sum += g;
    }
    double average = static_cast<double>(sum) / grades.size();

    // Find minimum and maximum grades
    auto min_grade = *min_element(grades.begin(), grades.end());
    auto max_grade = *max_element(grades.begin(), grades.end());

    // Output statistics
    cout << "Average grade: " << average << "\n";
    cout << "Highest grade: " << max_grade << "\n";
    cout << "Lowest grade: " << min_grade << "\n";

    return 0;
}

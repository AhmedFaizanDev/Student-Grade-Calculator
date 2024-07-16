#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>

using namespace std;

// Function to input grades
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

        if (grade < 0 || grade > 100) { // Example: valid grade range
            cout << "Invalid grade entered. Grade must be between 0 and 100.\n";
            continue;
        }

        grades.push_back(grade);
    }
}

// Function to calculate statistics
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

// Function to calculate median grade
void calculateMedian(const vector<int>& grades) {
    vector<int> sortedGrades = grades; // Copy grades to sort

    sort(sortedGrades.begin(), sortedGrades.end());

    double median;
    if (sortedGrades.size() % 2 == 0) {
        median = (sortedGrades[sortedGrades.size() / 2 - 1] + sortedGrades[sortedGrades.size() / 2]) / 2.0;
    } else {
        median = sortedGrades[sortedGrades.size() / 2];
    }

    cout << "Median grade: " << median << "\n";
}

// Function to sort grades
void sortGrades(vector<int>& grades) {
    sort(grades.begin(), grades.end());

    cout << "Sorted grades:\n";
    for (int grade : grades) {
        cout << grade << " ";
    }
    cout << "\n";
}

int main() {
    vector<int> grades;

    inputGrades(grades);
    calculateStatistics(grades);
    calculateMedian(grades);
    sortGrades(grades);

    return 0;
}

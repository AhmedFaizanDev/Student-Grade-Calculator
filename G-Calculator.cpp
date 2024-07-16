#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

// Function to input grades from a file
void inputGradesFromFile(vector<int>& grades, const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to open file: " << filename << endl;
        return;
    }

    int grade;
    while (file >> grade) {
        if (grade < 0 || grade > 100) {
            cout << "Invalid grade found in file: " << grade << ". Skipping.\n";
            continue;
        }
        grades.push_back(grade);
    }

    file.close();
}

// Function to write statistics to a file
void writeStatisticsToFile(const vector<int>& grades, const string& filename) {
    ofstream file(filename);
    if (!file.is_open()) {
        cout << "Failed to create output file: " << filename << endl;
        return;
    }

    file << "Student Grade Statistics:\n";

    if (grades.empty()) {
        file << "No grades entered.\n";
        file.close();
        return;
    }

    int sum = 0;
    for (int g : grades) {
        sum += g;
    }
    double average = static_cast<double>(sum) / grades.size();

    auto min_grade = *min_element(grades.begin(), grades.end());
    auto max_grade = *max_element(grades.begin(), grades.end());

    file << "Average grade: " << average << "\n";
    file << "Highest grade: " << max_grade << "\n";
    file << "Lowest grade: " << min_grade << "\n";

    // Calculate and write median grade
    vector<int> sortedGrades = grades;
    sort(sortedGrades.begin(), sortedGrades.end());
    double median;
    if (sortedGrades.size() % 2 == 0) {
        median = (sortedGrades[sortedGrades.size() / 2 - 1] + sortedGrades[sortedGrades.size() / 2]) / 2.0;
    } else {
        median = sortedGrades[sortedGrades.size() / 2];
    }
    file << "Median grade: " << median << "\n";

    // Calculate and write mode grade
    unordered_map<int, int> frequency;
    for (int grade : grades) {
        frequency[grade]++;
    }
    int mode = -1;
    int maxFreq = 0;
    for (auto& entry : frequency) {
        if (entry.second > maxFreq) {
            maxFreq = entry.second;
            mode = entry.first;
        }
    }
    file << "Mode grade: " << mode << " (appears " << maxFreq << " times)\n";

    file.close();
}

int main() {
    vector<int> grades;

    // Input grades from file
    inputGradesFromFile(grades, "grades.txt");

    // Calculate and write statistics to file
    writeStatisticsToFile(grades, "results.txt");

    cout << "Student grade statistics have been calculated and saved to 'results.txt'.\n";

    return 0;
}

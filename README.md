# Student Grade Calculator

The Student Grade Calculator is a C++ program designed to calculate and analyze student grades, providing detailed statistics and grade distribution analysis.

## Features

### Input Handling

- **Read student grades from a text file (`grades.txt`):**
  - The program reads student grades from a specified text file (`grades.txt`). Each grade should be on a new line within the file.

### Statistics Calculation

- **Calculate various statistics:**
  - **Average Grade:** Computes the arithmetic mean of all input grades.
  - **Median Grade:** Determines the middle value in a sorted list of grades, which separates the higher half from the lower half.
  - **Mode Grade:** Identifies the grade that appears most frequently in the dataset.

### Grade Distribution Analysis

- **Analyze and categorize grades into different ranges:**
  - Grades are categorized into the following ranges:
    - 0-59
    - 60-69
    - 70-79
    - 80-89
    - 90-100
  - The program counts how many grades fall into each range and generates a distribution report.

### Output Generation

- **Generate a detailed report (`results.txt`):**
  - After calculating statistics and analyzing grade distribution, the program generates a comprehensive report stored in `results.txt`.
  - The report includes:
    - Average grade
    - Median grade
    - Mode grade
    - Grade distribution across defined ranges

## Installation

To run the Student Grade Calculator locally on your machine, follow these steps:

1. **Clone the repository:**
   ```bash
   git clone https://github.com/AhmedFaizanDev/Student-Grade-Calculator.git
   cd Student-Grade-Calculator

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const int NUM_SCORES = 5;
    string studentName = "";
    int studentCount = 0;
    double totalAverageSum = 0.0;

    cout << fixed << setprecision(1);

    while (true) {
        cout << "Student name (or end to finish): ";
        cin >> studentName;

        if (studentName == "end") {
            break;
        }

        int scoreSum = 0;

        // Ввод и проверка 5 оценок для текущего студента
        for (int i = 1; i <= NUM_SCORES; i++) {
            int score = 0;

            while (true) {
                cout << "Score " << i << ": ";
                cin >> score;

                // Защита от ввода букв вместо числа (бонус)
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout << "Invalid score. Enter a value from 0 to 100." << endl;
                    continue;
                }

                if (score < 0 || score > 100) {
                    cout << "Invalid score. Enter a value from 0 to 100." << endl;
                } else {
                    break;
                }
            }

            scoreSum += score;
        }

        double average = static_cast<double>(scoreSum) / NUM_SCORES;
        char grade = 'F';

        if (average >= 90.0) {
            grade = 'A';
        } else if (average >= 75.0) {
            grade = 'B';
        } else if (average >= 60.0) {
            grade = 'C';
        } else {
            grade = 'F';
        }

        cout << studentName << ": average " << average << ", grade " << grade << endl;

        studentCount++;
        totalAverageSum += average;
    }

    if (studentCount == 0) {
        cout << "No students entered" << endl;
    } else {
        double classAverage = totalAverageSum / studentCount;
        cout << "Students entered: " << studentCount << endl;
        cout << "Class average: " << classAverage << endl;
    }

    return 0;
}

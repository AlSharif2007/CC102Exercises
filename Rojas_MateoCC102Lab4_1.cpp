#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    char again;

    do {
        system("clear");
        int students, quizzes;
        cout << "Enter number of students: ";
        cin >> students;
        cout << "Enter number of quizzes: ";
        cin >> quizzes;

        double scores[50][50];
        double average[50];

        for (int i = 0; i < students; i++) {
            cout << "\nStudent " << i + 1 << " scores:\n";
            double sum = 0;

            for (int j = 0; j < quizzes; j++) {
                cout << "Quiz " << j + 1 << ": ";
                cin >> scores[i][j];
                sum += scores[i][j];
            }

            double avg = sum / quizzes;
            avg = (int)(avg * 100 + 0.5) / 100.0;
            average[i] = avg;
        }

        cout << "\n--------------------------------------------------\n";
        cout << "Student\t";
        for (int j = 0; j < quizzes; j++)
            cout << "Q" << j + 1 << "\t";
        cout << "Average\n";
        cout << "--------------------------------------------------\n";

        for (int i = 0; i < students; i++) {
            cout << i + 1 << "\t";
            for (int j = 0; j < quizzes; j++)
                cout << scores[i][j] << "\t";

            cout << average[i] << "%\n";
            cout << "--------------------------------------------------\n";
        }

        cout << "\nRun program again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}

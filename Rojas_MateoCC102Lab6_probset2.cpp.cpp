#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

struct book {
    int barcode;
    string title;
    int year;
    int rating;
};

string getCategory(int rating) {
    switch (rating) {
        case 5: return "Excellent";
        case 4: return "Very Good";
        case 3: return "Good";
        case 2: return "Fair";
        case 1: return "Poor";
        default: return "No Rating";
    }
}

int main() {
    char repeat;

    do {
        system("cls");
        int n;
        cout << "Enter number of books: ";
        cin >> n;

        book b[n];

        for (int i = 0; i < n; i++) {
            cout << "\nBook " << i + 1 << endl;

            // Unique barcode check
            bool unique;
            do {
                unique = true;
                cout << "Enter Barcode: ";
                cin >> b[i].barcode;

                for (int j = 0; j < i; j++) {
                    if (b[i].barcode == b[j].barcode) {
                        cout << "Barcode already exists! Enter another.\n";
                        unique = false;
                        break;
                    }
                }
            } while (!unique);

            cin.ignore();
            cout << "Enter Title: ";
            getline(cin, b[i].title);

            cout << "Enter Year Published: ";
            cin >> b[i].year;

            cout << "Enter Rating (0-5): ";
            cin >> b[i].rating;
        }

        // Display
        cout << "\n\n--- Book Records ---\n";
        cout << "Barcode\tTitle\tYear\tRating\tCategory\n";

        for (int i = 0; i < n; i++) {
            cout << b[i].barcode << "\t"
                 << b[i].title << "\t"
                 << b[i].year << "\t"
                 << b[i].rating << "\t"
                 << getCategory(b[i].rating) << endl;
        }

        cout << "\nRun again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

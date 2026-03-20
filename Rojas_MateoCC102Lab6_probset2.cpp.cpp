#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

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

template <typename T>
void input(T b[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "\nBook " << i + 1 << endl;

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

        cout << "Enter Year: ";
        cin >> b[i].year;

        cout << "Enter Rating (0-5): ";
        cin >> b[i].rating;
    }
}

template <typename T>
void display(T b[], int n) {
    cout << "\n--- Book Records ---\n";
    cout << "Barcode\tTitle\tYear\tRating\tCategory\n";

    for (int i = 0; i < n; i++) {
        cout << b[i].barcode << "\t"
             << b[i].title << "\t"
             << b[i].year << "\t"
             << b[i].rating << "\t"
             << getCategory(b[i].rating) << endl;
    }
}

int main() {
    int n;
    char repeat;

    do {
        system("clear"); 
        
        cout << "Enter number of books: ";
        cin >> n;

        struct book {
            int barcode;
            string title;
            int year;
            int rating;
        };
        
        book* b = new book[n];

        input(b, n);
        display(b, n);

        delete[] b;

        cout << "\nRun again? (y/n): ";
        cin >> repeat;

    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

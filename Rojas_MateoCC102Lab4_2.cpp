#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    char again;

    do {
        system("clear");
        const int PRODUCTS = 5;
        const int SALESPERSONS = 4;

        vector<vector<double>> sales(PRODUCTS, vector<double>(SALESPERSONS, 0));

        int salesperson, product;
        double amount;
        char choice;

        do {
            cout << "\nEnter Salesperson number (1-4): ";
            cin >> salesperson;

            cout << "Enter Product number (1-5): ";
            cin >> product;

            cout << "Enter Amount sold: ";
            cin >> amount;

            if (salesperson >= 1 && salesperson <= 4 &&
                product >= 1 && product <= 5) {

                sales[product - 1][salesperson - 1] += amount;

            } else {
                cout << "Invalid input! Try again.\n";
            }

            cout << "Enter another sale? (y/n): ";
            cin >> choice;

        } while (choice == 'y' || choice == 'Y');

        cout << "\n\nSales Summary Table\n";
        cout << "-------------------------------------------------------------\n";
        cout << "| Product\tSP1\tSP2\tSP3\tSP4\tTotal |\n";
        cout << "-------------------------------------------------------------\n";

        double grandTotal = 0;

        for (int i = 0; i < PRODUCTS; i++) {
            double rowTotal = 0;

            cout << "| " << i + 1 << "\t";

            for (int j = 0; j < SALESPERSONS; j++) {
                cout << sales[i][j] << ".00%\t";
                rowTotal += sales[i][j];
            }

            cout << rowTotal << ".00% |\n";
            cout << "-------------------------------------------------------------\n";

            grandTotal += rowTotal;
        }

        cout << "| Total\t";

        for (int j = 0; j < SALESPERSONS; j++) {
            double columnTotal = 0;

            for (int i = 0; i < PRODUCTS; i++) {
                columnTotal += sales[i][j];
            }

            cout << columnTotal << ".00%\t";
        }

        cout << grandTotal << ".00% |\n";
        cout << "-------------------------------------------------------------\n";

        cout << "\nRun program again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    return 0;
}

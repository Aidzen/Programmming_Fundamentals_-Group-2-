#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int MAX_COLS = 10;
const int MAX_ROWS = 10;

// sheet structure
string sheetName;
int colCount = 0;
string colNames[MAX_COLS];
string colTypes[MAX_COLS];
string table[MAX_ROWS][MAX_COLS];
int rowCount = 0;

// checker if is int
bool isInteger(const string& s) {
    if (s.empty()) return false; //If empty then false
    for (char c : s) {
        if (!isdigit(c)) return false; // If input not digit, then false
    }
    return true;
}

// to create sheet
void createSheet() {
    cout << "Enter attendance sheet name: ";
    getline(cin, sheetName);
    cout << "Attendance sheet \"" << sheetName << "\" created successfully.\n\n";

    cout << "Define number of columns (max 10): ";
    cin >> colCount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    if (colCount > MAX_COLS) colCount = MAX_COLS; //Makes sure not exceed max columns

    for (int i = 0; i < colCount; i++) {
        cout << "Enter column " << i + 1 << " name: ";
        getline(cin, colNames[i]); //Store name in array

        cout << "Enter data type (INT / TEXT): ";
        getline(cin, colTypes[i]); //Store type in array
    }

    cout << "\nSheet structure created successfully.\n\n";
}

// to create row
void insertRow() {
    if (rowCount >= MAX_ROWS) {
        cout << "Error: Sheet row limit reached.\n"; //error message
        return;
    }

    cout << "-------------------------------------------\n";
    cout << "Insert New Attendance Row\n";
    cout << "-------------------------------------------\n";

    string value;
    for (int c = 0; c < colCount; c++) {
        cout << "Enter " << colNames[c] << ": ";
        getline(cin, value);

        if (colTypes[c] == "INT" && !isInteger(value)) {
            cout << "Error: Invalid INT value. Please enter a number.\n";
            return;
        }

        table[rowCount][c] = value;
    }

    rowCount++;
    cout << "Row inserted successfully.\n\n";
}

// View CSV
void viewCSV() {
    cout << "-------------------------------------------\n";
    cout << "View Attendance Sheet (CSV Mode)\n";
    cout << "-------------------------------------------\n";

    for (int c = 0; c < colCount; c++) {
        cout << colNames[c];
        if (c < colCount - 1) cout << ", ";
    }
    cout << endl;

    for (int r = 0; r < rowCount; r++) {
        for (int c = 0; c < colCount; c++) {
            cout << table[r][c];
            if (c < colCount - 1) cout << ", ";
        }
        cout << endl;
    }
}

// ooutput
int main() {

    cout << "===========================================\n";
    cout << "   STUDENT ATTENDANCE TRACKER - MILESTONE 1\n";
    cout << "===========================================\n\n";

    createSheet();

    char choice;

    do {
        insertRow();
        cout << "Add another row? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    while (choice == 'y' || choice == 'Y');

    viewCSV();

    cout << "\n-------------------------------------------\n";
    cout << "End of Milestone 1 Output\n";
    cout << "-------------------------------------------\n";

    return 0;
}

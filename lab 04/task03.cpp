#include <iostream>
#include <list>

using namespace std;

class Spreadsheet {
private:
    list<list<int>> data;

public:
    //add row
    void addRow(const list<int>& row) {
        data.push_back(row);
    }

    // delete row
    void deleteRow(int rowIndex) {
        if (rowIndex>=0 && rowIndex<data.size()) {
            auto it = data.begin();
            for (int i = 0; i<rowIndex; ++i) {
                ++it;
            }
            data.erase(it);
            cout<<"\nDeleted successfully";
        } else {
            cout <<"Invalid row index!" <<endl;
        }
    }

    // display spreadsheet
    void display() {
        cout << "Spreadsheet:" << endl;
        for (const auto& row : data) {
            for (int cell : row) {
                cout << cell << "\t";
            }
            cout << endl;
        }
    }
};

int main() {
    Spreadsheet spreadsheet;

    spreadsheet.addRow({10, 20, 30});
    spreadsheet.addRow({40, 50, 60});
    spreadsheet.addRow({70, 80, 90});

    char choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Add Row" << endl;
        cout << "2. Delete Row" << endl;
        cout << "3. Display Spreadsheet" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1': {
                cout << "Enter values for New row (separate by spaces and enter -1 to end): ";
                list<int> newRow;
                int value;
                while (cin >> value && value != -1) {
                    newRow.push_back(value);
                }
                spreadsheet.addRow(newRow);
                break;
            }
            case '2': {
                
                int rowIndex;
                cout << "Enter the index to delete row: ";
                cin >> rowIndex;
                spreadsheet.deleteRow(rowIndex);
                break;
            }
            case '3':
                spreadsheet.display();
                break;
            case '4':
                cout << "Exiting..." << endl;
                break;
                
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
        }
    } while (choice != '4');

    return 0;
}

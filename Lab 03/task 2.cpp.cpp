#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map< string, string > phoneBook;
    string searchName;

    phoneBook["syed"] = "123-456789";
    phoneBook["Ali"] = "987-654321";
    phoneBook["haider"] = "456-789123";

    cout << "Enter the name of the person to find in the phone book: ";
    getline(cin, searchName);

    if (!searchName.empty()) {
        searchName[0] = toupper(searchName[0]);
    }

    auto it = phoneBook.find(searchName);
    
    if (it != phoneBook.end()) {
        cout << "Contact found: " << it->first << " - " << it->second << endl;
    } 
    else {
        cout << " Contact not found" << endl;
    }

    return 0;
}

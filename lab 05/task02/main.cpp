#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Book {
private:
    string title;
    string author;
    int publicationYear;
    bool borrowed;

public:
    Book(const string& title, const string& author, int publicationYear)
        : title(title), author(author), publicationYear(publicationYear), borrowed(false) {}

    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    int getPublicationYear() const { return publicationYear; }
    bool isBorrowed() const { return borrowed; }
    void setBorrowed(bool status) { borrowed = status; }
};

class Library {
private:
    vector<Book> inventory;

public:
    void addBook(const Book& book) { inventory.push_back(book); }

    bool removeBook(const string& bookTitle) {
        auto it = find_if(inventory.begin(), inventory.end(),
            [&bookTitle](const Book& book) { return book.getTitle() == bookTitle; });

        if (it != inventory.end()) {
            inventory.erase(it);
            return true;
        }
        return false;
    }

    void listBooks() const {
        if (inventory.empty()) {
            cout << "The library is empty." << endl;
        }
        else {
            cout << "Books in the library:" << endl;
            for (const auto& book : inventory) {
                cout << "- " << book.getTitle() << " by " << book.getAuthor() << " (" << book.getPublicationYear() << ")" << endl;
            }
        }
    }
};

int main() {
    Library library;

    while (true) {
        cout << "\nLibrary Management System" << endl;
        cout << "1. Add a book" << endl;
        cout << "2. Remove a book" << endl;
        cout << "3. List all books" << endl;
        cout << "4. Exit" << endl;
        cout << "Choose an option: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string title, author;
            int year;
            cout << "Enter book title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter author name: ";
            getline(cin, author);
            cout << "Enter publication year: ";
            cin >> year;
            library.addBook(Book(title, author, year));
            break;
        }
        case 2: {
            string title;
            cout << "Enter book title to remove: ";
            cin.ignore();
            getline(cin, title);
            if (library.removeBook(title)) {
                cout << "Book removed successfully." << endl;
            }
            else {
                cout << "Book not found." << endl;
            }
            break;
        }
        case 3:
            library.listBooks();
            break;
        case 4:
            cout << "Exiting..." << endl;
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
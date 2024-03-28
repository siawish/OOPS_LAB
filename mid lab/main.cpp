#include<iostream>
#include<vector>

using namespace std;

class Book {
private:
    string title;
    string author;
    double price;
    int quantity;

public:
    Book(string title, string author, double price, int quantity) : title(title), author(author), price(price), quantity(quantity) {}

    string getTitle() { return title; }
    string getAuthor() { return author; }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }

    void decreaseQuantity(int amount) {
        if (quantity >= amount)
            quantity -= amount;
        else
            cout << " not available" << endl;
    }
};

class ShoppingCart {
private:
    vector<Book*> cart;

public:
    void addBookToCart(Book* book) {
        cart.push_back(book);
        book->decreaseQuantity(1); 
    }

    void viewCartContents() {
        cout << "Your Cart:" << endl;
        for (auto book : cart) {
            cout << "\nTitle: " << book->getTitle() << "\nWritten by: " << book->getAuthor() << "\nCost: PKR " << book->getPrice() << endl;
        }
    }

    double calculateTotalPrice() {
        double total = 0.0;
        for (auto book : cart) {
            total += book->getPrice();
        }
        return total;
    }

    void checkout() {
        cout << "\tTotal Price : PKR " << calculateTotalPrice() << endl;
        cout << "\tThanks for shopping here" << endl;
    }
};

void system() {
    cout << "---------------------------------Welcome to our store-----------------------------------------" << endl;
    Book book1("Life of prophet", "mufti tariq masood", 1500, 5);
    Book book2("1949 migration", "aleem ahmed", 999, 8);
    Book book3("www 2", "muhammad khan", 1050.49, 3);

    ShoppingCart cart;

    int choice;
    do {
        cout << "-----------------------------------main menu---------------------------------------------" << endl;
        cout << "\n\t1. Add book to cart" << "\n\t2. View cart contents";
        cout << "\n\t3. Proceed to checkout" << "\n\t4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            int bookChoice;
            cout << "Main menu: ";
            cout << "\nChoose book to add in cart:" << endl;
            cout << "1. " << book1.getTitle() << endl;
            cout << "2. " << book2.getTitle() << endl;
            cout << "3. " << book3.getTitle() << endl;
            cout << "Enter your choice: ";
            cin >> bookChoice;

            Book* selectedBook;
            switch (bookChoice) {
            case 1:
                selectedBook = &book1;
                break;
            case 2:
                selectedBook = &book2;
                break;
            case 3:
                selectedBook = &book3;
                break;
            default:
                cout << "Invalid option!" << endl;
                continue;
            }
            cart.addBookToCart(selectedBook);
            cout << "Book added to cart." << endl;
            break;
        case 2:
            cart.viewCartContents();
            break;
        case 3:
            cart.checkout();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 4);
}

int main() {
    system();
    return 0;
}

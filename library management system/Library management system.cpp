#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Book {
    string title, author, ISBN;
    bool isAvailable;
    time_t dueDate;

    Book(string t, string a, string i) : title(t), author(a), ISBN(i), isAvailable(true), dueDate(0) {}
};

struct Borrower {
    string name;
    string borrowedISBN;
    time_t borrowDate;

    Borrower(string n, string isbn) : name(n), borrowedISBN(isbn) {
        time(&borrowDate);
    }
};

vector<Book> books;
vector<Borrower> borrowers;

// Function to add a book
void addBook() {
    string title, author, ISBN;
    cout << "Enter Book Title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter ISBN: ";
    getline(cin, ISBN);

    books.push_back(Book(title, author, ISBN));
    cout << "Book added successfully!\n";
}

// Function to search for a book
void searchBook() {
    string query;
    cout << "Enter title, author, or ISBN to search: ";
    cin.ignore();
    getline(cin, query);

    bool found = false;
    for (const auto &book : books) {
        if (book.title == query || book.author == query || book.ISBN == query) {
            cout << "\nBook Found:\n";
            cout << "Title: " << book.title << "\nAuthor: " << book.author << "\nISBN: " << book.ISBN 
                 << "\nStatus: " << (book.isAvailable ? "Available" : "Checked Out") << "\n";
            found = true;
        }
    }
    if (!found) cout << "No matching book found.\n";
}

// Function to check out a book
void checkoutBook() {
    string ISBN, borrowerName;
    cout << "Enter ISBN of the book to check out: ";
    cin >> ISBN;
    cout << "Enter Borrower Name: ";
    cin.ignore();
    getline(cin, borrowerName);

    for (auto &book : books) {
        if (book.ISBN == ISBN && book.isAvailable) {
            book.isAvailable = false;

            time_t now;
            time(&now);
            book.dueDate = now + (7 * 24 * 60 * 60); // 7-day borrowing period

            borrowers.push_back(Borrower(borrowerName, ISBN));
            cout << "Book checked out successfully!\n";
            return;
        }
    }
    cout << "Book not available or invalid ISBN.\n";
}

// Function to return a book
void returnBook() {
    string ISBN;
    cout << "Enter ISBN of the book to return: ";
    cin >> ISBN;

    for (auto &book : books) {
        if (book.ISBN == ISBN && !book.isAvailable) {
            book.isAvailable = true;

            // Calculate fine if overdue
            time_t now;
            time(&now);
            double overdueDays = difftime(now, book.dueDate) / (60 * 60 * 24);
            if (overdueDays > 0) {
                cout << "Book returned late! Fine: $" << overdueDays * 1.0 << "\n"; // $1 per day fine
            } else {
                cout << "Book returned successfully!\n";
            }

            // Remove borrower record
            for (size_t i = 0; i < borrowers.size(); i++) {
                if (borrowers[i].borrowedISBN == ISBN) {
                    borrowers.erase(borrowers.begin() + i);
                    break;
                }
            }

            return;
        }
    }
    cout << "Invalid ISBN or book was not checked out.\n";
}

// Function to display available books
void viewBooks() {
    if (books.empty()) {
        cout << "No books available in the library.\n";
        return;
    }
    cout << "\nLibrary Books:\n";
    for (const auto &book : books) {
        cout << "Title: " << book.title << "\nAuthor: " << book.author 
             << "\nISBN: " << book.ISBN << "\nStatus: " 
             << (book.isAvailable ? "Available" : "Checked Out") << "\n\n";
    }
}

int main() {
    int choice;
    do {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. View Books\n";
        cout << "4. Check Out Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: viewBooks(); break;
            case 4: checkoutBook(); break;
            case 5: returnBook(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}

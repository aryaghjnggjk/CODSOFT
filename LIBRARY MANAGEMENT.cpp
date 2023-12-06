#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Book {
public:
    std::string title;
    std::string author;
    std::string ISBN;
    bool isAvailable;

    Book(const std::string& t, const std::string& a, const std::string& i)
        : title(t), author(a), ISBN(i), isAvailable(true) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(const std::string& title, const std::string& author, const std::string& ISBN) {
        books.push_back(Book(title, author, ISBN));
    }

    std::vector<Book> searchBooks(const std::string& keyword) {
        std::vector<Book> result;
        for (std::vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
            if (it->title.find(keyword) != std::string::npos ||
                it->author.find(keyword) != std::string::npos ||
                it->ISBN.find(keyword) != std::string::npos) {
                result.push_back(*it);
            }
        }
        return result;
    }

    void checkoutBook(const std::string& ISBN) {
        for (std::vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
            if (it->ISBN == ISBN && it->isAvailable) {
                it->isAvailable = false;
                std::cout << "Book checked out successfully.\n";
                return;
            }
        }
        std::cout << "Book not found or already checked out.\n";
    }

    void returnBook(const std::string& ISBN) {
        for (std::vector<Book>::iterator it = books.begin(); it != books.end(); ++it) {
            if (it->ISBN == ISBN && !it->isAvailable) {
                it->isAvailable = true;
                std::cout << "Book returned successfully.\n";
                return;
            }
        }
        std::cout << "Book not found or already returned.\n";
    }
};

int main() {
    Library library;

    library.addBook("The Catcher in the Rye", "J.D. Salinger", "978-0-316-76948-0");
    library.addBook("To Kill a Mockingbird", "Harper Lee", "978-0-06-112008-4");
    library.addBook("1984", "George Orwell", "978-0-452-28423-4");

    std::vector<Book> searchResult = library.searchBooks("Harper Lee");
    if (!searchResult.empty()) {
        std::cout << "Search Results:\n";
        for (std::vector<Book>::iterator it = searchResult.begin(); it != searchResult.end(); ++it) {
            std::cout << "Title: " << it->title << ", Author: " << it->author << ", ISBN: " << it->ISBN << "\n";
        }
    } else {
        std::cout << "No books found.\n";
    }

    library.checkoutBook("978-0-316-76948-0");

    library.returnBook("978-0-316-76948-0");

    return 0;
}

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


class Book {
private:
    std::string title;
    std::vector<std::string> authors;
    std::string isbn;
    double price;
    int publishYear;

public:
    // Constructor
    Book(const std::string &title, const std::vector<std::string> &authors, const std::string &isbn, double price, int publishYear)
        : title(title), authors(authors), isbn(isbn), price(price), publishYear(publishYear) {}

    // Getter
    std::string getTitle() const { return title; }
    const std::vector<std::string> &getAuthors() const { return authors; }
    std::string getIsbn() const { return isbn; }
    double getPrice() const { return price; }
    int getPublishYear() const { return publishYear; }

    // Setter
    void setPrice(double newPrice) { price = newPrice; }

    // Print info
    void printInfo() const {
        std::cout << "Title: " << title << "\nISBN: " << isbn << "\nPrice: " << price << "\nPublish Year: " << publishYear << "\nAuthors:";
        for (const auto &author : authors) {
            std::cout << " " << author;
        }
        std::cout << std::endl;
    }

    bool operator==(const Book &other) const {
        return isbn == other.isbn;
    }
};

class Bookshop {
private:
    int bookNum;
    double income;
    std::vector<Book> books; // Store all the books in the bookshop.
    std::string bookshopName;

public:
    // Constructor
    Bookshop(std::string name) : bookNum(0), books(), bookshopName(name), income(0.0) {}

    // Add
    void addBook(const Book &book) {
        books.push_back(book);
        bookNum++;
    }

   // Remove a book by ISBN
    void removeBook(const std::string& isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getIsbn() == isbn) {
                books.erase(it);
                break;
            }
        }
    }

    // Sell a book by ISBN
    void sellBook(const std::string& isbn) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->getIsbn() == isbn) {
                income += it->getPrice();
                books.erase(it);
                break;
            }
        }
    }

    // Getter
    int getBookNum() const { return bookNum; }
    double getIncome() const { return income; }

    // Display all books
    void displayBooks() const {
        for (const auto &book : books) {
            book.printInfo();
        }
    }
};

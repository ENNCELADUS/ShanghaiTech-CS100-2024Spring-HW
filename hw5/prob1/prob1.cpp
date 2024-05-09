#include <iostream>
#include <vector>
#include <string>

class Book {
private:
    std::string title;
    std::vector<std::string> authors;
    std::string isbn;
    double price;
    int publishYear;

public:
    // Default constructor
    Book() = default;

    // Constructor with parameters
    Book(const std::string &title, const std::vector<std::string> &authors, const std::string &isbn, double price, int publishYear)
        : title(title), authors(authors), isbn(isbn), price(price), publishYear(publishYear) {}

    Book(const Book& other) = default;
    Book(Book&& other) noexcept = default;
    Book& operator=(const Book& other) = default;
    Book& operator=(Book&& other) noexcept = default;

    // Destructor
    ~Book() = default;

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
    // Default constructor
    Bookshop() = default;

    // Constructor with parameters
    Bookshop(std::string name) : bookNum(0), income(0.0), books(), bookshopName(name) {}

    Bookshop(const Bookshop& other) = default;
    Bookshop(Bookshop&& other) noexcept = default;
    Bookshop& operator=(const Bookshop& other) = default;
    Bookshop& operator=(Bookshop&& other) noexcept = default;
    
    // Destructor
    ~Bookshop() = default;

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

int main() {
    // 创建几本书
    Book book1("The Great Gatsby", {"F. Scott Fitzgerald"}, "1234567890", 10.99, 1925);
    Book book2("1984", {"George Orwell"}, "2345678901", 15.99, 1949);
    Book book3("To Kill a Mockingbird", {"Harper Lee"}, "3456789012", 12.99, 1960);

    // 创建书店
    Bookshop myBookshop("My Awesome Bookshop");

    // 添加书籍到书店
    myBookshop.addBook(book1);
    myBookshop.addBook(book2);
    myBookshop.addBook(book3);

    // 显示书店中的所有书籍
    std::cout << "Books available in the bookshop before sales:" << std::endl;
    myBookshop.displayBooks();

    // 销售一本书
    myBookshop.sellBook("2345678901");  // Selling "1984"

    // 显示销售后的书店信息
    std::cout << "\nBooks available in the bookshop after selling one book:" << std::endl;
    myBookshop.displayBooks();

    // 显示书店的总收入
    std::cout << "Total income of the bookshop: $" << myBookshop.getIncome() << std::endl;

    // 测试拷贝构造函数
    Bookshop copyOfBookshop = myBookshop;  // 使用拷贝构造函数
    std::cout << "\nBooks available in the copied bookshop:" << std::endl;
    copyOfBookshop.displayBooks();

    // 测试移动构造函数
    Bookshop movedBookshop = std::move(myBookshop);  // 使用移动构造函数
    std::cout << "\nBooks available in the moved bookshop:" << std::endl;
    movedBookshop.displayBooks();

    // 创建另一个书店，用于测试赋值运算符
    Bookshop anotherBookshop("Another Bookshop");
    anotherBookshop.addBook(book3);  // 只加入一本书

    // 测试拷贝赋值运算符
    anotherBookshop = copyOfBookshop;
    std::cout << "\nBooks available in another bookshop after copy assignment:" << std::endl;
    anotherBookshop.displayBooks();

    // 测试移动赋值运算符
    Bookshop yetAnotherBookshop("Yet Another Bookshop");
    yetAnotherBookshop = std::move(anotherBookshop);  // 使用移动赋值
    std::cout << "\nBooks available in yet another bookshop after move assignment:" << std::endl;
    yetAnotherBookshop.displayBooks();

    return 0;
}
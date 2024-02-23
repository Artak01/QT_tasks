#include <iostream>
#include <string>

class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn) 
        : title(title), author(author), isbn(isbn) {}

    void setTitle(const std::string& newTitle) {
        title = newTitle;
    }

    void setAuthor(const std::string& newAuthor) {
        author = newAuthor;
    }

    void setISBN(const std::string& newISBN) {
        isbn = newISBN;
    }

    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    std::string getISBN() const {
        return isbn;
    }
};

int main() {
    Book book("The Great Gatsby", "F. Scott Fitzgerald", "9780743273565");

    std::cout << "Original Book:" << std::endl;
    std::cout << "Title: " << book.getTitle() << std::endl;
    std::cout << "Author: " << book.getAuthor() << std::endl;
    std::cout << "ISBN: " << book.getISBN() << std::endl;

    book.setTitle("To Kill a Mockingbird");
    book.setAuthor("Harper Lee");
    book.setISBN("9780061120084");

    std::cout << "\nUpdated Book:" << std::endl;
    std::cout << "Title: " << book.getTitle() << std::endl;
    std::cout << "Author: " << book.getAuthor() << std::endl;
    std::cout << "ISBN: " << book.getISBN() << std::endl;

    return 0;
}


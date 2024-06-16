#include "Book.hpp"

    // write and document all methods in this file.
    Book::Book()
    {
        title_ = "";
        author_ = "";
        ISBN_ = 0;
        icon_ = nullptr;
        price_ = 0.00;
        keywords_;
        blurb_ = "";
    }

    Book::~Book() // Destructor deleting everything
    {
        delete[] icon_;
        icon_ = nullptr;
    }

    Book::Book(const Book& rhs) // copy constructor
    {
        title_ = rhs.title_;
        author_ = rhs.author_;
        ISBN_ = rhs.ISBN_;
        price_ = rhs.price_;
        keywords_ = rhs.keywords_;
        blurb_ = rhs.blurb_;

        if (rhs.icon_) { // if it is pointing to a nullptr
            icon_ = new int[80];
            for (int i = 0; i < 80; i++) { // if it isn't pointing to nullptr, it will set each of the icon index to the rhs icon
                icon_[i] = rhs.icon_[i];
            }
        } else {
            icon_ = nullptr;
        }
    }

    Book& Book::operator=(const Book& rhs) // L value bc of & (copy assignment operator)
    {
        if (this != &rhs) {
            title_ = rhs.title_;
            author_ = rhs.author_;
            ISBN_ = rhs.ISBN_;
            price_ = rhs.price_;
            keywords_ = rhs.keywords_;
            blurb_ = rhs.blurb_;
        
         if (rhs.icon_) {
            icon_ = new int[80];
            for (int i = 0; i < 80; i++) {
                icon_[i] = rhs.icon_[i];
            }
        } else {
            icon_ = nullptr;
            }
        }
        return *this;
    }

    Book::Book(Book&& rhs) // move constructor
    {
        title_ = std::move(rhs.title_);
        author_= std::move(rhs.author_);
        ISBN_ = rhs.ISBN_; // primitive data type doesn't need moving
        //delete[] icon_; // deletes the icon pointer pointing to some place in memory so whatever the information it has no longer exists
        icon_= rhs.icon_;
        rhs.icon_ = nullptr; // sets the icon to nullptr right after we move the book
        price_ = rhs.price_;
        keywords_ = std::move(rhs.keywords_);
        blurb_ = std::move(rhs.blurb_);
    }

    Book& Book::operator=(Book&& rhs) // && r value (move assignemnt operator)
    {
        if(this != &rhs) {
            title_ = std::move(rhs.title_);
            author_ = std::move(rhs.author_);
            ISBN_ = rhs.ISBN_;
            //delete[] icon_;
            icon_ = rhs.icon_;
            rhs.icon_ = nullptr;
            price_ = rhs.price_;
            keywords_ = std::move(rhs.keywords_);
            blurb_ = std::move(rhs.blurb_);
        }
        return *this;
    }

    const std::string& Book::getTitle() const // returns the value of title_
    {
        return title_;
    }

    void Book::setTitle(const std::string& title) // stores whatever the input was to title_
    {
        title_ = title;
    }

    const std::string& Book::getAuthor() const // returns the value of author_
    {
        return author_;
    }

    void Book::setAuthor(const std::string& author) // stores whatever the input was to author_
    {
        author_ = author;
    }

    long long int Book::getISBN() const // returns the value of ISBN_
    {
        return ISBN_;
    }

    void Book::setISBN(long long int ISBN) // stores whatever the input was to ISBN_
    {
        ISBN_ = ISBN;
    }

    const int* Book::getIcon() const // returns the value of icon_
    {
        return icon_;
    }

    void Book::setIcon(int* icon) // stores whatever the input was to icon_
    {
        icon_ = icon;
    }

    float Book::getPrice() const // returns the value of price_
    {
        return price_;
    }

    void Book::setPrice(float price) // stores whatever the input was to price_
    {
        price_ = price;
    }

    const std::vector<std::string>& Book::getKeywords() const // returns the value of keywords_
    {
        return keywords_;
    }

    void Book::setKeywords(const std::vector<std::string>& keywords) // stores whatever the input was to keywords_
    {
        keywords_ = keywords;
    }

    const std::string& Book::getBlurb() const // returns the value of blurb_
    {
        return blurb_;
    }

    void Book::setBlurb(const std::string& blurb) // stores whatever the input was to blurb_
    {
        blurb_ = blurb;
    }

    void Book::print() const // prints their values out
    {
        std::cout << "Title: " << getTitle() << std::endl;
        std::cout << "Author: " << getAuthor() << std::endl;
        std::cout << "ISBN: " << getISBN() << std::endl;

        std::cout << "Icon: ";
        for (int i = 0; i < 80; i++) {
            std::cout << icon_[i] << " ";
        }
        std::cout << std::endl;

        std::cout << "Price: " << "$" << std::fixed << std::setprecision(2) << getPrice() << std::endl; // fixes the precision of the price to two decimals

        std::cout << "Keywords: ";
        for (int i = 0; i < keywords_.size(); i++) {
            std::cout << keywords_[i];
            if (i < keywords_.size() -1) {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;

        std::cout << "Blurb: " << getBlurb() << std::endl;

        
    }
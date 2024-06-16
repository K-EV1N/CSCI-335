#include "MoveAll.hpp"
#include "Book.hpp"

// Moves all Books in "source" with the specified keyword to "dest".
// A Book is moved if any of its keywords match the one specified in this function.
// Use iterators whenever appropriate.
// Hint: you need a const iterator for a const vector, but this will be automatically handled using "auto".

void moveAll (const std::string keyword, std::vector<Book> &source, std::vector<Book> &dest){
  const auto t1_start = std::chrono::steady_clock::now();
  int books_moved=0; // counts books moved
  // DO NOT ALTER ABOVE HERE

  for (std::vector<Book>::iterator it = source.begin(); it != source.end(); it++) { // loops through the source
    const auto &book = *it;
    bool temp = false; // tracker variable for if the keyword is found
    for (int i = 0; i < book.getKeywords().size(); i++) {
      if (book.getKeywords()[i] == keyword) { // if the each book matches the keywords...
        temp = true; // flip the temp variable to true
      }
    }
    if (temp) { 
      dest.push_back(std::move(*it)); // move the book with the correct keyword to dest vector
      it = source.erase(it); // erase the previous element pointing to the book and moves on to the next element
      it--; 
      books_moved++; // increment books_moved
    }
  }
  
    // DO NOT ALTER BELOW HERE
  const auto t1_end = std::chrono::steady_clock::now();
  int t1 = std::chrono::duration <double, std::micro> (t1_end - t1_start).count();
  std::cout << "Moved " << books_moved << " books in " << t1 << " microseconds." << std::endl;
}
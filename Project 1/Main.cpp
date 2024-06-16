#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <sstream>
#include "Book.hpp"
#include "MoveAll.hpp"

int main(){
  
  std::vector<Book> catalog, cart;

  // open file
  std::string filename = "1000bookInputFile.txt";
  std::ifstream fin(filename);

  // define expected format
  std::regex title("(Title: )(.*)");
  std::regex author("(Author: )(.*)");
  std::regex ISBN("(ISBN: )(.*)");
  std::regex icon("(Icon: )(.*)");
  std::regex price("(Price: \\$)(.*)");
  std::regex keywords("(Keywords: )(.*)");
  std::regex blurb("(Blurb: )(.*)");

  // declare helper variables for reading from file
  std::string line;
  std::smatch match;
  Book temp;

  // reads all 7 fields in each iteration and copies the value of each field into Book "temp"
  // pushes "temp" onto the back of "catalog" at the end of the iteration
  while (getline(fin,line)){

    // Title
    if (!std::regex_search(line, match, title)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setTitle(match[2]);

    // Author
    getline(fin,line);
    if (!std::regex_search(line, match, author)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setAuthor(match[2]);

    // ISBN
    getline(fin,line);
    if (!std::regex_search(line, match, ISBN)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setISBN(std::stoll(match[2]));

    // Icon
    getline(fin,line);
    if (!std::regex_search(line, match, icon)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    std::stringstream numstring(match[2]);
    int next_number;
    int* numarray = new int[80];
    for (int i=0 ; i<80; ++i){
      if (!(numstring >> next_number))
        std::cout << "Error reading file format" << std::endl;
      numarray[i] = next_number;
    }
    temp.setIcon(numarray);
    numarray = nullptr;

    // Price
    getline(fin,line);
    if (!std::regex_search(line, match, price)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setPrice(std::stof(match[2]));

    // Keywords
    getline(fin,line);
    if (!std::regex_search(line, match, keywords)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    std::stringstream keyword_string(match[2]);
    std::vector<std::string> keywords;
    while (keyword_string){
      std::string keyword;
      if (!getline(keyword_string >> std::ws, keyword, ',' )) break;
      keywords.push_back(keyword);
    }
    temp.setKeywords(keywords);

    // Blurb
    getline(fin,line);
    if (!std::regex_search(line, match, blurb)){
      std::cout << "Error reading file format" << std::endl;
      exit(1);
    }
    temp.setBlurb(match[2]);

    getline(fin,line);  // skip line between entries
    catalog.push_back(temp);

  }

  // write your test cases here
  // moveAll("name", catalog, cart);
  // Book test;
  // test.setTitle("Seikou.");
  // test.setAuthor("Hildred Billings");
  // test.setISBN(8080124750);
  // test.setIcon(155 198 103 166 240 32 127 245 94 139 114 62 234 184 86 203 124 99 47 204 191 233 116 198 175 72 167 248 81 20 0 113 29 42 92 131 118 99 166 154 170 54 48 100 89 49 127 34 32 27 122 38 88 82 26 78 136 219 157 134 118 140 48 184 133 212 194 198 166 246 153 24 220 173 223 24 231 199 83 14);
  // test.setPrice(30.07);
  // test.setKeywords("Spanish Literature", "Magical Realism", "Romanian Literature");
  // test.setBlurb("For over twenty years Reina has sexually celebrated the women around her with a reverence only tolerated by her wife, Aiko. But when Reina misinterprets the fluidity of their open relationship, she's backed into a corner where her gender dysphoria reigns supreme. In order to salvage her marriage, she may have to reanalyze the way she views the world, her life, and her experiences.,Just when she thinks she's figured her spouse out, Aiko faces an unexpected transgression. Can she forgive her? Or will love finally give way to the fatigue that accompanies being with someone like Reina? A sick mother and unsympathetic sister are not helping Aiko's dilemma.,Even the most passionate relationships sometimes fall asunder to seikou, the sexual character at the core of one's identity. Will Reina and Aiko reunite with stronger hearts, or is it finally time to go their separate ways? And if they do split up, who will help them pick up the pieces - the stoic therapist, the desperate socialite, or the young couple who initiated this mess to begin with?");

  // std::cout << "Title: " << test.getTitle() << std::endl;
  // std::cout << "Author: " << test.getAuthor() << std::endl;
  // std::cout << "ISBN: " << test.getISBN() << std::endl;
  // std::cout << "Icon: " << test.getIcon() << std::endl;
  // std::cout << "Price: " << test.getPrice() << std::endl;
  // std::cout << "Keywords: " << test.getKeywords() << std::endl;
  // std::cout << "Blurb: " << test.getBlurb() << std::endl;

  for (const Book& Book2 : catalog) {
    Book2.print();
  }
  





  return 0;
}
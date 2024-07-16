#include "PhoneBook.hpp"

#include <iostream>

using std::cin;
using std::cout;

void PhoneBook::loop(void) {
  string cmd;

  while (true) {
    cout << "Enter command: ";
    cin >> cmd;
    if (cmd == "ADD")
      cout << "Need to add";
    else if (cmd == "SEARCH")
      cout << "Need to search";
    else if (cmd == "EXIT")
      break;
    else
      cout << "Invalid command";
    cout << std::endl;
  }
}

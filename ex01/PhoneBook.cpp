#include "PhoneBook.hpp"

void PhoneBook::run(void) {
  std::string cmd;

  while (true) {
    std::cout << "Enter command: ";
    std::cin >> cmd;
    if (!cmd.compare("ADD"))
      std::cout << "Need to add";
    else if (!cmd.compare("SEARCH"))
      std::cout << "Need to search";
    else if (!cmd.compare("EXIT"))
      break;
    else
      std::cout << "Invalid command";
    std::cout << std::endl;
  }
}

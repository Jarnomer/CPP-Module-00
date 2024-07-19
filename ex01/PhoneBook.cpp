#include "PhoneBook.hpp"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void PhoneBook::search_contact(void) {
  for (int i = 0; i < MAX_CONTACTS; i++) {
    cout << this->contacts[i].get_first_name();
    cout << this->contacts[i].get_last_name();
    cout << this->contacts[i].get_nick_name();
    cout << this->contacts[i].get_phone_number();
    cout << this->contacts[i].get_darkest_secret();
  }
}

static bool ft_is_all_digits(string str) {
  for (char c : str)
    if (!std::isdigit(c))
      return (false);
  return (true);
}

static string get_number(string str) {
  string input;

  while (true) {
    cout << "Enter " << str << ": ";
    getline(cin, input);
    if (cin.eof()) {
      exit(EXIT_FAILURE);
    } else if (input.empty()) {
      cout << "Input can't be empty" << endl;
      continue;
    } else if (!ft_is_all_digits(input)) {
      cout << "Input must be all digits" << endl;
      continue;
    }
    return input;
  }
}

static string get_input(string str) {
  string input;

  while (true) {
    cout << "Enter " << str << ": ";
    getline(cin, input);
    if (cin.eof()) {
      exit(EXIT_FAILURE);
    } else if (input.empty()) {
      cout << "Input can't be empty" << endl;
      continue;
    }
    return input;
  }
}

void PhoneBook::add_contact() {
  static int i = 0;

  this->contacts[i].set_first_name(get_input("first name"));
  this->contacts[i].set_last_name(get_input("last name"));
  this->contacts[i].set_nick_name(get_input("nick name"));
  this->contacts[i].set_phone_number(get_number("phone number"));
  this->contacts[i].set_darkest_secret(get_input("darkest secret"));
  i = (i + 1) % MAX_CONTACTS;
}

void PhoneBook::loop(void) {
  PhoneBook pb;
  string command;

  while (true) {
    cout << "Enter command: ";
    getline(cin, command);
    if (cin.eof()) {
      exit(EXIT_FAILURE);
    } else if (command == "EXIT") {
      exit(EXIT_SUCCESS);
    } else if (command.empty()) {
      continue;
    } else if (command == "ADD")
      pb.add_contact();
    else if (command == "SEARCH")
      pb.search_contact();
    else
      cout << "Invalid command";
    cout << endl;
  }
}

#include "PhoneBook.hpp"

static bool ft_valid_index(string str) {
  if (str.length() > 1) {
    return false;
  } else if (str == "8" || str == "9") {
    return false;
  }
  return true;
}

static bool ft_all_digits(string str) {
  for (char c : str)
    if (!std::isdigit(c))
      return (false);
  return (true);
}

static bool ft_empty_input(string str) {
  if (str.empty())
    return (true);
  for (char c : str)
    if (std::isprint(c) && !std::isspace(c))
      return (false);
  return (true);
}

static string get_input(string str) {
  string input;

  while (true) {
    cout << "Enter " << str << ": ";
    getline(cin, input);
    if (cin.eof()) {
      exit(EXIT_FAILURE);
    } else if (ft_empty_input(input)) {
      cout << ERR_EMPTY << endl;
      continue;
    }
    return input;
  }
}

static string get_number(string str) {
  string input;

  while (true) {
    input = get_input(str);
    if (!ft_all_digits(input)) {
      cout << ERR_DIGIT << endl;
      continue;
    }
    return input;
  }
}

static string get_index(string str) {
  string input;

  while (true) {
    input = get_number(str);
    if (!ft_valid_index(input)) {
      cout << ERR_RANGE << endl;
      continue;
    }
    return input;
  }
}

static void print_header(void) {
  cout << "|" << std::right << std::setw(10) << "INDEX" ;
  cout << "|" << std::right << std::setw(10) << "FORENAME";
  cout << "|" << std::right << std::setw(10) << "LAST NAME";
  cout << "|" << std::right << std::setw(10) << "NICKNAME";
  cout << "|" << endl;
}

void PhoneBook::search_contact(void) {
  string input;
  int i;

  print_header();
  for (int i = 0; i < MAX_CONTACTS; i++) {
    this->contacts[i].contact_name_info(i);
  }
  input = get_index("index");
  i = input[0] - '0';
  this->contacts[i].contact_full_info();
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
    } else if (ft_empty_input(command)) {
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

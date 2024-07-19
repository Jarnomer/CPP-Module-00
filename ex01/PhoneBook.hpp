#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook {
private:
  Contact contacts[8];

public:
  static void loop(void);
  void add_contact();
  void search_contact();
};

#endif

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

#define MAX_CONTACTS 8

#define ERR_EMPTY "Input can't be empty"
#define ERR_DIGIT "Input must be all digits"
#define ERR_RANGE "Input is out of range"

class PhoneBook {
private:
  Contact contacts[8];

public:
  static void loop(void);
  void add_contact(void);
  void search_contact(void);
};

#endif

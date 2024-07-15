#ifdef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
  static const int max = 8;
  Contact contacts[max];

public:
  static void run(void);
};

#endif

#ifdef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook {
private:
  const int max = 8;
  Contact contacts[max];

public:
  void loop(void);
};

#endif

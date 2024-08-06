#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Contact {
private:
  string first_name;
  string last_name;
  string nick_name;
  string phone_number;
  string darkest_secret;

public:
  string get_first_name(void);
  string get_last_name(void);
  string get_nick_name(void);
  string get_phone_number(void);
  string get_darkest_secret(void);
  void set_first_name(string str);
  void set_last_name(string str);
  void set_nick_name(string str);
  void set_phone_number(string str);
  void set_darkest_secret(string str);
  void contact_name_info(int index);
  void contact_full_info(void);
};

#endif

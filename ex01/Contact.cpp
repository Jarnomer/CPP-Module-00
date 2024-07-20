#include "Contact.hpp"

string Contact::get_first_name(void) { return this->first_name; }
string Contact::get_last_name(void) { return this->last_name; }
string Contact::get_nick_name(void) { return this->nick_name; }
string Contact::get_phone_number(void) { return this->phone_number; }
string Contact::get_darkest_secret(void) { return this->darkest_secret; }

void Contact::set_first_name(string str) { this->first_name = str; }
void Contact::set_last_name(string str) { this->last_name = str; }
void Contact::set_nick_name(string str) { this->nick_name = str; }
void Contact::set_phone_number(string str) { this->phone_number = str; }
void Contact::set_darkest_secret(string str) { this->darkest_secret = str; }

static string limit_output(string str) {
  if (str.length() > 10)
    return str.substr(0, 9) + ".";
  return str;
}

void Contact::contact_name_info(int index) {
  cout << "|" << std::right << std::setw(10) << index;
  cout << "|" << std::right << std::setw(10)
       << limit_output(this->get_first_name());
  cout << "|" << std::right << std::setw(10)
       << limit_output(this->get_last_name());
  cout << "|" << std::right << std::setw(10)
       << limit_output(this->get_nick_name());
  cout << "|" << endl;
}

void Contact::contact_full_info(void) {
  cout << "First Name: " << this->get_first_name() << endl;
  cout << "Last Name: " << this->get_last_name() << endl;
  cout << "Nick Name: " << this->get_nick_name() << endl;
  cout << "Phone Number: " << this->get_phone_number() << endl;
  cout << "Darkest Secret: " << this->get_darkest_secret() << endl;
}

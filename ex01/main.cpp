#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

class contact {
public:
  string first_name;
  string last_name;
  string nick_name;
  string phone_number;
  bool is_empty;
  int index;

  void set_darkest_secret(string new_secret) { darkest_secret = new_secret; }
  string get_darkest_secret(void) { return darkest_secret; }

private:
  string darkest_secret;
};

int main(void) {
  string cmd;

  while (true) {
    cout << "Enter command: ";
    cin >> cmd;
    if (!cmd.compare("ADD"))
      cout << "Need to add";
    else if (!cmd.compare("SEARCH"))
      cout << "Need to search";
    else if (!cmd.compare("EXIT"))
      break;
    else
      cout << "Invalid command";
	cout << std::endl;
  }
  return 0;
}

#include <iostream>

using std::cout;
using std::endl;
using std::string;

string ft_to_upper(string str) {
  for (int i = 0; i < (int)str.length(); i++) {
    str[i] = toupper(str[i]);
  }
  return (str);
}

int main(int argc, char **argv) {
  if (argc == 1) {
    cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    for (int i = 1; i < argc; i++) {
      cout << ft_to_upper(argv[i]);
    }
  }
  cout << endl;
  return 0;
}

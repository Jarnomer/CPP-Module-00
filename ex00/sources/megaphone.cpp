#include <algorithm>
#include <iostream>

int main(int argc, char **argv) {
  std::string str;
  int i = 0;

  if (argc == 1) {
    std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
  } else {
    while (++i < argc) {
      str = argv[i];
      std::transform(str.begin(), str.end(), str.begin(), ::toupper);
      std::cout << str;
    }
  }
  std::cout << std::endl;
  return 0;
}

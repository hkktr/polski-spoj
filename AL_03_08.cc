// C++14 (gcc 8.3)
#include <iostream>

int main() {
  int second_highest_value{-1};
  int highest_value{-1};
  int present_value;
  while (true) {
    std::cin >> present_value;
    if (present_value == 0) break;

    if (present_value > highest_value) {
      second_highest_value = highest_value;
      highest_value = present_value;
    } else if (present_value != highest_value &&
               present_value > second_highest_value) {
      second_highest_value = present_value;
    }
  }

  if (second_highest_value == -1) {
    std::cout << highest_value;
  } else {
    std::cout << second_highest_value;
  }

  return 0;
}
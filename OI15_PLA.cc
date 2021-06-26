// C++14 (gcc 8.3)
#include <iostream>
#include <stack>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;

  std::stack<int> stack;
  int result{0};
  while (--n >= 0) {
    int width, height;
    std::cin >> width >> height;

    while (!stack.empty() && stack.top() > height) stack.pop();
    if (stack.empty() || stack.top() < height) {
      ++result;
      stack.push(height);
    }
  }

  std::cout << result << "\n";

  return 0;
}
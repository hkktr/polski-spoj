// C++14 (gcc 8.3)
#include <csignal>

int main() {
  std::raise(SIGALRM);

  return 0;
}
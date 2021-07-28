// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>
#include <limits>
#include <vector>

constexpr int kG{1'000};

long long CalculateTreeHeight(long long height, int max_velocity) {
  return static_cast<long long>(std::pow(max_velocity, 2)) / (2 * kG) + height;
}

class Resident {
 public:
  Resident(int height, int age, int growth_quotient)
      : height_{height}, age_{age}, growth_quotient_{growth_quotient} {}

  long long GetTreeHeight(int year, int max_velocity) const {
    return CalculateTreeHeight(GetHeight(year), max_velocity);
  }

 private:
  int height_;
  int age_;
  int growth_quotient_;

  long long GetHeight(int year) const {
    if (age_ < 20) {
      const int growth_years{std::min(year, 20 - age_)};
      return static_cast<long long>(height_) +
             growth_years * static_cast<long long>(growth_quotient_);
    } else {
      return height_;
    }
  }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int t;
  std::cin >> t;

  while (--t >= 0) {
    int max_velocity, n;
    std::cin >> max_velocity >> n;

    max_velocity *= 100;
    std::vector<Resident> residents;
    residents.reserve(n);

    long long const_min_tree_height{std::numeric_limits<long long>::max()};
    long long min_tree_height{std::numeric_limits<long long>::max()};

    while (--n >= 0) {
      int height, age, growth_quotient;
      std::cin >> height >> age >> growth_quotient;

      if (age >= 20) {
        const long long tree_height{CalculateTreeHeight(height, max_velocity)};
        if (tree_height < const_min_tree_height) {
          const_min_tree_height = tree_height;
          if (const_min_tree_height < min_tree_height) {
            min_tree_height = const_min_tree_height;
          }
        }
      } else {
        const Resident new_resident(height, age, growth_quotient);
        residents.push_back(new_resident);

        const long long tree_height{
            new_resident.GetTreeHeight(0, max_velocity)};
        if (tree_height < min_tree_height) {
          min_tree_height = tree_height;
        }
      }
    }
    std::cout << "0: " << min_tree_height << "\n";

    bool const_heights{false};
    for (int year{1}; year <= 20; ++year) {
      if (!const_heights) {
        min_tree_height = const_min_tree_height;
        for (const Resident& resident : residents) {
          const long long tree_height{
              resident.GetTreeHeight(year, max_velocity)};
          if (tree_height < min_tree_height) {
            min_tree_height = tree_height;
          }
        }

        if (min_tree_height == const_min_tree_height) {
          const_heights = true;
        }
        std::cout << year << ": " << min_tree_height << "\n";
      } else {
        std::cout << year << ": " << const_min_tree_height << "\n";
      }
    }
  }

  return 0;
}
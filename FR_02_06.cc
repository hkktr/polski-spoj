// C++14 (gcc 8.3)
#include <cmath>
#include <iostream>
#include <string>
#include <vector>

double CalculateBMI(int weight, int height) {
  return weight / std::pow(height / 100.0, 2);
}

int main() {
  int t;
  std::cin >> t;

  std::vector<std::string> underweight_people;
  std::vector<std::string> healthy_weight_people;
  std::vector<std::string> overweight_people;

  std::string person_name;
  int weight, height;
  while (--t >= 0) {
    std::cin >> person_name >> weight >> height;

    double bmi{CalculateBMI(weight, height)};
    if (bmi < 18.5) {
      underweight_people.push_back(person_name);
    } else if (bmi >= 18.5 && bmi < 25) {
      healthy_weight_people.push_back(person_name);
    } else if (bmi >= 25) {
      overweight_people.push_back(person_name);
    }
  }

  std::cout << "niedowaga\n";
  for (const std::string& name : underweight_people) {
    std::cout << name << "\n";
  }

  std::cout << "\nwartosc prawidlowa\n";
  for (const std::string& name : healthy_weight_people) {
    std::cout << name << "\n";
  }

  std::cout << "\nnadwaga\n";
  for (const std::string& name : overweight_people) {
    std::cout << name << "\n";
  }

  return 0;
}
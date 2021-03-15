// C++ (gcc 8.3)
#include <iostream>
#include <string>

class Time {
 public:
  Time(const std::string& string_time) {
    hours_ = std::stoi(string_time.substr(0, 2));
    minutes_ = std::stoi(string_time.substr(3, 2));
  }

  void AddMinutes(int minutes) {
    minutes_ += minutes;
    hours_ += minutes_ / 60;
    hours_ %= 24;
    minutes_ %= 60;
  }

  friend std::ostream& operator<<(std::ostream& out, const Time& time) {
    std::string result;
    result.reserve(5);

    result += std::to_string(time.hours_);
    result.insert(0, 2 - result.size(), '0');
    result += ":";
    result += std::to_string(time.minutes_);
    result.insert(3, 5 - result.size(), '0');

    out << result;
    return out;
  }

 private:
  int hours_;
  int minutes_;
};

int main() {
  std::string start_time;
  std::cin >> start_time;

  std::cout << start_time;
  Time time(start_time);

  constexpr int lesson_duration{45};
  int break_duration;
  while (std::cin >> break_duration) {
    time.AddMinutes(lesson_duration);
    std::cout << "," << time;

    time.AddMinutes(break_duration);
    std::cout << "," << time;
  }
  time.AddMinutes(lesson_duration);
  std::cout << "," << time;

  return 0;
}
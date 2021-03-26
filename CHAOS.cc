// C++14 (gcc 8.3)
#include <iostream>
#include <string>

class Time {
 public:
  Time(const std::string& string_time) {
    hours_ = std::stoi(string_time.substr(0, 2));
    minutes_ = std::stoi(string_time.substr(3, 2));
  }

  void MakePalindromic() {
    if (hours_ == 0) {
      if (minutes_ < 9) {
        ++minutes_;
      } else if (minutes_ < 55) {
        minutes_ = minutes_ / 11 * 11 + 11;
      } else {
        hours_ = 1;
        minutes_ = 1;
      }
    } else if (hours_ <= 9) {
      if (minutes_ < hours_) {
        minutes_ = hours_;
      } else if (minutes_ < hours_) {
        minutes_ = hours_;
      } else if (minutes_ < 50 + hours_) {
        const int digit{minutes_ % 10};
        if (digit < hours_) {
          minutes_ = minutes_ / 10 * 10 + hours_;
        } else if (digit == hours_) {
          minutes_ += 10;
        } else if (digit > hours_) {
          minutes_ = minutes_ / 10 * 10 + 10 + hours_;
        }
      } else {
        ++hours_;
        if (hours_ <= 9) {
          minutes_ = hours_;
        } else {
          minutes_ = 1;
        }
      }
    } else if (hours_ <= 23) {
      const int reversed_hours{Reversed(hours_)};
      if (reversed_hours < 60 && reversed_hours > minutes_) {
        minutes_ = reversed_hours;
      } else {
        if (Reversed(hours_ + 1) >= 60) {
          hours_ = 20;
          minutes_ = 2;
        } else if (hours_ <= 22) {
          ++hours_;
          minutes_ = Reversed(hours_);
        } else {
          hours_ = 0;
          minutes_ = 0;
        }
      }
    }
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
  int Reversed(int number) const { return number % 10 * 10 + number / 10; }

  int hours_;
  int minutes_;
};

int main() {
  int n;
  std::cin >> n;

  std::string string_time;
  string_time.reserve(5);
  while (--n >= 0) {
    std::cin >> string_time;
    Time time(string_time);
    time.MakePalindromic();
    std::cout << time << "\n";
  }

  return 0;
}
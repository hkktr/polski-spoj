// C++ (gcc 8.3)
#include <array>
#include <iostream>

template <typename T>
class Fraction {
 public:
  Fraction() : numerator_{0}, denominator_{1} {}
  Fraction(const T& numerator, const T& denominator)
      : numerator_{numerator}, denominator_{denominator} {
    Simplify();
  }
  Fraction(const std::pair<T, T>& value)
      : Fraction(value.first, value.second) {}
  Fraction(const T& value) : Fraction(value, T(1)) {}
  Fraction(const Fraction& other) { *this = other; }

  Fraction& operator=(const std::pair<T, T>& value) {
    numerator_ = value.first;
    denominator_ = value.second;
    Simplify();
    return *this;
  }
  Fraction& operator=(const T& value) {
    numerator_ = value;
    denominator_ = T(1);
    return *this;
  }
  Fraction& operator=(const Fraction& other) {
    numerator_ = other.numerator_;
    denominator_ = other.denominator_;
    return *this;
  }

  Fraction operator+() const { return *this; }
  Fraction operator-() const {
    Fraction result{*this};
    result.numerator_ = -numerator_;
    return result;
  }

  Fraction operator+(const Fraction& other) const {
    const T new_denominator{LCM(denominator_, other.denominator_)};
    const T multiplier{new_denominator / denominator_};
    const T other_multiplier{new_denominator / other.denominator_};
    const T new_numerator{numerator_ * multiplier +
                          other.numerator_ * other_multiplier};
    return Fraction(new_numerator, new_denominator);
  }
  Fraction operator-(const Fraction& other) const {
    const T new_denominator{LCM(denominator_, other.denominator_)};
    const T multiplier{new_denominator / denominator_};
    const T other_multiplier{new_denominator / other.denominator_};
    const T new_numerator{numerator_ * multiplier -
                          other.numerator_ * other_multiplier};
    return Fraction(new_numerator, new_denominator);
  }
  Fraction operator*(const Fraction& other) const {
    return Fraction(numerator_ * other.numerator_,
                    denominator_ * other.denominator_);
  }
  Fraction operator/(const Fraction& other) const {
    return *this * Fraction(other.denominator_, other.numerator_);
  }

  Fraction operator+=(const Fraction& other) { return (*this = *this + other); }
  Fraction operator-=(const Fraction& other) { return (*this = *this - other); }
  Fraction operator*=(const Fraction& other) { return (*this = *this * other); }
  Fraction operator/=(const Fraction& other) { return (*this = *this / other); }

  bool operator<(const Fraction& other) const {
    const T new_denominator{LCM(denominator_, other.denominator_)};
    const T multiplier{new_denominator / denominator_};
    const T other_multiplier{new_denominator / other.denominator_};
    const T new_numerator{numerator_ * multiplier};
    const T new_other_numerator{other.numerator_ * other_multiplier};

    return new_numerator < new_other_numerator;
  }
  bool operator>(const Fraction& other) const { return other < *this; }
  bool operator<=(const Fraction& other) const { return !(other < *this); }
  bool operator>=(const Fraction& other) const { return !(*this < other); }
  bool operator==(const Fraction& other) const {
    return numerator_ == other.numerator_ && denominator_ == other.denominator_;
  }
  bool operator!=(const Fraction& other) const {
    return numerator_ != other.numerator_ || denominator_ != other.denominator_;
  }

  friend std::istream& operator>>(std::istream& in, Fraction& fraction) {
    in >> fraction.numerator_;
    in.ignore(1, '/');
    in >> fraction.denominator_;
    fraction.Simplify();
    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction) {
    out << fraction.numerator_ << "/" << fraction.denominator_;
    return out;
  }

  const T& Numerator() const { return numerator_; }
  const T& Denominator() const { return denominator_; }

  void SetNumerator(const T& numerator) {
    numerator_ = numerator;
    Simplify();
  }
  void SetDenominator(const T& denominator) {
    denominator_ = denominator;
    Simplify();
  }

 private:
  void Simplify() {
    if (numerator_ != 0) {
      const T divisor{GCD(numerator_, denominator_)};
      numerator_ /= divisor;
      denominator_ /= divisor;
    }
  }

  T GCD(T a, T b) const {
    while (b != 0) {
      const T temp{b};
      b = a % b;
      a = temp;
    }
    return a;
  }

  T LCM(T a, T b) const { return a / GCD(a, b) * b; }

  T numerator_;
  T denominator_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  using Fraction = Fraction<unsigned long long>;

  int t;
  std::cin >> t;

  while (--t >= 0) {
    std::array<Fraction, 3> triangle;
    for (Fraction& side : triangle) {
      std::cin >> side;
    }

    Fraction difference;
    if (triangle[1] >= triangle[2]) {
      difference = triangle[1] - triangle[2];
    } else {
      difference = triangle[2] - triangle[1];
    }

    if (triangle[0] < triangle[1] + triangle[2] && triangle[0] > difference) {
      std::cout << "TAK\n";
    } else {
      std::cout << "NIE\n";
    }
  }

  return 0;
}
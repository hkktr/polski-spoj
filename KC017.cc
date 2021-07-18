// C++14 (gcc 8.3)
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

class BigInt {
 public:
  BigInt() : sign_{1} {}
  BigInt(const BigInt& other) { *this = other; }
  BigInt(BigInt&& other) noexcept {
    sign_ = other.sign_;
    value_.swap(other.value_);
  }
  BigInt(long long value) { *this = value; }
  BigInt(const std::string& string) { ReadString(string); }

  BigInt& operator=(const BigInt& other) {
    sign_ = other.sign_;
    value_ = other.value_;
    return *this;
  }
  BigInt& operator=(BigInt&& other) noexcept {
    sign_ = other.sign_;
    value_.swap(other.value_);
    return *this;
  }
  BigInt& operator=(long long value) {
    if (value < 0) {
      sign_ = -1;
      value = -value;
    } else {
      sign_ = 1;
    }

    value_.clear();
    while (value > 0) {
      value_.push_back(value % kBase);
      value /= kBase;
    }

    return *this;
  }
  BigInt& operator=(const std::string& string) {
    ReadString(string);
    return *this;
  }

  BigInt operator+() const { return *this; }
  BigInt operator-() const {
    BigInt result(*this);
    result.sign_ = -sign_;
    return result;
  };

  BigInt operator+(const BigInt& other) const {
    if (sign_ == other.sign_) {
      BigInt result(other);

      for (int i{0}, carry{0};
           i < static_cast<int>(std::max(value_.size(), other.value_.size())) ||
           carry;
           ++i) {
        if (i == static_cast<int>(result.value_.size())) {
          result.value_.push_back(0);
        }
        result.value_[i] +=
            carry + (i < static_cast<int>(value_.size()) ? value_[i] : 0);
        carry = result.value_[i] >= kBase;
        if (carry) result.value_[i] -= kBase;
      }

      return result;
    }
    return *this - (-other);
  }
  BigInt operator-(const BigInt& other) const {
    if (sign_ == other.sign_) {
      if (Abs() >= other.Abs()) {
        BigInt result(*this);
        for (int i{0}, carry{0};
             i < static_cast<int>(other.value_.size()) || carry; ++i) {
          result.value_[i] -=
              carry +
              (i < static_cast<int>(other.value_.size()) ? other.value_[i] : 0);
          carry = result.value_[i] < 0;
          if (carry) result.value_[i] += kBase;
        }

        result.TrimLeadingZeroes();
        return result;
      }
      return -(other - *this);
    }
    return *this + (-other);
  }
  BigInt operator*(const BigInt& other) const {
    std::vector<int> a6{ConvertBase(value_, kBaseDigits, 6)};
    std::vector<int> b6{ConvertBase(other.value_, kBaseDigits, 6)};
    std::vector<long long> a(a6.begin(), a6.end());
    std::vector<long long> b(b6.begin(), b6.end());

    while (a.size() < b.size()) a.push_back(0);
    while (b.size() < a.size()) b.push_back(0);
    while (a.size() & (a.size() - 1)) {
      a.push_back(0);
      b.push_back(0);
    }

    const std::vector<long long> result_value{KaratsubaMultiply(a, b)};
    BigInt result;
    result.sign_ = sign_ * other.sign_;

    for (int i{0}, carry{0}; i < static_cast<int>(result_value.size()); ++i) {
      const long long current{result_value[i] + carry};
      result.value_.push_back(static_cast<int>(current % 1'000'000));
      carry = static_cast<int>(current / 1'000'000);
    }

    result.value_ = ConvertBase(result.value_, 6, kBaseDigits);
    result.TrimLeadingZeroes();

    return result;
  }
  BigInt operator/(const BigInt& other) const {
    return DivisionModulo(other).first;
  }
  BigInt operator/(int value) const {
    BigInt result(*this);

    if (value < 0) {
      result.sign_ = -result.sign_;
      value = -value;
    }

    for (int i{static_cast<int>(result.value_.size() - 1)}, remainder{0};
         i >= 0; --i) {
      const long long current{result.value_[i] +
                              remainder * static_cast<long long>(kBase)};
      result.value_[i] = static_cast<int>(current / value);
      remainder = static_cast<int>(current % value);
    }

    result.TrimLeadingZeroes();
    return result;
  }
  BigInt operator%(const BigInt& other) const {
    return DivisionModulo(other).second;
  }

  BigInt& operator+=(const BigInt& other) { return (*this = *this + other); }
  BigInt& operator-=(const BigInt& other) { return (*this = *this - other); }
  BigInt& operator*=(const BigInt& other) { return (*this = *this * other); }
  BigInt& operator/=(const BigInt& other) { return (*this = *this / other); }
  BigInt& operator/=(int value) { return (*this = *this / value); }
  BigInt& operator%=(const BigInt& other) { return (*this = *this % other); }

  BigInt& operator++() { return (*this = *this + 1); }
  BigInt& operator--() { return (*this = *this - 1); }
  BigInt operator++(int) {
    BigInt temp(*this);
    ++*this;
    return temp;
  }
  BigInt operator--(int) {
    BigInt temp(*this);
    --*this;
    return temp;
  }

  bool operator<(const BigInt& other) const {
    if (sign_ != other.sign_) return sign_ < other.sign_;
    if (value_.size() != other.value_.size()) {
      return value_.size() * sign_ < other.value_.size() * other.sign_;
    }
    for (int i{static_cast<int>(value_.size() - 1)}; i >= 0; --i) {
      if (value_[i] != other.value_[i]) {
        return value_[i] * sign_ < other.value_[i] * other.sign_;
      }
    }
    return false;
  }
  bool operator>(const BigInt& other) const { return other < *this; }
  bool operator<=(const BigInt& other) const { return !(other < *this); }
  bool operator>=(const BigInt& other) const { return !(*this < other); }
  bool operator==(const BigInt& other) const {
    return !(*this < other) && !(other < *this);
  }
  bool operator!=(const BigInt& other) const {
    return *this < other || other < *this;
  }

  friend std::istream& operator>>(std::istream& in, BigInt& big_int) {
    std::string string;
    in >> string;
    big_int = string;

    return in;
  }
  friend std::ostream& operator<<(std::ostream& out, const BigInt& big_int) {
    if (big_int.sign_ == -1) std::cout << "-";
    if (big_int.value_.empty()) {
      std::cout << "0";
    } else {
      out << big_int.value_.back();
      for (auto it{big_int.value_.rbegin() + 1}; it != big_int.value_.rend();
           ++it) {
        out << std::setw(big_int.kBaseDigits) << std::setfill('0') << *it;
      }
    }

    return out;
  }

  std::pair<BigInt, BigInt> DivisionModulo(const BigInt& other) const {
    const int norm{kBase / (other.value_.back() + 1)};
    BigInt a = Abs() * norm;
    BigInt b = other.Abs() * norm;

    BigInt quotient, remainder;
    quotient.value_.resize(a.value_.size());

    for (int i{static_cast<int>(a.value_.size() - 1)}; i >= 0; --i) {
      remainder *= kBase;
      remainder += a.value_[i];

      const int temp_a{remainder.value_.size() <= b.value_.size()
                           ? 0
                           : remainder.value_[b.value_.size()]};
      const int temp_b{remainder.value_.size() <= b.value_.size() - 1
                           ? 0
                           : remainder.value_[b.value_.size() - 1]};
      int divisor{(static_cast<long long>(kBase) * temp_a + temp_b) /
                  b.value_.back()};

      remainder -= b * divisor;
      while (remainder < 0) {
        remainder += b;
        --divisor;
      }
      quotient.value_[i] = divisor;
    }

    quotient.sign_ = sign_ * other.sign_;
    remainder.sign_ = sign_;
    quotient.TrimLeadingZeroes();
    remainder.TrimLeadingZeroes();

    return std::make_pair(quotient, remainder / norm);
  }

  BigInt Abs() const {
    BigInt result(*this);
    result.sign_ = 1;
    return result;
  }

 private:
  const int kBase{1'000'000'000};
  const int kBaseDigits{9};

  std::vector<int> ConvertBase(const std::vector<int>& vector,
                               int old_base_digits, int new_base_digits) const {
    std::vector<long long> bases(std::max(old_base_digits, new_base_digits) +
                                 1);
    bases[0] = 1;
    for (int i{1}; i < static_cast<int>(bases.size()); ++i)
      bases[i] = bases[i - 1] * 10;

    std::vector<int> result;
    long long current{0};
    int current_base_digits{0};

    for (int value : vector) {
      current += value * bases[current_base_digits];
      current_base_digits += old_base_digits;

      while (current_base_digits >= new_base_digits) {
        result.push_back(static_cast<int>(current % bases[new_base_digits]));
        current /= bases[new_base_digits];
        current_base_digits -= new_base_digits;
      }
    }
    result.push_back(static_cast<int>(current));

    while (!result.empty() && !result.back()) result.pop_back();
    return result;
  }

  std::vector<long long> KaratsubaMultiply(
      const std::vector<long long>& a, const std::vector<long long>& b) const {
    using vll_t = std::vector<long long>;

    const int n{static_cast<int>(a.size())};
    vll_t result(n + n);
    if (n <= 32) {
      for (int i{0}; i < n; ++i) {
        for (int j{0}; j < n; ++j) {
          result[i + j] += a[i] * b[j];
        }
      }
      return result;
    }

    const int k{n >> 1};
    vll_t a1(a.begin(), a.begin() + k);
    vll_t a2(a.begin() + k, a.end());
    vll_t b1(b.begin(), b.begin() + k);
    vll_t b2(b.begin() + k, b.end());

    vll_t a1b1{KaratsubaMultiply(a1, b1)};
    vll_t a2b2{KaratsubaMultiply(a2, b2)};

    for (int i{0}; i < k; ++i) a2[i] += a1[i];
    for (int i{0}; i < k; ++i) b2[i] += b1[i];

    vll_t temp{KaratsubaMultiply(a2, b2)};
    for (int i{0}; i < static_cast<int>(a1b1.size()); ++i) temp[i] -= a1b1[i];
    for (int i{0}; i < static_cast<int>(a2b2.size()); ++i) temp[i] -= a2b2[i];

    for (int i{0}; i < static_cast<int>(temp.size()); ++i)
      result[i + k] += temp[i];
    for (int i{0}; i < static_cast<int>(a1b1.size()); ++i) result[i] += a1b1[i];
    for (int i{0}; i < static_cast<int>(a2b2.size()); ++i)
      result[i + n] += a2b2[i];

    return result;
  }

  void ReadString(const std::string& string) {
    sign_ = 1;
    value_.clear();

    int position{0};
    while (position < static_cast<int>(string.size()) &&
           (string[position] == '-' || string[position] == '+')) {
      if (string[position] == '-') sign_ = -sign_;
      ++position;
    }

    for (int i{static_cast<int>(string.size()) - 1}; i >= position;
         i -= kBaseDigits) {
      int result{0};
      for (int j{std::max(position, i - kBaseDigits + 1)}; j <= i; ++j) {
        result *= 10;
        result += string[j] - '0';
      }
      value_.push_back(result);
    }

    TrimLeadingZeroes();
  }

  void TrimLeadingZeroes() {
    while (!value_.empty() && !value_.back()) value_.pop_back();
    if (value_.empty()) sign_ = 1;
  }

  int sign_;
  std::vector<int> value_;
};

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  BigInt a, b;
  while (std::cin >> a >> b) {
    std::cout << a - b << "\n";
  }

  return 0;
}
/*Copyright 2020 written by COS*/

/* errors
 * invalid initialization of reference of type ‘const string& 
 * {aka const std::__cxx11::basic_string<char>&}’ 
 * from expression of type ‘Tax’
 * 
 */

#include <inc/tax.h>

using std::iostream;
using std::ostream;
// basic constructor
/*Tax::Tax() {
  code_ = "";
  percent_ = 0.0;
  positive = true;
}*/

// initialization constructor percent must be positive
Tax::Tax(const std::string& code, double percent) : code_(code),
                                                    percent_(percent),
                                                    positive_(true) {
  if (percent < 0) {
    positive_ = false;
  }
  code_ = "";
  percent_ = 0.0;
}

double Tax::operator*(double rhs) const {
  // returns the tax instance percentage as a percent
  return percent();
}

double operator*(double lhs, const Tax& rhs) {
  return 0.0;
}

istream& operator>>(std::istream& lhs, Tax& rhs) {
  string store;
  *lhs >> store;
  return *lhs;
}

// error ‘std::ostream& Tax::operator<<(std::ostream&, const Tax&)’
// must take exactly one argument
// stackoverflow says add std infront of (ostream& lhs)
// didn't work

ostream& operator<<(std::ostream& lhs, const Tax& rhs) {
  lhs << code_ << ':' << percent();
  return lhs;
}

#include <stdio.h>
#include "array_utils.h"

int main(void) {
  ArrayUtil score_in_int;
  ArrayUtil score_in_float;
  ArrayUtil score_in_char;
  ArrayUtil score_in_double;
  int int_size = sizeof(int);
  int char_size = sizeof(char);
  int float_size = sizeof(float);
  int double_size = sizeof(double);
  score_in_int = create(int_size,LENGTH);
  score_in_float = create(float_size,LENGTH);
  score_in_char = create(char_size,LENGTH);
  score_in_double = create(double_size,LENGTH);
  assert_for_int(score_in_int);
  assert_for_float(score_in_float);
  assert_for_char(score_in_char);
  assert_for_double(score_in_double);

  return 0;
}

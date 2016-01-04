#include <stdio.h>
#include "array_utils.h"

int main(void) {
  // ArrayUtil score_in_int;
  // ArrayUtil score_in_int2;
  // ArrayUtil score_in_float;
  // ArrayUtil score_in_char;
  // ArrayUtil score_in_double;
  // int int_size = sizeof(int);
  // int char_size = sizeof(char);
  // int float_size = sizeof(float);
  // int double_size = sizeof(double);
  // score_in_int = create(int_size,LENGTH);
  // score_in_int2 = create(int_size,LENGTH);
  // score_in_float = create(float_size,LENGTH);
  // score_in_char = create(char_size,LENGTH);
  // score_in_double = create(double_size,LENGTH);
  assert_for_int();
  assert_for_long();
  assert_for_float();
  assert_for_char();
  assert_for_double();
  assert_for_areEqual();

  return 0;
}

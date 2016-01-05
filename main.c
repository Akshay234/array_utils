#include <stdio.h>
#include "array_utils.h"

int main(void) {
  assert_for_int();
  assert_for_long();
  assert_for_float();
  assert_for_char();
  assert_for_double();
  assert_for_areEqual();
  assert_for_resize();
  assert_for_findIndex();
  assert_for_findFirst();
  return 0;
}

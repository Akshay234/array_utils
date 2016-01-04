#include "array_utils.h"
#include "assert.h"

void assert_for_int(){
  ArrayUtil array_1 = create(4,10);
  assert(array_1.typeSize == 4);
  assert(array_1.length == 10);
  int *array = (int *)array_1.base;
  array[0] = 23;
  assert(array[0] == 23);
  free(array_1.base);
}

void assert_for_long(){
  ArrayUtil array_1 = create(8,6);
  assert(array_1.typeSize == 8);
  assert(array_1.length == 6);
  long *array = (long *)array_1.base;
  array[0] = 999999999999;
  assert(array[0] == 999999999999);
  free(array_1.base);
}

void assert_for_float(){
  ArrayUtil array_1 = create(4,8);
  assert(array_1.typeSize == 4);
  assert(array_1.length == 8);
  float *array = (float *)array_1.base;
  array[0] = 1.5;
  assert(array[0] == 1.5);
  free(array_1.base);

}

void assert_for_char(){
  ArrayUtil array_1 = create(1,7);
  assert(array_1.typeSize == 1);
  assert(array_1.length == 7);
  char *array = (char *)array_1.base;
  array[0] = 'A';
  assert(array[0] == 'A');
  free(array_1.base);

}

void assert_for_double(){
  ArrayUtil array_1 = create(8,20);
  assert(array_1.typeSize == 8);
  assert(array_1.length == 20);
  double *array = (double *)array_1.base;
  array[0] = 4294967296664598;
  array[1] = 123.456;
  assert(array[0] == 4294967296664598);
  assert(array[1] == 123.456);
  free(array_1.base);
}

void assert_for_areEqual(){
  ArrayUtil array_1 = create(4,10);
  ArrayUtil array_2 = create(4,10);
  int are_equal = areEqual(array_1,array_2);
  assert(are_equal = TRUE);
  free(array_1.base);
}

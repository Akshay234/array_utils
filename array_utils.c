#include <stdlib.h>
#include "array_utils.h"
#include "assert.h"
#include <stdio.h>



ArrayUtil create(int typeSize,int length){
  void *newArray = calloc(length,typeSize);
  ArrayUtil newUtil;
  newUtil.base = newArray;
  newUtil.typeSize = typeSize;
  newUtil.length = length;
  return newUtil;
}

int areEqual(ArrayUtil array_1,ArrayUtil array_2){
  if(array_1.length != array_2.length){return FALSE;}
  int *first_array = array_1.base;
  int *second_array = array_2.base;
  for (size_t i = 0; i < array_1.length;i++) {
    if(first_array[i] != second_array[i]){return FALSE;}
  }
  return TRUE;
}

void assert_for_int(ArrayUtil array_1){
  assert(array_1.typeSize == 4);
  assert(array_1.length == 10);
  int *array = (int *)array_1.base;
  array[0] = 23;
  assert(array[0] == 23);
}

void assert_for_long(ArrayUtil array_1){
  assert(array_1.typeSize == 4);
  assert(array_1.length == 10);
  long *array = (long *)array_1.base;
  array[0] = 999999999999;
  assert(array[0] == 999999999999);
}

void assert_for_float(ArrayUtil array_1){
  assert(array_1.typeSize == 4);
  assert(array_1.length == 10);
  float *array = (float *)array_1.base;
  array[0] = 1.5;
  assert(array[0] == 1.5);
}

void assert_for_char(ArrayUtil array_1){
  assert(array_1.typeSize == 1);
  assert(array_1.length == 10);
  char *array = (char *)array_1.base;
  array[0] = 'A';
  assert(array[0] == 'A');
}

void assert_for_double(ArrayUtil array_1){
  assert(array_1.typeSize == 8);
  assert(array_1.length == 10);
  double *array = (double *)array_1.base;
  array[0] = 4294967296664598;
  array[1] = 123.456;
  assert(array[0] == 4294967296664598);
  assert(array[1] == 123.456);

}

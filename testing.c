#include "array_utils.h"
#include "assert.h"
#include <stdlib.h>
void assert_for_int(){
  ArrayUtil util_1 = create(4,10);
  assert(util_1.typeSize == 4);
  assert(util_1.length == 10);
  int *array = (int *)util_1.base;
  array[0] = 23;
  assert(array[0] == 23);
  free(util_1.base);
}

void assert_for_long(){
  ArrayUtil util_1 = create(8,6);
  assert(util_1.typeSize == 8);
  assert(util_1.length == 6);
  long *array = (long *)util_1.base;
  array[0] = 999999999999;
  assert(array[0] == 999999999999);
  free(util_1.base);
}

void assert_for_float(){
  ArrayUtil util_1 = create(4,8);
  assert(util_1.typeSize == 4);
  assert(util_1.length == 8);
  float *array = (float *)util_1.base;
  array[0] = 1.5;
  assert(array[0] == 1.5);
  free(util_1.base);

}

void assert_for_char(){
  ArrayUtil util_1 = create(1,7);
  assert(util_1.typeSize == 1);
  assert(util_1.length == 7);
  char *array = (char *)util_1.base;
  array[0] = 'A';
  assert(array[0] == 'A');
  free(util_1.base);

}

void assert_for_double(){
  ArrayUtil util_1 = create(8,20);
  assert(util_1.typeSize == 8);
  assert(util_1.length == 20);
  double *array = (double *)util_1.base;
  array[0] = 4294967296664598;
  array[1] = 123.456;
  assert(array[0] == 4294967296664598);
  assert(array[1] == 123.456);
  free(util_1.base);
}

void assert_for_areEqual(){
  ArrayUtil util_1 = create(4,3);
  ArrayUtil util_2 = create(4,3);
  int *array1 = util_1.base;
  int *array2 = util_2.base;
  array1[0] = 1, array1[1] = 2, array1[2] = 3;
  array2[0] = 1, array2[1] = 2, array2[2] = 3;
  int are_equal = areEqual(util_1,util_2);
  assert(are_equal = TRUE);
  free(util_1.base);

  //---------------------------------------//
  // ArrayUtil util_3 = create(4,6);


}

void assert_for_resize(){
  ArrayUtil util_1 = create(4,5);
  ArrayUtil util_2 = resize(util_1,2);
  assert(util_2.length == 2);
  assert(util_2.typeSize == 4);
  int result = areEqual(util_1,util_2);
  assert(result == FALSE);
  free(util_1.base);
}


void assert_for_findIndex(){
  ArrayUtil util_1 = create(4,5);
  int *array = (int *)util_1.base;
  array[0] = 10 , array[1] = 20 , array[2] = 30 , array[3] = 40 , array[4] = 50;
  int value1 = 30;
  int value2 = 3;
  int result1 = findIndex(util_1,&value1);
  int result2 = findIndex(util_1,&value2);
  assert(result1 == 2);
  assert(result2 == -1);

  //-----------------------------------------//

  ArrayUtil util_2 = create(8,4);
  double *array2 = (double *)util_2.base;
  array2[0] = 123.542 , array2[1] = 342.563 , array2[2] = 2346.75 , array2[3] = 2363.265;
  double value3 = 342.563;
  int result3 = findIndex(util_2,&value3);
  assert(result3 == 1);
}

void assert_for_findFirst() {
  ArrayUtil util_1 = create(4,5);
  int *array = (int *)util_1.base;
  array[0] = 10, array[1] = 20, array[2] = 30, array[3] = 40, array[4] = 50;
  int value1 = 15;
  int value2 = 7;
  _match* mh1 = &isDivisible;
  _match* mh2 = &isEven;
  void *result1 = findFirst(util_1,mh1,&value1);
  void *result2 = findFirst(util_1,mh1,&value2);
  int ele1 = *(int *)result1;
  assert(ele1 == 30);
  assert(result2 == NULL);

  //-------------------------------------//

  void *result3 = findFirst(util_1,mh2,&value1);
  int ele2 = *(int *)result3;
  assert(ele2 == 10);
}

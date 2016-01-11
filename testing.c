#include "array_utils.h"
#include "assert.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int isDivisible(void *given_ele, void *array_ele){
  int result = (*(int *)array_ele) % (*(int *)given_ele) == 0;
  return result;
}

int isEven(void *given_ele,void *array_ele){
  int result = *(int *)array_ele % 2 == 0;
  return result;
}

//-------------------------------------------------------------------//

void test_for_int(){
  ArrayUtil util_1 = create(4,10);
  assert(util_1.typeSize == 4);
  assert(util_1.length == 10);
  int *array = (int *)util_1.base;
  array[0] = 23;
  assert(array[0] == 23);
  free(util_1.base);
}

void test_for_long(){
  ArrayUtil util_1 = create(8,6);
  assert(util_1.typeSize == 8);
  assert(util_1.length == 6);
  long *array = (long *)util_1.base;
  array[0] = 999999999999;
  assert(array[0] == 999999999999);
  free(util_1.base);
}

void test_for_float(){
  ArrayUtil util_1 = create(4,8);
  assert(util_1.typeSize == 4);
  assert(util_1.length == 8);
  float *array = (float *)util_1.base;
  array[0] = 1.5;
  assert(array[0] == 1.5);
  free(util_1.base);

}

void test_for_char(){
  ArrayUtil util_1 = create(1,7);
  assert(util_1.typeSize == 1);
  assert(util_1.length == 7);
  char *array = (char *)util_1.base;
  array[0] = 'A';
  assert(array[0] == 'A');
  free(util_1.base);

}

void test_for_double(){
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

void test_for_areEqual(){
  ArrayUtil util_1 = create(4,3);
  ArrayUtil util_2 = create(4,3);
  int *array1 = util_1.base;
  int *array2 = util_2.base;
  array1[0] = 1, array1[1] = 2, array1[2] = 3;
  array2[0] = 1, array2[1] = 2, array2[2] = 3;
  int are_equal = areEqual(util_1,util_2);
  assert(are_equal = TRUE);
  free(util_1.base);
}

void test_for_resize(){
  ArrayUtil util_1 = create(4,5);
  ArrayUtil util_2 = resize(util_1,2);
  assert(util_2.length == 2);
  assert(util_2.typeSize == 4);
  int result = areEqual(util_1,util_2);
  assert(result == FALSE);
  free(util_1.base);
}


void test_for_findIndex(){
  ArrayUtil util = create(4,5);
  int *array = (int *)util.base;
  array[0] = 10 , array[1] = 20 , array[2] = 30 , array[3] = 40 , array[4] = 50;
  int value1 = 30;
  int value2 = 3;
  int result1 = findIndex(util,&value1);
  int result2 = findIndex(util,&value2);
  assert(result1 == 2);
  assert(result2 == -1);

  //-----------------------------------------//

  ArrayUtil util_1 = create(8,4);
  double *array1 = (double *)util_1.base;
  array1[0] = 123.542 , array1[1] = 342.563 , array1[2] = 2346.75 , array1[3] = 2363.265;
  double value3 = 342.563;
  int result3 = findIndex(util_1,&value3);
  assert(result3 == 1);
  free(util.base);
  free(util_1.base);
}

void test_for_findFirst() {
  ArrayUtil util = create(4,5);
  int *array = (int *)util.base;
  array[0] = 10, array[1] = 20, array[2] = 30, array[3] = 40, array[4] = 50;
  _match* mh1 = &isDivisible;
  int value1 = 15;
  void *result1 = findFirst(util,mh1,&value1);
  int ele1 = *(int *)result1;
  assert(ele1 == 30);

  //------------------------------------------//

  int value2 = 7;
  void *result2 = findFirst(util,mh1,&value2);
  assert(result2 == NULL);

  //-------------------------------------//

  _match* mh2 = &isEven;
  void *result3 = findFirst(util,mh2,&value1);
  int ele2 = *(int *)result3;
  assert(ele2 == 10);
  free(util.base);
}


void test_for_findLast() {
  ArrayUtil util = create(4,5);
  int *array = (int *)util.base;
  array[0] = 10, array[1] = 20, array[2] = 30, array[3] = 60, array[4] = 44;
  int value1 = 15;
  int value2 = 7;
  _match* mh1 = &isDivisible;
  _match* mh2 = &isEven;
  void *result1 = findLast(util,mh1,&value1);
  void *result2 = findLast(util,mh1,&value2);
  int ele1 = *(int *)result1;
  assert(ele1 == 60);
  assert(result2 == NULL);

  //-------------------------------------//

  void *result3 = findLast(util,mh2,&value1);
  int ele2 = *(int *)result3;
  assert(ele2 == 44);
  free(util.base);
}


void test_for_countMatch(){
  ArrayUtil util = create(4,5);
  int *array = (int *)util.base;
  array[0] = 10, array[1] = 20, array[2] = 30, array[3] = 60, array[4] = 44;
  int value1 = 5;
  int value2 = 7;
  _match* mh1 = &isDivisible;
  int matchedEle1 = count(util,mh1,&value1);
  int matchedEle2 = count(util,mh1,&value2);
  assert(matchedEle1 == 4);
  assert(matchedEle2 == 0);

  //-----------------------------//

  _match* mh2 = &isEven;
  int matchedEle3 = count(util,mh2,&value1);
  assert(matchedEle3 == 5);
  free(util.base);
}

void test_for_filter(){
  ArrayUtil util = create(4,5);
  int *array = (int *)util.base;
  array[0] = 10, array[1] = 22, array[2] = 30, array[3] = 60, array[4] = 41;
  int value1 = 10;
  int value2 = 7;
  _match* mh1 = &isDivisible;
  _match* mh2 = &isEven;

  //-------------------------------------------//

  ArrayUtil util_1 = create(4,3);
  int matchedEle1 = filter(util,mh1,&value1,&util_1.base,util_1.length);

  int *array1 = (int *)util_1.base;
  assert(matchedEle1 == 2);
  assert(array1[0] == 10);
  assert(array1[1] == 30);

  //-----------------------------------------//

  ArrayUtil util_2 = create(4,1);
  int matchedEle2 = filter(util,mh1,&value2,&util_2.base,util_2.length);

  int *array2 = (int *)util_2.base;
  assert(matchedEle2 == 0);
  assert(array2[0] != 10);

  //-----------------------------//

  ArrayUtil util_3 = create(4,5);
  int matchedEle3 = filter(util,mh2,&value1,&util_3.base,util_3.length);
  assert(matchedEle3 == 4);
  int *array3 = (int *)util_3.base;
  assert(array3[0] == 10);
  assert(array3[1] == 22);
  assert(array3[2] == 30);
  assert(array3[3] == 60);
  free(util.base);
  free(util_1.base);
  free(util_2.base);
}

void increment_by(void *given_ele, void *source_ele, void *destination_ele){
  int dest = *(int *)given_ele + *(int *)source_ele;
  memcpy(destination_ele,&dest,sizeof(int));
}

void test_for_map(){
  ArrayUtil util = create(4,5);
  int *array = (int *)util.base;
  array[0] = 10, array[1] = 22, array[2] = 30, array[3] = 60, array[4] = 41;
  int value1 = 10;
  ArrayUtil util_1 = create(4,5);
  map(util,util_1,increment_by,&value1);
  int *array1 = (int *)util_1.base;
  assert(array1[0] == 20);
  assert(array1[1] == 32);
  assert(array1[2] == 40);
  assert(array1[3] == 70);
  assert(array1[4] == 51);
  free(util.base);
  free(util_1.base);
}

void multiply_by(void *given_ele,void *array_value){
  int populated_value = *(int *)given_ele * *(int *)array_value;
  memcpy(array_value,&populated_value,sizeof(int));
}

void test_for_forEach(){
  ArrayUtil util = create(4,5);
  int *array = (int *)util.base;
  array[0] = 10, array[1] = 22, array[2] = 30, array[3] = 60, array[4] = 41;
  int value1 = 3;
  forEach(util,multiply_by,&value1);
  assert(array[0] == 30);
  assert(array[1] == 66);
  assert(array[2] == 90);
  assert(array[3] == 180);
  assert(array[4] == 123);
  free(util.base);
}

void *add_all(void *given_ele,void *prev_ele,void *current_ele){
  int *total = (int *)calloc(1,sizeof(int));
  *total = *(int *)prev_ele + *(int *)current_ele;
  return total;
}

void test_for_reduce(){
  ArrayUtil util = create(4,5);
  int *array = (int *)util.base;
  array[0] = 10, array[1] = 22, array[2] = 30, array[3] = 60, array[4] = 41;
  int value1 = 3;
  int value2 = 0;
  void *result = reduce(util,add_all,&value1,&value2);
  assert(*(int *)result == 163);
  free(util.base);
}

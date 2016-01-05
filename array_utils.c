#include "array_utils.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

ArrayUtil create(int typeSize,int length){
  void *newArray = calloc(length,typeSize);
  ArrayUtil newUtil;
  newUtil.base = newArray;
  newUtil.typeSize = typeSize;
  newUtil.length = length;
  return newUtil;
}

int areEqual(ArrayUtil util_1,ArrayUtil util_2){
  int result = memcmp(util_1.base,util_2.base,util_1.typeSize * util_1.length);
  return result == TRUE;
}

ArrayUtil resize(ArrayUtil util,int length){
  realloc(util.base,length);
  util.length = length;
  return util;
}

int findIndex(ArrayUtil util, void* element){
  void *array = util.base;
  for (size_t i = 0; i < util.length; i++) {
    int result = memcmp(array,element,util.typeSize);
    if(result == 0){
      return i;
    }
    array += util.typeSize;
  }
  return -1;
}

void dispose(ArrayUtil util){
  free(util.base);
}

int isDivisible(void *given_ele, void *array_ele){
  int result = (*(int *)array_ele) % (*(int *)given_ele) == 0;
  return result;
}

int isEven(void *given_ele,void *array_ele){
  int result = *(int *)array_ele % 2 == 0;
  return result;
}

void *findFirst(ArrayUtil util,_match mh,void *given_ele){
  for (size_t i = 0; i < util.length; i++) {
    if(mh(given_ele,util.base) == 1){
      return util.base;
    }
    util.base += util.typeSize;
  }
  return (void *)NULL;
}

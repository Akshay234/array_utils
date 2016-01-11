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

void *findFirst(ArrayUtil util,_match mh,void *given_ele){
  for (size_t i = 0; i < util.length; i++) {
    if(mh(given_ele,util.base) == 1){
      return util.base;
    }
    util.base += util.typeSize;
  }
  return (void *)NULL;
}


void *findLast(ArrayUtil util,_match mh,void *given_ele){
  void *lastMatch = (void *)NULL;
  for (size_t i = 0; i < util.length; i++) {
    if(mh(given_ele,util.base) == 1){
        lastMatch = util.base;
    }
    util.base += util.typeSize;
  }
  return lastMatch;
}

int count(ArrayUtil util,_match mh, void *given_ele){
  int counter = 0;
  for (size_t i = 0; i < util.length; i++) {
    if(mh(given_ele,util.base) == 1){
        counter++;
    }
    util.base += util.typeSize;
  }
  return counter;
}

int filter(ArrayUtil util,_match mh, void* given_ele, void** destination, int maxItems){
  int counter = 0;
  void *array = *destination;
  for (size_t i = 0; i < maxItems; i++) {
    if(mh(given_ele,util.base) == 1){
      memcpy(array,util.base,util.typeSize);
      counter++;
      array += util.typeSize;
    }
    util.base += util.typeSize;
  }
  return counter;
}

void map(ArrayUtil source, ArrayUtil destination, ConvertFunc* convert, void* given_ele){
  for (size_t i = 0; i < source.length; i++) {
    convert(given_ele,source.base,destination.base);
    source.base += source.typeSize;
    destination.base += destination.typeSize;
  }
}

void forEach(ArrayUtil util, OperationFunc* operation, void* hint){
  for (size_t i = 0; i < util.length; i++) {
    operation(hint,util.base);
    util.base += util.typeSize;
  }
}

void* reduce(ArrayUtil util, ReducerFunc* reducer, void* given_ele, void* intialValue){
  void *initial = intialValue;
  for (size_t i = 0; i < util.length; i++) {
    initial = reducer(given_ele,initial,util.base);
    util.base += util.typeSize;
  }
  return initial;
}

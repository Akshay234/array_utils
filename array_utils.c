#include <stdlib.h>
#include "array_utils.h"
#include <stdio.h>
#include "string.h"



ArrayUtil create(int typeSize,int length){
  void *newArray = calloc(length,typeSize);
  ArrayUtil newUtil;
  newUtil.base = newArray;
  newUtil.typeSize = typeSize;
  newUtil.length = length;
  return newUtil;
}

int areEqual(ArrayUtil array_1,ArrayUtil array_2){
  int result = memcmp(array_1.base,array_2.base,array_1.typeSize * array_1.length);
  return result == TRUE;
}

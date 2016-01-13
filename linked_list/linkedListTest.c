#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"
#include "stdio.h"

void test_for_create(){
  LinkedList list = createList();
  assert(list.first == NULL);
  assert(list.last == NULL);
  assert(list.total_ele == 0);
}

void test_for_add_to_list(){
  LinkedList list = createList();
  int val = 4;
  char alp = 'A';
  float float_val = 2.5;
  add_to_list(&list,&val);
  add_to_list(&list,&alp);
  int total_ele_in_array = add_to_list(&list,&float_val);
  assert(total_ele_in_array == 3);
  assert(*(float *)list.last->value == 2.5);
  assert(*(char *)list.first->next->value == 'A');
  assert(*(int *)list.first->value == 4);
}

void test_for_get_first_element(){
  LinkedList list = createList();
  char char1 = 'A', char2 = 'B', char3 = 'C';
  add_to_list(&list,&char1);
  add_to_list(&list,&char2);
  add_to_list(&list,&char3);
  void *first_ele = get_first_element(list);
  assert(*(char *)first_ele == 'A');
}


void test_for_get_last_element(){
  LinkedList list = createList();
  char char1 = 'A', char2 = 'B', char3 = 'C', char4 = 'D';
  add_to_list(&list,&char1);
  add_to_list(&list,&char2);
  add_to_list(&list,&char3);
  add_to_list(&list,&char4);
  void *last_ele = get_last_element(list);
  assert(*(char *)last_ele == 'D');
}

void increment(void *val){
  int *a = (int *)malloc(sizeof(int));
  *a = *(int *)val +1;
  memcpy(val,a,sizeof(int));
}

void test_for_forEach(){
  LinkedList list = createList();
  int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5, val6 = 6;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  add_to_list(&list,&val5);
  add_to_list(&list,&val6);
  forEach(list,increment);
  assert(*(int *)list.first->value == 2);
  assert(*(int *)list.last->value == 7);
  assert(*(int *)list.first->next->value == 3);
  assert(*(int *)list.first->next->next->value == 4);
  forEach(list,increment);
  assert(*(int *)list.first->value == 3);
  assert(*(int *)list.last->value == 8);
  assert(*(int *)list.first->next->value == 4);
  assert(*(int *)list.first->next->next->value == 5);
}


void test_for_getElementAt(){
  LinkedList list = createList();
  int val1 = 1, val2 = 2, val3 = 3, val4 = 4;
  char val5 = 'A';
  float val6 = 6.5;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  add_to_list(&list,&val5);
  add_to_list(&list,&val6);
  void *ele1 = getElementAt(list,2);
  assert(*(int *)ele1 == 3);
  void *ele2 = getElementAt(list,4);
  assert(*(char *)ele2 == 'A');
  void *ele3 = getElementAt(list,5);
  assert(*(float *)ele3 == 6.5);
}


void test_for_indexOf(){
  LinkedList list = createList();
  int val1 = 1, val2 = 2, val3 = 3, val4 = 4;
  char val5 = 'A';
  float val6 = 6.5;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  add_to_list(&list,&val5);
  add_to_list(&list,&val6);
  int ele1 = 3;
  int result1 = indexOf(list,&ele1);
  assert(result1 == 2);
  char ele2 = 'A';
  int result2 = indexOf(list,&ele2);
  assert(result2 == 4);
}

void test_for_deleteElementAt(){
  LinkedList list1 = createList();
  int val1 = 1, val2 = 2, val3 = 3, val4 = 4;
  char val5 = 'A';
  float val6 = 6.5;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  add_to_list(&list1,&val5);
  add_to_list(&list1,&val6);
  void *ele1 = deleteElementAt(&list1,2);
  assert(*(int *)ele1 == 3);
  assert(list1.total_ele == 5);
  assert(*(int *)list1.first->next->next->value == 4);

 //-----------------------------------------//

  LinkedList list2 = createList();
  add_to_list(&list2,&val1);
  add_to_list(&list2,&val2);
  add_to_list(&list2,&val3);
  add_to_list(&list2,&val4);
  add_to_list(&list2,&val5);
  add_to_list(&list2,&val6);
  void *ele2 = deleteElementAt(&list2,0);
  assert(*(int *)ele2 == 1);
  assert(list2.total_ele == 5);
  assert(*(int *)list2.first->value == 2);

  //--------------------------------------------//

  LinkedList list3 = createList();
  add_to_list(&list3,&val1);
  add_to_list(&list3,&val2);
  add_to_list(&list3,&val3);
  add_to_list(&list3,&val4);
  add_to_list(&list3,&val5);
  add_to_list(&list3,&val6);
  void *ele3 = deleteElementAt(&list3,5);
  assert(*(float *)ele3 == 6.5);
  assert(list3.total_ele == 5);
  assert(*(char *)list3.last->value == 'A');

  void *ele4 =deleteElementAt(&list3,5);
  assert(list3.total_ele == 5);
  assert(*(char *)list3.last->value == 'A');
  assert(ele4 == NULL);
}

void test_for_asArray(){
  LinkedList list1 = createList();
  int val1 = 1, val2 = 2, val3 = 3, val4 = 4;
  char val5 = 'A';
  float val6 = 6.5;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  add_to_list(&list1,&val5);
  add_to_list(&list1,&val6);
  void *array[10];
  int arrayLength = asArray(list1,array,3);
  assert(arrayLength == 3);
  assert(*(int *)array[0] == 1);
  assert(*(int *)array[1] == 2);
  assert(*(int *)array[2] == 3);
}

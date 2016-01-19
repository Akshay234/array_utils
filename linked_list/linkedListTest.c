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

void test_of_int_for_add_to_list(){
  LinkedList list = createList();
  int val1 = 4, val2 = 7, val3 = 13;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  int total_ele_in_array = add_to_list(&list,&val3);
  assert(total_ele_in_array == 3);
  assert(*(int *)list.first->value == val1);
  assert(*(int *)list.first->next->value == val2);
  assert(*(int *)list.last->value == val3);
}

void test_of_char_for_add_to_list(){
  LinkedList list = createList();
  char alp1 = 'A', alp2 = 'B', alp3 = 'C';
  float float_val = 2.5;
  add_to_list(&list,&alp1);
  add_to_list(&list,&alp2);
  int total_ele_in_array = add_to_list(&list,&alp3);
  assert(total_ele_in_array == 3);
  assert(*(char *)list.first->value == alp1);
  assert(*(char *)list.first->next->value == alp2);
  assert(*(char *)list.last->value == alp3);
}

void test_of_double_for_add_to_list(){
  LinkedList list = createList();
  double val1 = 4294967296, val2 = 4294967295, val3 = 4294967299;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  int total_ele_in_array = add_to_list(&list,&val3);
  assert(total_ele_in_array == 3);
  assert(*(double *)list.first->value == val1);
  assert(*(double *)list.first->next->value == val2);
  assert(*(double *)list.last->value == val3);
}

void test_of_float_for_add_to_list(){
  LinkedList list = createList();
  float val1 = 4.5, val2 = 3.5;
  add_to_list(&list,&val1);
  int total_ele_in_array = add_to_list(&list,&val2);
  assert(total_ele_in_array == 2);
  assert(*(float *)list.first->value == val1);
  assert(*(float *)list.first->next->value == val2);
  assert(*(float *)list.last->value == val2);
}


//------------------------------------------------------------------------//

void test_of_num_for_get_first_element(){
  LinkedList list = createList();
  int val1 = 10, val2 = 20, val3 = 30;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  void *first_ele = get_first_element(list);
  assert(*(int *)first_ele == val1);
  void *same_ele = get_first_element(list);
  assert(*(int *)same_ele == val1);
}

void test_of_char_for_get_first_element(){
  LinkedList list = createList();
  char alp1 = 'A', alp2 = 'B', alp3 = 'C';
  add_to_list(&list,&alp1);
  add_to_list(&list,&alp2);
  add_to_list(&list,&alp3);
  void *first_ele = get_first_element(list);
  assert(*(char *)first_ele == alp1);
}

void test_of_float_for_get_first_element(){
  LinkedList list = createList();
  float val1 = 7.5, val2 = 2.0, val3 = 9.5;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  void *first_ele = get_first_element(list);
  assert(*(float *)first_ele == val1);
  void *same_ele = get_first_element(list);
  assert(*(float *)same_ele == val1);
}

void test_of_double_for_get_first_element(){
  LinkedList list = createList();
  double val1 = 1293467389, val2 = 239846894639, val3 = 23865768364678;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  void *first_ele = get_first_element(list);
  assert(*(double *)first_ele == val1);
  void *same_ele = get_first_element(list);
  assert(*(double *)same_ele == val1);
}

//---------------------------------------------------------------//

void test_of_num_for_get_last_element(){
  LinkedList list = createList();
  int val1 = 10, val2 = 20, val3 = 30;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  void *first_ele = get_last_element(list);
  assert(*(int *)first_ele == val3);
  void *same_ele = get_last_element(list);
  assert(*(int *)same_ele == val3);
}

void test_of_char_for_get_last_element(){
  LinkedList list = createList();
  char alp1 = 'A', alp2 = 'B', alp3 = 'C', alp4 = 'D';
  add_to_list(&list,&alp1);
  add_to_list(&list,&alp2);
  add_to_list(&list,&alp3);
  add_to_list(&list,&alp4);
  void *last_ele = get_last_element(list);
  assert(*(char *)last_ele == alp4);
}

void test_of_float_for_get_last_element(){
  LinkedList list = createList();
  float val1 = 7.5, val2 = 2.0, val3 = 9.5;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  void *first_ele = get_last_element(list);
  assert(*(float *)first_ele == val3);
  void *same_ele = get_last_element(list);
  assert(*(float *)same_ele == val3);
}

void test_of_double_for_get_last_element(){
  LinkedList list = createList();
  double val1 = 1293467389, val2 = 239846894639, val3 = 23865768364678;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  void *first_ele = get_last_element(list);
  assert(*(double *)first_ele == val3);
  void *same_ele = get_last_element(list);
  assert(*(double *)same_ele == val3);
}

//--------------------------------------------------------------------//

void increment_int_type(void *val){
  int *a = (int *)malloc(sizeof(int));
  *a = *(int *)val +1;
  memcpy(val,a,sizeof(int));
}

void increment_double_type(void *val){
  double *a = (double *)malloc(sizeof(double));
  *a = *(double *)val +1;
  memcpy(val,a,sizeof(double));
}

void increment_float_type(void *val){
  float *a = (float *)malloc(sizeof(float));
  *a = *(float *)val +1;
  memcpy(val,a,sizeof(float));
}

void test_of_int_for_forEach(){
  LinkedList list = createList();
  int val1 = 1, val2 = 2, val3 = 3, val4 = 4, val5 = 5, val6 = 6;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  add_to_list(&list,&val5);
  add_to_list(&list,&val6);
  forEach(list,increment_int_type);
  assert(*(int *)list.first->value == 2);
  assert(*(int *)list.first->next->value == 3);
  assert(*(int *)list.first->next->next->value == 4);
  assert(*(int *)list.last->value == 7);
  forEach(list,increment_int_type);
  assert(*(int *)list.first->value == 3);
  assert(*(int *)list.first->next->value == 4);
  assert(*(int *)list.first->next->next->value == 5);
  assert(*(int *)list.last->value == 8);
}

void test_of_char_for_forEach(){
  LinkedList list = createList();
  char alp1 = 'A', alp2 = 'B', alp3 = 'C', alp4 = 'D', alp5 = 'E', alp6 = 'F';
  add_to_list(&list,&alp1);
  add_to_list(&list,&alp2);
  add_to_list(&list,&alp3);
  add_to_list(&list,&alp4);
  add_to_list(&list,&alp5);
  add_to_list(&list,&alp6);
  forEach(list,increment_int_type);
  assert(*(char *)list.first->value == 'B');
  assert(*(char *)list.first->next->value == 'C');
  assert(*(char *)list.first->next->next->value == 'D');
  assert(*(char *)list.last->value == 'G');
  forEach(list,increment_int_type);
  assert(*(char *)list.first->value == 'C');
  assert(*(char *)list.first->next->value == 'D');
  assert(*(char *)list.first->next->next->value == 'E');
  assert(*(char *)list.last->value == 'H');
}

void test_of_double_for_forEach(){
  LinkedList list = createList();
  double val1 = 986325387, val2 = 238975243786, val3 = 238769543,
  val4 = 832456754356, val5 = 2436765465, val6 = 4676765445768765;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  add_to_list(&list,&val5);
  add_to_list(&list,&val6);
  forEach(list,increment_double_type);
  assert(*(double *)list.first->value == 986325388);
  assert(*(double *)list.first->next->value == 238975243787);
  assert(*(double *)list.first->next->next->value == 238769544);
  assert(*(double *)list.last->value == 4676765445768766);
  forEach(list,increment_double_type);
  assert(*(double *)list.first->value == 986325389);
  assert(*(double *)list.first->next->value == 238975243788);
  assert(*(double *)list.first->next->next->value == 238769545);
  assert(*(double *)list.last->value == 4676765445768767);
}


void test_of_float_for_forEach(){
  LinkedList list = createList();
  float val1 = 9.5, val2 = 2.0, val3 = 6.5;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  forEach(list,increment_float_type);
  assert(*(float *)list.first->value == 10.5);
  assert(*(float *)list.first->next->value == 3.0);
  assert(*(float *)list.last->value == 7.5);
  forEach(list,increment_float_type);
  assert(*(float *)list.first->value == 11.5);
  assert(*(float *)list.first->next->value == 4.0);
  assert(*(float *)list.last->value == 8.5);
}

//-----------------------------------------------------------------------------//


void test_of_int_for_getElementAt(){
  LinkedList list = createList();
  int val1 = 10, val2 = 20, val3 = 30, val4 = 40;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  void *no_ele = getElementAt(list,-1);
  assert(no_ele == NULL);
  void *ele0 = getElementAt(list,0);
  assert(*(int *)ele0 == val1);
  void *ele1 = getElementAt(list,1);
  assert(*(int *)ele1 == val2);
  void *ele2 = getElementAt(list,2);
  assert(*(int *)ele2 == val3);
  void *ele3 = getElementAt(list,3);
  assert(*(int *)ele3 == val4);
  void *ele4 = getElementAt(list,4);
  assert(ele4 == NULL);
}

void test_of_char_for_getElementAt(){
  LinkedList list = createList();
  char alp1 = 'A', alp2 = 'B', alp3 = 'C', alp4 = 'D';
  add_to_list(&list,&alp1);
  add_to_list(&list,&alp2);
  add_to_list(&list,&alp3);
  add_to_list(&list,&alp4);
  void *no_ele = getElementAt(list,-1);
  assert(no_ele == NULL);
  void *ele0 = getElementAt(list,0);
  assert(*(char *)ele0 == alp1);
  void *ele1 = getElementAt(list,1);
  assert(*(char *)ele1 == alp2);
  void *ele2 = getElementAt(list,2);
  assert(*(char *)ele2 == alp3);
  void *ele3 = getElementAt(list,3);
  assert(*(char *)ele3 == alp4);
  void *ele4 = getElementAt(list,4);
  assert(ele4 == NULL);
}

void test_of_double_for_getElementAt(){
  LinkedList list = createList();
  double val1 = 986325387, val2 = 238975243786,
  val3 = 238769543,val4 = 832456754356466;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  void *no_ele = getElementAt(list,-1);
  assert(no_ele == NULL);
  void *ele0 = getElementAt(list,0);
  assert(*(double *)ele0 == val1);
  void *ele1 = getElementAt(list,1);
  assert(*(double *)ele1 == val2);
  void *ele2 = getElementAt(list,2);
  assert(*(double *)ele2 == val3);
  void *ele3 = getElementAt(list,3);
  assert(*(double *)ele3 == val4);
  void *ele4 = getElementAt(list,4);
  assert(ele4 == NULL);
}

void test_of_float_for_getElementAt(){
  LinkedList list = createList();
  float val1 = 9.5, val2 = 2.5,
  val3 = 2.0,val4 = 8.5;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  void *no_ele = getElementAt(list,-1);
  assert(no_ele == NULL);
  void *ele0 = getElementAt(list,0);
  assert(*(float *)ele0 == val1);
  void *ele1 = getElementAt(list,1);
  assert(*(float *)ele1 == val2);
  void *ele2 = getElementAt(list,2);
  assert(*(float *)ele2 == val3);
  void *ele3 = getElementAt(list,3);
  assert(*(float *)ele3 == val4);
  void *ele4 = getElementAt(list,4);
  assert(ele4 == NULL);
}

//-------------------------------------------------------------------------------//


void test_of_int_for_indexOf(){
  LinkedList list = createList();
  int val1 = 10, val2 = 20, val3 = 30, val4 = 40;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  int val5 = 50;
  assert(indexOf(list,&val1) == 0);
  assert(indexOf(list,&val2) == 1);
  assert(indexOf(list,&val3) == 2);
  assert(indexOf(list,&val4) == 3);
  assert(indexOf(list,&val5) == -1);
}

void test_of_char_for_indexOf(){
  LinkedList list = createList();
  char alp1 = 'A', alp2 = 'B', alp3 = 'C', alp4 = 'D';
  add_to_list(&list,&alp1);
  add_to_list(&list,&alp2);
  add_to_list(&list,&alp3);
  add_to_list(&list,&alp4);
  char alp5 = 'E';
  assert(indexOf(list,&alp1) == 0);
  assert(indexOf(list,&alp2) == 1);
  assert(indexOf(list,&alp3) == 2);
  assert(indexOf(list,&alp4) == 3);
  assert(indexOf(list,&alp5) == -1);
}


void test_of_double_for_indexOf(){
  LinkedList list = createList();
  double val1 = 986325387, val2 = 238975243786,
  val3 = 238769543,val4 = 832456754356466;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  double val5 = 83245675435646667;
  assert(indexOf(list,&val1) == 0);
  assert(indexOf(list,&val2) == 1);
  assert(indexOf(list,&val3) == 2);
  assert(indexOf(list,&val4) == 3);
  assert(indexOf(list,&val5) == -1);
}

void test_of_float_for_indexOf(){
  LinkedList list = createList();
  float val1 = 9.5, val2 = 2.5,
  val3 = 2.0,val4 = 8.5;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  float val5 = 10.5;
  assert(indexOf(list,&val1) == 0);
  assert(indexOf(list,&val2) == 1);
  assert(indexOf(list,&val3) == 2);
  assert(indexOf(list,&val4) == 3);
  assert(indexOf(list,&val5) == -1);
}

//-----------------------------------------------------------------------------//

void test_of_int_for_deleteElementAt(){
  LinkedList list = createList();
  int val1 = 10, val2 = 20, val3 = 30, val4 = 40,val5 = 50, val6 = 60;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  add_to_list(&list,&val5);
  add_to_list(&list,&val6);

  assert(deleteElementAt(&list,-1) == NULL);
  assert(list.total_ele == 6);
  assert(*(int *)list.first->value == val1);
  assert(*(int *)list.first->next->value == val2);
  assert(*(int *)list.first->next->next->value == val3);
  assert(*(int *)list.last->value == val6);

  assert(deleteElementAt(&list,6) == NULL);
  assert(list.total_ele == 6);
  assert(*(int *)list.first->value == val1);
  assert(*(int *)list.first->next->value == val2);
  assert(*(int *)list.first->next->next->value == val3);
  assert(*(int *)list.last->value == val6);


  assert(*(int *)deleteElementAt(&list,0) == val1);
  assert(list.total_ele == 5);
  assert(*(int *)list.first->value == val2);
  assert(*(int *)list.first->next->value == val3);
  assert(*(int *)list.first->next->next->value == val4);
  assert(*(int *)list.last->value == val6);

  assert(*(int *)deleteElementAt(&list,4) == val6);
  assert(list.total_ele == 4);
  assert(*(int *)list.first->value == val2);
  assert(*(int *)list.first->next->value == val3);
  assert(*(int *)list.first->next->next->value == val4);
  assert(*(int *)list.last->value == val5);

  assert(*(int *)deleteElementAt(&list,2) == val4);
  assert(list.total_ele == 3);
  assert(*(int *)list.first->value == val2);
  assert(*(int *)list.first->next->value == val3);
  assert(*(int *)list.first->next->next->value == val5);
  assert(*(int *)list.last->value == val5);
}

void test_of_char_for_deleteElementAt(){
  LinkedList list = createList();
  char alp1 = 'A', alp2 = 'B', alp3 = 'C', alp4 = 'D',alp5 = 'E', alp6 = 'F';
  add_to_list(&list,&alp1);
  add_to_list(&list,&alp2);
  add_to_list(&list,&alp3);
  add_to_list(&list,&alp4);
  add_to_list(&list,&alp5);
  add_to_list(&list,&alp6);

  assert(deleteElementAt(&list,-1) == NULL);
  assert(list.total_ele == 6);
  assert(*(char *)list.first->value == alp1);
  assert(*(char *)list.first->next->value == alp2);
  assert(*(char *)list.first->next->next->value == alp3);
  assert(*(char *)list.last->value == alp6);

  assert(deleteElementAt(&list,6) == NULL);
  assert(list.total_ele == 6);
  assert(*(char *)list.first->value == alp1);
  assert(*(char *)list.first->next->value == alp2);
  assert(*(char *)list.first->next->next->value == alp3);
  assert(*(char *)list.last->value == alp6);

  assert(*(char *)deleteElementAt(&list,0) == alp1);
  assert(list.total_ele == 5);
  assert(*(char *)list.first->value == alp2);
  assert(*(char *)list.first->next->value == alp3);
  assert(*(char *)list.first->next->next->value == alp4);
  assert(*(char *)list.last->value == alp6);

  assert(*(char *)deleteElementAt(&list,4) == alp6);
  assert(list.total_ele == 4);
  assert(*(char *)list.first->value == alp2);
  assert(*(char *)list.first->next->value == alp3);
  assert(*(char *)list.first->next->next->value == alp4);
  assert(*(char *)list.last->value ==alp5);

  assert(*(char *)deleteElementAt(&list,2) == alp4);
  assert(list.total_ele == 3);
  assert(*(char *)list.first->value == alp2);
  assert(*(char *)list.first->next->value == alp3);
  assert(*(char *)list.first->next->next->value == alp5);
  assert(*(char *)list.last->value == alp5);
}

void test_of_double_for_deleteElementAt(){
  LinkedList list = createList();
  double val1 = 986325387, val2 = 238975243786, val3 = 238769543,
  val4 = 832456754356, val5 = 2436765465, val6 = 4676765445768765;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);
  add_to_list(&list,&val5);
  add_to_list(&list,&val6);

  assert(deleteElementAt(&list,-1) == NULL);
  assert(list.total_ele == 6);
  assert(*(double *)list.first->value == val1);
  assert(*(double *)list.first->next->value == val2);
  assert(*(double *)list.first->next->next->value == val3);
  assert(*(double *)list.last->value == val6);

  assert(deleteElementAt(&list,6) == NULL);
  assert(list.total_ele == 6);
  assert(*(double *)list.first->value == val1);
  assert(*(double *)list.first->next->value == val2);
  assert(*(double *)list.first->next->next->value == val3);
  assert(*(double *)list.last->value == val6);

  assert(*(double *)deleteElementAt(&list,0) == val1);
  assert(list.total_ele == 5);
  assert(*(double *)list.first->value == val2);
  assert(*(double *)list.first->next->value == val3);
  assert(*(double *)list.first->next->next->value == val4);
  assert(*(double *)list.last->value == val6);

  assert(*(double *)deleteElementAt(&list,4) == val6);
  assert(list.total_ele == 4);
  assert(*(double *)list.first->value == val2);
  assert(*(double *)list.first->next->value == val3);
  assert(*(double *)list.first->next->next->value == val4);
  assert(*(double *)list.last->value == val5);

  assert(*(double *)deleteElementAt(&list,2) == val4);
  assert(list.total_ele == 3);
  assert(*(double *)list.first->value == val2);
  assert(*(double *)list.first->next->value == val3);
  assert(*(double *)list.first->next->next->value == val5);
  assert(*(double *)list.last->value == val5);
}

void test_of_float_for_deleteElementAt(){
  LinkedList list = createList();
  float val1 = 9.5, val2 = 2.5,
  val3 = 2.0,val4 = 8.5;
  add_to_list(&list,&val1);
  add_to_list(&list,&val2);
  add_to_list(&list,&val3);
  add_to_list(&list,&val4);

  assert(deleteElementAt(&list,-1) == NULL);
  assert(list.total_ele == 4);
  assert(*(float *)list.first->value == val1);
  assert(*(float *)list.first->next->value == val2);
  assert(*(float *)list.last->value == val4);

  assert(deleteElementAt(&list,5) == NULL);
  assert(list.total_ele == 4);
  assert(*(float *)list.first->value == val1);
  assert(*(float *)list.first->next->value == val2);
  assert(*(float *)list.last->value == val4);

  assert(*(float *)deleteElementAt(&list,0) == val1);
  assert(list.total_ele == 3);
  assert(*(float *)list.first->value == val2);
  assert(*(float *)list.first->next->value == val3);
  assert(*(float *)list.last->value == val4);

  assert(*(float *)deleteElementAt(&list,2) == val4);
  assert(list.total_ele == 2);
  assert(*(float *)list.first->value == val2);
  assert(*(float *)list.first->next->value == val3);
  assert(*(float *)list.last->value == val3);
}

//--------------------------------------------------------------//

void test_of_int_for_asArray(){
  LinkedList list1 = createList();
  int val1 = 10, val2 = 20, val3 = 30, val4 = 40,val5 = 50, val6 = 60;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  add_to_list(&list1,&val5);
  add_to_list(&list1,&val6);
  void *array[10];
  assert(asArray(list1,array,5) == 5);
  assert(*(int *)array[0] == val1);
  assert(*(int *)array[1] == val2);
  assert(*(int *)array[2] == val3);
  assert(*(int *)array[3] == val4);
  assert(*(int *)array[4] == val5);
}

void test_of_char_for_asArray(){
  LinkedList list1 = createList();
  char alp1 = 'A', alp2 = 'B', alp3 = 'C', alp4 = 'D',alp5 = 'E', alp6 = 'F';
  add_to_list(&list1,&alp1);
  add_to_list(&list1,&alp2);
  add_to_list(&list1,&alp3);
  add_to_list(&list1,&alp4);
  add_to_list(&list1,&alp5);
  add_to_list(&list1,&alp6);
  void *array[10];
  assert(asArray(list1,array,6) == 6);
  assert(*(char *)array[0] == alp1);
  assert(*(char *)array[1] == alp2);
  assert(*(char *)array[2] == alp3);
  assert(*(char *)array[3] == alp4);
  assert(*(char *)array[4] == alp5);
  assert(*(char *)array[5] == alp6);
}

void test_of_double_for_asArray(){
  LinkedList list1 = createList();
  double val1 = 986325387, val2 = 238975243786, val3 = 238769543,
  val4 = 832456754356, val5 = 2436765465, val6 = 4676765445768765;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  add_to_list(&list1,&val5);
  add_to_list(&list1,&val6);
  void *array[10];
  assert(asArray(list1,array,6) == 6);
  assert(*(double *)array[0] == val1);
  assert(*(double *)array[1] == val2);
  assert(*(double *)array[2] == val3);
  assert(*(double *)array[3] == val4);
  assert(*(double *)array[4] == val5);
  assert(*(double *)array[5] == val6);
}

void test_for_asArray_when_linkedList_have_less_ele(){
  LinkedList list1 = createList();
  double val1 = 986325387, val2 = 238975243786, val3 = 238769543, val4 = 832456754356;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  void *array[10];
  assert(asArray(list1,array,6) == 6);
  assert(*(double *)array[0] == val1);
  assert(*(double *)array[1] == val2);
  assert(*(double *)array[2] == val3);
  assert(*(double *)array[3] == val4);
  assert(*(double *)array[4] == 0);
  assert(*(double *)array[5] == 0);
}

// void test_for_asArray_when_linkedList_have_more_ele(){
//   LinkedList list1 = createList();
//   int val1 = 10, val2 = 20, val3 = 30, val4 = 40,val5 = 50, val6 = 60;
//   add_to_list(&list1,&val1);
//   add_to_list(&list1,&val2);
//   add_to_list(&list1,&val3);
//   add_to_list(&list1,&val4);
//   add_to_list(&list1,&val5);
//   add_to_list(&list1,&val6);
//   void *array[5];
//   assert(asArray(list1,array,6) == 5);
//   assert(*(int *)array[0] == val1);
//   assert(*(int *)array[1] == val2);
//   assert(*(int *)array[2] == val3);
//   assert(*(int *)array[3] == val4);
//   assert(*(int *)array[4] == val5);
// }

//------------------------------------------------------------------------//

int greater_int(void *num,void *hint){
  return *(int *)num > *(int *)hint;
}

int greater_char(void *num,void *hint){
  return *(char *)num > *(char *)hint;
}

int greater_double(void *num,void *hint){
  return *(double *)num > *(double *)hint;
}

void test_of_int_for_filter(){
  LinkedList list1 = createList();
  int val1 = 11, val2 = 12, val3 = 13, val4 = 15, val5 = 16;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  add_to_list(&list1,&val5);
  LinkedList refinedList = filter(list1,greater_int,&val3);
  assert(refinedList.total_ele == 2);
  assert(*(int *)refinedList.first->value == val4);
  assert(*(int *)refinedList.first->next->value == val5);
  assert(*(int *)refinedList.last->value == val5);
}

void test_of_char_for_filter(){
  LinkedList list1 = createList();
  char alp1 = 'A', alp2 = 'B', alp3 = 'C', alp4 = 'D', alp5 = 'E';
  add_to_list(&list1,&alp1);
  add_to_list(&list1,&alp2);
  add_to_list(&list1,&alp3);
  add_to_list(&list1,&alp4);
  add_to_list(&list1,&alp5);
  LinkedList refinedList = filter(list1,greater_char,&alp2);
  assert(refinedList.total_ele == 3);
  assert(*(char *)refinedList.first->value == alp3);
  assert(*(char *)refinedList.first->next->value == alp4);
  assert(*(char *)refinedList.last->value == alp5);
}

void test_of_double_for_filter(){
  LinkedList list1 = createList();
  double val1 = 986325387, val2 = 238975243786, val3 = 238769543, val4 = 832456754356;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  LinkedList refinedList = filter(list1,greater_double,&val2);
  assert(refinedList.total_ele == 1);
  assert(*(double *)refinedList.first->value == val4);
  assert(*(double *)refinedList.last->value == val4);
  assert(refinedList.first->next == refinedList.last->next);
}

//------------------------------------------------------------------------------//

void test_of_int_for_reverse(){
  LinkedList list1 = createList();
  int val1 = 11, val2 = 12, val3 = 13, val4 = 15,val5 = 16;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  add_to_list(&list1,&val5);
  LinkedList reversedList = reverse(list1);
  assert(reversedList.total_ele == 5);
  assert(*(int *)reversedList.first->value == val5);
  assert(*(int *)reversedList.first->next->value == val4);
  assert(*(int *)reversedList.last->value == val1);
}

void test_of_char_for_reverse(){
  LinkedList list1 = createList();
  char alp1 = 'A', alp2 = 'B', alp3 = 'C', alp4 = 'D', alp5 = 'E';
  add_to_list(&list1,&alp1);
  add_to_list(&list1,&alp2);
  add_to_list(&list1,&alp3);
  add_to_list(&list1,&alp4);
  add_to_list(&list1,&alp5);
  LinkedList reversedList = reverse(list1);
  assert(reversedList.total_ele == 5);
  assert(*(char *)reversedList.first->value == alp5);
  assert(*(char *)reversedList.first->next->value == alp4);
  assert(*(char *)reversedList.last->value == alp1);
}

void test_of_double_for_reverse(){
  LinkedList list1 = createList();
  double val1 = 986325387, val2 = 238975243786, val3 = 238769543, val4 = 832456754356;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  LinkedList reversedList = reverse(list1);
  assert(reversedList.total_ele == 4);
  assert(*(double *)reversedList.first->value == val4);
  assert(*(double *)reversedList.first->next->value == val3);
  assert(*(double *)reversedList.last->value == val1);
}

//--------------------------------------------------------------------------------//

void increment_by(void *inc_val, void *list_ele, void *destItem){
  *(int *)destItem = *(int *)list_ele + *(int *)inc_val;
}

void increment_of_double_by(void *inc_val, void *list_ele, void *destItem){
  *(double *)destItem = *(double *)list_ele + *(double *)inc_val;
}

void test_of_int_for_map(){
  LinkedList list1 = createList();
  int val1 = 11, val2 = 12, val3 = 13, val4 = 15, val5 = 16;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  add_to_list(&list1,&val5);
  LinkedList incrementedList = map(list1,increment_by,&val1);
  assert(incrementedList.total_ele == 5);
  assert(*(int *)incrementedList.first->value == 22);
  assert(*(int *)incrementedList.first->next->value == 23);
  assert(*(int *)incrementedList.last->value == 27);
}

void test_of_char_for_map(){
  LinkedList list1 = createList();
  char alp1 = 'A', alp2 = 'B', alp3 = 'C', alp4 = 'D', alp5 = 'E';
  add_to_list(&list1,&alp1);
  add_to_list(&list1,&alp2);
  add_to_list(&list1,&alp3);
  add_to_list(&list1,&alp4);
  add_to_list(&list1,&alp5);
  int hint = 1;
  LinkedList incrementedList = map(list1,increment_by,&hint);
  assert(incrementedList.total_ele == 5);
  assert(*(char *)incrementedList.first->value == alp2);
  assert(*(char *)incrementedList.first->next->value == alp3);
  assert(*(char *)incrementedList.last->value == 'F');
}

void test_of_double_for_map(){
  LinkedList list1 = createList();
  double val1 = 986325387, val2 = 238975243786, val3 = 238769543, val4 = 832456754356;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  double hint = 3;
  LinkedList incrementedList = map(list1,increment_of_double_by,&hint);
  assert(incrementedList.total_ele == 4);
  assert(*(double *)incrementedList.first->value == 986325390);
  assert(*(double *)incrementedList.last->value == 832456754359);
}

//-----------------------------------------------------------------------------//

void *add_all_nums(void *hint,void *previousValue,void *currentValue){
  *(int *)previousValue += *(int *)currentValue;
  return previousValue;
}

void test_for_int_in_reduce(){
  LinkedList list1 = createList();
  int val1 = 11, val2 = 12, val3 = 13, val4 = 15, val5 = 16;
  add_to_list(&list1,&val1);
  add_to_list(&list1,&val2);
  add_to_list(&list1,&val3);
  add_to_list(&list1,&val4);
  add_to_list(&list1,&val5);
  int initial = 0;
  void *reduced_result = reduce(list1,add_all_nums,&val1,&initial);
  assert(*(int *)reduced_result == 67);
}


// void test_for_char_in_reduce(){
//   LinkedList list1 = createList();
//   char alp1 = 'A', alp2 = 'K', alp3 = 'S', alp4 = 'H', alp5 = 'A', alp6 = 'Y';
//   add_to_list(&list1,&alp1);
//   add_to_list(&list1,&alp2);
//   add_to_list(&list1,&alp3);
//   add_to_list(&list1,&alp4);
//   add_to_list(&list1,&alp5);
//   add_to_list(&list1,&alp6);
//   void *initial = NULL;
//   void *reduced_result = reduce(list1,concat_all_alphabets,&alp1,&initial);
//   // assert(*(char *)reduced_result == 'A');
// }

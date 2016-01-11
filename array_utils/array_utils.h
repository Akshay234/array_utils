#define LENGTH 10

#define TRUE 1
#define FALSE 0

typedef int _match(void *,void *);
typedef void ConvertFunc(void*, void*, void*);
typedef void OperationFunc(void*, void*);
typedef void* ReducerFunc(void*, void*, void*);
typedef struct array{
  void *base;
  int typeSize;
  int length;
}ArrayUtil;

ArrayUtil create(int,int);
ArrayUtil resize(ArrayUtil,int);
int areEqual(ArrayUtil,ArrayUtil);
void dispose(ArrayUtil);
int findIndex(ArrayUtil,void*);
void *findFirst(ArrayUtil,_match* ,void*);
void *findLast(ArrayUtil,_match* ,void*);
int count(ArrayUtil,_match*, void*);
int filter(ArrayUtil,_match*, void*,void **, int);
void map(ArrayUtil, ArrayUtil, ConvertFunc*, void* hint);
void forEach(ArrayUtil, OperationFunc*, void* hint);
void* reduce(ArrayUtil, ReducerFunc*, void*, void*);
void test_for_int();
void test_for_long();
void test_for_float();
void test_for_char();
void test_for_double();
void test_for_areEqual();
void test_for_resize();
void test_for_findIndex();
void test_for_findFirst();
void test_for_findLast();
void test_for_countMatch();
void test_for_filter();
void test_for_map();
void test_for_forEach();
void test_for_reduce();

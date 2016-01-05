#define LENGTH 10

#define TRUE 1
#define FALSE 0

typedef int(_match)(void *,void *);

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
int MatchFunc(void *,void *);
int isDivisible(void*, void*);
int isEven(void *,void*);
void *findFirst(ArrayUtil,_match* mh,void*);
void assert_for_int();
void assert_for_long();
void assert_for_float();
void assert_for_char();
void assert_for_double();
void assert_for_areEqual();
void assert_for_resize();
void assert_for_findIndex();
void assert_for_findFirst();

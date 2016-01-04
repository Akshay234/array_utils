#define LENGTH 10

#define TRUE 1
#define FALSE 0

typedef struct array{
  void *base;
  int typeSize;
  int length;
}ArrayUtil;

int areEqual(ArrayUtil,ArrayUtil);
ArrayUtil create(int,int);
ArrayUtil resize(ArrayUtil,int);
void assert_for_int();
void assert_for_long();
void assert_for_float();
void assert_for_char();
void assert_for_double();
void assert_for_areEqual();

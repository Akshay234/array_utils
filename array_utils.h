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
void assert_for_int(ArrayUtil);
void assert_for_float(ArrayUtil);
void assert_for_char(ArrayUtil);
void assert_for_double(ArrayUtil);

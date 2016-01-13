typedef struct element{
  void *value;
  struct element *next;
} Element;

typedef void (*ElementProcessor)(void *);

typedef struct {
  Element *first;
  Element *last;
  int total_ele;
}LinkedList;

LinkedList createList();
int add_to_list(LinkedList *,void *);
void *get_first_element(LinkedList);
void *get_last_element(LinkedList);
void forEach(LinkedList, ElementProcessor);
void * getElementAt(LinkedList, int);
int indexOf(LinkedList, void *);
void *deleteElementAt(LinkedList *, int);
void test_for_asArray();
int asArray(LinkedList, void **, int);

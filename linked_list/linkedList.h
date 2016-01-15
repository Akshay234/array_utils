typedef int (filterFn)(void *,void *);
typedef void (mapFn)(void *,void *,void *);
typedef void *(reduceFn)(void *,void *,void *);
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
int asArray(LinkedList, void **, int);
LinkedList filter(LinkedList, filterFn, void * );
LinkedList reverse(LinkedList);
LinkedList map(LinkedList, mapFn, void * );
void * reduce(LinkedList, reduceFn, void * ,void *);

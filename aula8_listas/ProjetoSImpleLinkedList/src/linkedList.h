#include <stdbool.h>
#include "node.h"

typedef struct simple_linked_list* List;


List createList();

void destroyList(List list);

bool insertList(List list, Info element);

bool insertAtBeginningList(List list, Info element);

bool insertAtPositionList(List list, int position, Info element);

Info getInfoAt(List list, int position);

bool isEmptyList(List list);

int size(List list);

bool hasElement(List list, Info element);

bool removeAt(List list, int position);

int countKey(List list, Info key);
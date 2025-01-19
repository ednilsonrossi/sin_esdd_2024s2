#include <stdbool.h>
#include "node.h"

typedef struct simple_linked_list* List;


List createList();

void destroyList(List list);

bool insertList(List list, Info element);

Info getInfoAt(List list, int position);

bool isEmptyList(List list);

int size(List list);
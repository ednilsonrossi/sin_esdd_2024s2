#include "node.h"
#include <stdbool.h>

typedef struct linked_list* List;

List create();

void destroy(List list);

bool insert(List list, Info element);

bool insertAtBeggining(List list, Info element);

bool isEmpty(List list);

Info getIntoAt(List list, int position);

int size(List list);
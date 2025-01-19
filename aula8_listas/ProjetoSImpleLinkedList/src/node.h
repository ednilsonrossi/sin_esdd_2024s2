#include <stdlib.h>

typedef struct node* NodePtr;
typedef int Info;

NodePtr createNode();

void destroy(NodePtr node);

void setInfo(NodePtr node, Info element);

void setNext(NodePtr node, NodePtr next);

Info getInfo(NodePtr node);

NodePtr getNext(NodePtr node);
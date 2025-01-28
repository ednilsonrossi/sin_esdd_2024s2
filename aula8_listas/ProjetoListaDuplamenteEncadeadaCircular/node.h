#include <stdlib.h>

typedef struct node* NodePtr;
typedef char* Info;

NodePtr createNode();

void destroyNode(NodePtr node);

NodePtr getPrevious(NodePtr node);

NodePtr getNext(NodePtr node);

Info getInfo(NodePtr node);

void setPrevious(NodePtr node, NodePtr previous);

void setNext(NodePtr node, NodePtr next);

void setInfo(NodePtr node, Info info);
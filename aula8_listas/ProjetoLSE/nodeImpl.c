#include "node.h"

struct node {
    Info element;
    NodePtr next;
};

NodePtr createNode() {
    NodePtr node;
    node = malloc(sizeof(struct node));
    return node;
}

void destroyNode(NodePtr node) {
    free(node);
}

void setInfo(NodePtr node, Info element) {
    if (node != NULL) {
        node->element  = element;
    }
}

void setNext(NodePtr node, NodePtr next) {
    if (node != NULL) {
        node->next = next;
    }
}

Info getInfo(NodePtr node) {
    if (node != NULL){
        return node->element;
    }
    return NULL;
}

NodePtr getNext(NodePtr node) {
    if (node != NULL) {
        return node->next;
    }
    return NULL;
}
#include "node.h"

struct node {
    NodePtr previous;
    Info info;
    NodePtr next;
};

NodePtr createNode() {
    NodePtr node = malloc(sizeof(struct node));
    if (node != NULL) {
        node->previous = NULL;
        node->next = NULL;
        node->info = NULL;
    }
    return node;
}

void destroyNode(NodePtr node) {
    if (node != NULL) {
        free(node);
    }
}

NodePtr getPrevious(NodePtr node) {
    if (node != NULL) {
        return node->previous;
    }
    return NULL;
}

NodePtr getNext(NodePtr node) {
    if (node != NULL) {
        return node->next;
    } else {
        return NULL;
    }
}

Info getInfo(NodePtr node) {
    Info info = NULL;
    if (node != NULL) {
        info = node->info;
    }
    return info;
}

void setPrevious(NodePtr node, NodePtr previous) {
    if (node != NULL) {
        node->previous = previous;
    }
}

void setNext(NodePtr node, NodePtr next) {
    if (node != NULL) {
        node->next = next;
    }
}

void setInfo(NodePtr node, Info info) {
    if (node != NULL) {
        node->info = info;
    }
}
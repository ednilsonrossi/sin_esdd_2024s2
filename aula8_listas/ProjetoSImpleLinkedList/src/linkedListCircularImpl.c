#include "linkedList.h"

struct simple_linked_list {
    NodePtr head;
    int listSize;
};

List createList() {
    List list = malloc(sizeof(struct simple_linked_list));
    list->head = NULL;
    list->listSize = 0;
    return list;
}

void destroyList(List list) {

}

bool insertList(List list, Info element) {
    bool inseriu = false;

    if (list != NULL) {
        NodePtr node = createNode();
        setInfo(node, element);

        if (isEmptyList(list)) {
            list->head = node;
            setNext(node, node);
        } else {
            NodePtr walker = list->head;
            while (getNext(walker) != list->head) {
                walker = getNext(walker);
            }
            setNext(node, getNext(walker));
            setNext(walker, node);
        }
        list->listSize += 1;
        inseriu = true;
    }

    return inseriu;
}

bool insertAtBeginningList(List list, Info element) {
    bool inseriu = false;
    if (list != NULL) {
        NodePtr node = createNode();
        setInfo(node, element);

        if (isEmptyList(list)) {
            list->head = node;
            setNext(node, node);
        } else {
            NodePtr walker = list->head;
            while (getNext(walker) != list->head) {
                walker = getNext(walker);
            }
            setNext(node, getNext(walker));
            setNext(walker, node);
            list->head = node;
        }
        list->listSize += 1;
        inseriu = true;
    }
    return inseriu;
}

bool insertAtPositionList(List list, int position, Info element) {
    return false;
}

Info getInfoAt(List list, int position){
NodePtr andarilho;
    int contador;

    if (list != NULL) {
        if (!isEmptyList(list) && position >= 0 && position <= list->listSize) {
            andarilho = list->head;
            contador = 0;

            while (contador < position && getNext(andarilho) != list->head) {
                andarilho = getNext(andarilho);
                contador += 1;
            }

            if (contador == position) {
                return getInfo(andarilho);
            }
        }
    }

    return NULL;
}

bool isEmptyList(List list) {
    return list->head == NULL;
}

int size(List list) {
    return list->listSize;
}

bool hasElement(List list, Info element) {

}

bool removeAt(List list, int position) {

}

int countKey(List list, Info key) {

}
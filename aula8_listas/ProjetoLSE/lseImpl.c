#include "lse.h"

struct simple_linked_list {
    NodePtr head;
};

List createList() {
    List list = malloc(sizeof(struct simple_linked_list));
    list->head = NULL;
    return list;
}

void destroyList(List list) {
    NodePtr rip, walker;
    if (list != NULL) {
        rip = list->head;
        while(rip != NULL) {
            walker = getNext(rip);
            destroyNode(rip);
            rip = walker;
        }
        free(list);
    }
}

bool insertList(List list, Info element) {
    NodePtr node, walker;
    bool result = false;

    if (list != NULL) {
        /**
         * Lista existe, cria-se um novo node e configura-se as
         * informações (info e next) desse node.
         */
        node = createNode();
        setInfo(node, element);
        setNext(node, NULL);

        if (list->head == NULL) {
            /**
             * Lista está vazia, o node é inserido como primeiro nó
             * da lista.
             */
            list->head = node;
            result = true;
        } else {
            /**
             * Lista não está vazia, procura-se o último node, ou seja, o node cujo
             * campo NEXT aponta para NULL. Econtrado o último node insere-se o novo
             * node na lista ligando o último node (walker) com o novo node.
             */
            walker = list->head;
            while (getNext(walker) != NULL) {
                walker = getNext(walker);
            }
            setNext(walker, node);
            result = true;
        }
    }
    return result;
}

Info getInfoAt(List list, int position) {
    NodePtr walker;
    int counter;

    if (list != NULL) {
        if (position >= 0 && !isEmptyList(list)){
            walker = list->head;
            counter = 0;

            while (counter < position && getNext(walker) != NULL) {
                walker = getNext(walker);
                counter += 1;
            }

            if (counter == position) {
                return getInfo(walker);
            }
        }
    }
    return NULL;
}

bool isEmptyList(List list) {
    bool result = true;
    if (list != NULL) {
        if (list->head != NULL) {
            result = false;
        }
    }
    return result;
}

int size(List list) {
    NodePtr walker;
    int counter = 0;

    if (list != NULL) {
        walker = list->head;
        while(walker != NULL){
            counter += 1;
            walker = getNext(walker);
        }
    }

    return counter;
}
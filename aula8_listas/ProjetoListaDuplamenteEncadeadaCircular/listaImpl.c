#include "lista.h"

struct linked_list {
    NodePtr head;
};

List create() {
    List list = malloc(sizeof(struct linked_list));
    if (list != NULL) {
        list->head = NULL;
    }
    return list;
}

void destroy(List list) {
    if (list != NULL) {
        NodePtr rip = list->head;
        setNext(getPrevious(rip), NULL);
        while (rip != NULL) {
            NodePtr dead = rip;
            rip = getNext(rip);
            destroyNode(dead);
        }
        free(list);
    }
}

bool insert(List list, Info element) {
    bool result = false;
    if (list != NULL) {
        NodePtr node = createNode();
        setInfo(node, element);

        if (isEmpty(list)) {
            list->head = node;
            setNext(node, node);
            setPrevious(node, node);
        } else {
            NodePtr last = getPrevious(list->head);
            setNext(node, list->head);
            setPrevious(list->head, node);
            setNext(last, node);
            setPrevious(node, last);
        }
        result = true;
    }
    return result;
}

bool insertAtBeggining(List list, Info element) {
    if (list != NULL) {
        NodePtr node = createNode();
        setInfo(node, element);

        if (isEmpty(list)) {
            list->head = node;
            setNext(node, node);
            setPrevious(node, node);
        } else {
            NodePtr last = getPrevious(list->head);
            setNext(node, list->head);
            setNext(last, node);
            setPrevious(list->head, node);
            setPrevious(node, last);
            list->head = node;
        }
        return true;
    }
    return false;
}

bool isEmpty(List list) {
    bool empty = false;
    if (list->head == NULL) {
        empty = true;
    }
    return empty;

    // return list->head == NULL;
}

Info getIntoAt(List list, int position) {
    if (list != NULL) {
        if (!isEmpty(list)){
            if (position >= 0) {
                int counter = 0;
                NodePtr walker = list->head;
                while(counter < position && getNext(walker) != list->head) {
                    walker = getNext(walker);
                    counter += 1;
                }

                if (counter == position) {
                    return getInfo(walker);
                } else {
                    return NULL;
                }
            }
        }
    }
    return NULL;
}

int size(List list) {
    if (list != NULL) {
        if (!isEmpty(list)) {
            int counter = 1;
            NodePtr walker = list->head;
            while(getNext(walker) != list->head) {
                counter += 1;
                walker = getNext(walker);
            }
            return counter;
        }
    }
    return 0;
}

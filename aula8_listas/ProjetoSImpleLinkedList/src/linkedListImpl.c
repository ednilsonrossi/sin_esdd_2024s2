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
    NodePtr finado, andarilho;

    if (list != NULL) {
        finado = list->head;
        while (finado != NULL) {
            andarilho = getNext(finado);
            destroy(finado);
            finado = andarilho;
        }
        free(list);
    }
    
}

bool insertList(List list, Info element) {
    NodePtr node, walker;
    bool result = false;

    if (list != NULL) {

        node = createNode();
        setInfo(node, element);
        setNext(node, NULL);

        if (list->head == NULL) {
            list->head = node;
            result = true;
        } else {
            walker = list->head;
            while (getNext(walker) != NULL) {
                walker = getNext(walker);
            }
            setNext(walker, node);
            result = true;
        }

        if (result) {
            list->listSize += 1;
        }
    }

    return result;
}

bool insertAtBeginningList(List list, Info element) {

    if (list != NULL) {
        NodePtr node = createNode();
        setInfo(node, element);
        setNext(node, list->head);
        list->head = node;
        list->listSize += 1;
        return true;
    }
    return false;
}

Info getInfoAt(List list, int position) {
    NodePtr andarilho;
    int contador;

    if (list != NULL) {
        if (!isEmptyList(list) && position >= 0 && position <= list->listSize) {
            andarilho = list->head;
            contador = 0;

            while (contador < position && getNext(andarilho) != NULL) {
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

bool hasElement(List list, Info element) {
    bool achou = false;

    if (list != NULL) {
        if (!isEmptyList(list)){
            NodePtr transeunte = list->head;

            while(!achou && getNext(transeunte) != NULL) {
                if (getInfo(transeunte) == element) {
                    achou = true;
                }
                transeunte = getNext(transeunte);
            }
            
        }
    }

    return achou;
}

bool isEmptyList(List list) {
    return list->head == NULL;
}

int size(List list) {
/*    NodePtr andarilho;
    int contador = 0;

    if (list != NULL) {
        andarilho = list->head;
        while (andarilho != NULL) {
            contador += 1;
            andarilho = getNext(andarilho);
        }
        
    }

    return contador;
*/
    return list->listSize;
}

bool removeAt(List list, int position) {
    NodePtr caramelo, andarilho;
    int contador;
    bool removeu = false;
    
    if (list != NULL) {
        if ( !isEmptyList(list) ) {
            if (position < list->listSize) {

                if (position == 0) {
                    // Apagar o primeiro node
                    andarilho = list->head;
                    list->head = getNext(andarilho);
                    destroy(andarilho);
                    removeu = true;
                } else {
                    // Apagar um node do meio ou final da lista
                    caramelo = NULL;
                    andarilho = list->head;
                    contador = 0;

                    while (contador < position && getNext(andarilho) != NULL) {
                        caramelo = andarilho;
                        andarilho = getNext(andarilho);
                        contador += 1;
                    }

                    setNext(caramelo, getNext(andarilho));
                    destroy(andarilho);
                    removeu = true;
                }

            }
        }
    }
    if (removeu) {
        list->listSize --;
    }

    return removeu;
}










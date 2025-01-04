#include <stdlib.h>

typedef struct node* NodePtr;
typedef int Info;

/**
 * Aloca espaço em memória para armazenar um NodePtr. A operação
 * retorna o endereço de memória alocado ou NULL caso ocorra 
 * algum erro.
 */
NodePtr createNode();

/**
 * Libera o endereço de memória utilizado pelo NodePtr.
 */
void destroyNode(NodePtr node);

/**
 * Altera o campo INFORMAÇÃO do NodePtr passado como argumento
 * para a operação.
 */
void setInfo(NodePtr node, Info element);

/**
 * Altera o campo PRÓXIMO do NodePtr passado como argumento
 * para a operação.
 */
void setNext(NodePtr node, NodePtr next);

/**
 * Retorna o valor do campo INFORMAÇÃO do NodePtr passado como
 * argumento.
 */
Info getInfo(NodePtr node);

/**
 * Retorno o endereço do node que o NodePtr armazena no campo NEXT.
 */
NodePtr getNext(NodePtr node);

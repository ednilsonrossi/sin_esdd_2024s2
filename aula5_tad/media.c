#include <stdio.h>

int main(){
    int media = 0, num, n = 0;
    char para;
    do{
        printf("Insira um valor: ");
        scanf("%d", &num);
        media += num;
        printf("Digite s se deseja continuar:");
        scanf(" %c",&para);
        n++;
    }while(para=='s' || para=='S');
    media = media/n;
    printf("%d\n",media);
}
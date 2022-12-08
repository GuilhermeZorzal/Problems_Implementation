#include <stdio.h>
#include <stdlib.h>

int cont(int *a){
    *(a) += 2;
    return 0;
}

int main(){
    int a;
    a = 1;
    cont(&a);
    printf("%d",a);
    return 0;
}
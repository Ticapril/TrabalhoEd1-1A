#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main(void){
    int *p;

    printf("%3d", p);
    printf("%3d", &p);
    printf("%3d", *p);
}

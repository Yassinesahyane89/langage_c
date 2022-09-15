#include <stdio.h>
#include <stdlib.h>

struct test{
    char c;
    float x;
    int y;
};

void f(struct test z){
   struct test *P = &z;
   P->c++;
   P->x+=2;
   P->y++;
   printf("%c %.2f %d \n",P->c,P->x,P->y);
}

int main()
{
 struct test Z;
 Z.c='a';
 Z.x=12.5;
 Z.y=4;
 f(Z);
 printf("%c %.2f %d \n",Z.c,Z.x,Z.y);
}

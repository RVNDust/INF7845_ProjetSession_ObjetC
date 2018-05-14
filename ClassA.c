#include<stdlib.h>
#include<stdio.h>
 
#include "ClassA.h" 

struct ClassA_VT VT_A = {1, &HT_A, &A_foo, &A_bar, &A_setX, &A_getX};
void* HT_A[] = {&VT_A};

ClassA* new_ClassA()
{
    ClassA* a = malloc(sizeof(ClassA));
    a->vt = &VT_A;
    a->x = 0;
    return a;
}

void A_foo(struct ClassA *This)
{
    This->x = This->x+10;
}

void A_bar(struct ClassA *This)
{
    This->x = This->x-10;
}

void A_setX(struct ClassA *This, int _value)
{
    This->x = _value;
}

int A_getX(struct ClassA *This)
{
    return This->x;
}
#include<stdlib.h>
#include<stdio.h>
 
#include "ClassA.h" 

struct ClassA_VT* VT_A = NULL;
void *HIERARCHICALTREE_A[10];

ClassA* new_ClassA()
{
    ClassA* a = malloc(sizeof(ClassA));
    a->vt = VT_A;
    a->x = 0;
    return a;
}

ClassA_VT* new_ClassA_VT(void)
{
    ClassA_VT* vt_a = malloc(sizeof(ClassA_VT));
    vt_a->hierarchicalLevel = 1;
    vt_a->foo = &A_foo;
    vt_a->bar = &A_bar;
    vt_a->setX = &A_setX;
    vt_a->getX = &A_getX;
    return vt_a;
}

void init_ClassA()
{
    if(VT_A == NULL)
    { 
        printf("INIT A OK\n");
        ClassA_VT* vt_a = new_ClassA_VT();
        VT_A = vt_a;
        HIERARCHICALTREE_A[VT_A->hierarchicalLevel] = VT_A;
        VT_A->hierarchicalTree = &HIERARCHICALTREE_A;
    }
    else
    {
        printf("INIT A ABORT");
    }
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
#include<stdlib.h>
#include<stdio.h>
 
#include "ClassA.h"
#include "ClassB.h" 

struct ClassB_VT* VT_B = NULL;

ClassB_VT* new_ClassB_VT(void)
{
    ClassB_VT* vt_b = malloc(sizeof(ClassB_VT));
    vt_b->hierarchicalLevel = 2;
    vt_b->foo = &B_foo;
    vt_b->bar = &A_bar;
    vt_b->setX = &A_setX;
    vt_b->getX = &A_getX;
    vt_b->baz = &B_baz;
    vt_b->setY = &B_setY;
    vt_b->getY = &B_getY;
    return vt_b;
}

ClassB* new_ClassB()
{
    ClassB* b = malloc(sizeof(ClassB));
    b->vt = VT_B;
    b->x = 0;
    b->y = 0;
    return b;
}

void init_ClassB()
{
    if(VT_B == NULL)
    {
        ClassB_VT* vt_b = new_ClassB_VT();
        VT_B = vt_b;
        HIERARCHICALTREE_A[VT_B->hierarchicalLevel] = VT_B;
        VT_B->hierarchicalTree = &HIERARCHICALTREE_A;
    }
}

void B_foo(struct ClassB *This)
{
    This->y = This->y+15;
}

void B_baz(struct ClassB *This)
{
    printf("x:%d y:%d\n", This->vt->getX((ClassA*)This), This->vt->getY(This));
}

void B_setY(struct ClassB *This, int _value)
{
    This->y = _value;
}

int B_getY(struct ClassB *This)
{
    return This->y;
}
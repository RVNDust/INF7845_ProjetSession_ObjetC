#include<stdlib.h>
#include<stdio.h>
 
#include "ClassC.h" 

struct ClassC_VT* VT_C = NULL;
void *HIERARCHICALTREE_C[10];

ClassC* new_ClassC()
{
    ClassC* c = malloc(sizeof(ClassC));
    c->vt = VT_C;
    return c;
}

ClassC_VT* new_ClassC_VT(void)
{
    ClassC_VT* vt_c = malloc(sizeof(ClassC_VT));
    vt_c->hierarchicalLevel = 1;
    vt_c->bar = &C_bar;
    return vt_c;
}

void init_ClassC()
{
    if(VT_C == NULL)
    { 
        ClassC_VT* vt_c = new_ClassC_VT();
        VT_C = vt_c;
        HIERARCHICALTREE_C[VT_C->hierarchicalLevel] = VT_C;
        VT_C->hierarchicalTree = &HIERARCHICALTREE_C;
    }
    else
    {
        printf("INIT C ABORT");
    }
}

void C_bar(struct ClassC *This)
{
    printf("Je suis C");
}
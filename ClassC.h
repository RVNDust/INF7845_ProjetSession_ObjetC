#ifndef CLASSC_H
#define CLASSC_H

extern void *HIERARCHICALTREE_C[10];

typedef struct ClassC
{
    //Table virtuelle
    struct ClassC_VT (*vt);
    //Attributs
    int x;

} ClassC ;

typedef struct ClassC_VT
{
    int hierarchicalLevel;
    void* (*hierarchicalTree)[10];
    void (*bar)(struct ClassC*);
} ClassC_VT ;

ClassC* new_ClassC();
ClassC_VT* new_ClassC_VT();
void init_ClassC();

void C_bar(struct ClassC*);
#endif CLASSC_H
#ifndef CLASSA_H
#define CLASSA_H

extern struct ClassA_VT VT_A;
extern void *HT_A[];

typedef struct ClassA
{
    //Table virtuelle
    struct ClassA_VT (*vt);
    //Attributs
    int x;

} ClassA ;

typedef struct ClassA_VT
{
    int hl;
    void* (*ht)[];
    void (*foo)(struct ClassA*);
    void (*bar)(struct ClassA*);
    void (*setX)(struct ClassA*, int _value);
    int (*getX)(struct ClassA*);
} ClassA_VT ;

ClassA* new_ClassA();
ClassA_VT* new_ClassA_VT();
void init_ClassA();

void A_foo(struct ClassA*);
void A_bar(struct ClassA*);
void A_setX(struct ClassA*, int _value);
int A_getX(struct ClassA*);
#endif CLASSA_H
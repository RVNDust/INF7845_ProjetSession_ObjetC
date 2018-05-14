#ifndef CLASSB_H
#define CLASSB_H

extern struct ClassB_VT VT_B;
extern void *HT_B[];

typedef struct ClassB
{
    //Table virtuelle
    struct ClassB_VT (*vt);
    //Attributs
    int x;
    int y;

} ClassB ;

typedef struct ClassB_VT
{
    int hl;
    void* (*ht)[];
    void (*foo)(struct ClassB*);
    void (*bar)(struct ClassA*);
    void (*setX)(struct ClassA*, int _value);
    int (*getX)(struct ClassA*);
    void (*baz)(struct ClassB*);
    void (*setY)(struct ClassB*, int _value);
    int (*getY)(struct ClassB*);
} ClassB_VT ;

ClassB_VT* new_ClassB_VT();
ClassB* new_ClassB();
void init_ClassB();

void B_foo(struct ClassB*);
void B_baz(struct ClassB*);
void B_setY(struct ClassB*, int _value);
int B_getY(struct ClassB*);

#endif CLASSB_H
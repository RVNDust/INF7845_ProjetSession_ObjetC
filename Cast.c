#include<stdlib.h>
#include<stdio.h>

#include "Cast.h"
#include "ClassA.h" 
#include "ClassB.h"

ClassB* cast_A_as_B(ClassA* _objet)
{
    if(_objet->vt->hl >= VT_B->hl) //Verifying that the hierarchical level is superior or equal - 1 mean root, more than 1 is a children
    {
        if(_objet->vt->ht[VT_B->hl] == VT_B->ht[VT_B->hl]) //Verifying that the references are the same, means that the object to convert is at least an object of the same class (target class)
        {
            return (ClassB*)_objet;
        }
        else
        {
            printf("CAST IMPOSSIBLE, HIERACHIES DIFFERENTES, LE PARAMETRE FOURNI N'EST PAS VALIDE.\n");
            return NULL;
        }
    }
    else
    {
        printf("CAST IMPOSSIBLE, CLASSE DE NIVEAU IDENTIQUE OU SUPERIEUR.\n");
        return NULL;
    }
}

ClassA* cast_B_as_A(ClassB* _objet)
{
    return (ClassA*)_objet;
}
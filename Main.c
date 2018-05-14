
#include <stdlib.h>
#include <stdio.h>

#include "Cast.h"
#include "ClassA.h"
#include "ClassB.h"
#include "ClassC.h"
#include "LinkedList.h"
#include "LinkedListNode.h"

void init()
{
        //Préparation des différentes classes à utiliser
        //init_ClassA();
        //init_ClassB();
        init_ClassC();
        init_linked_list();
}

int main()
{
        printf("DEMARAGE PROGRAMME\n");
        //Appel à Init, préparation des objets
        init();

        //Utilisation des classes A & B
        ClassA* a = new_ClassA();
        a->vt->setX(a, 0);
        printf("%d\n", a->vt->getX(a));
        a->vt->foo(a);
        printf("%d\n", a->vt->getX(a));
        a->vt->bar(a);
        printf("%d\n", a->vt->getX(a));

        ClassB* b = new_ClassB();
        b->vt->setX((ClassA*)b, 50);
        b->vt->setY(b, -5);
        b->vt->baz(b);
        b->vt->foo(b);
        b->vt->baz(b);
        b->vt->bar((ClassA*)b);
        b->vt->baz(b);

        //Démo héritage simple
        ClassA* a2 = cast_B_as_A(new_ClassB());
        a2->vt->setX(a2, 0);
        printf("%d\n", a2->vt->getX(a2));
        a2->vt->foo(a2);
        printf("%d\n", a2->vt->getX(a2));
        a2->vt->bar(a2);
        printf("%d\n", a2->vt->getX(a2));
        
        //Test cast safe
        // ClassB* b2 = cast_A_as_B(a2);
        // b2->vt->setY(b2, 50);
        // b2->vt->baz(b2);
        //Test cast unsafe
        // ClassC* c = new_ClassC();
        // b2 = (ClassB*)c;
        // a2 = cast_B_as_A(b2);
        // b2 = cast_A_as_B(a2);

        // //Utilisation d'une liste chainée - Tests des méthodes en cours
        // linked_list* ll = new_linked_list();
        // int* value = malloc(sizeof(int));
        // int value1 = 1; int value2 = 5; int value3 = 10;
        // value = &value1;
        // ll->vt->push(ll, value);
        // value = &value2;
        // ll->vt->push(ll, value);
        // value = &value3;
        // ll->vt->push(ll, value);

        // int* getValue = (int*)ll->vt->get_data(ll, 1);
        // printf("x:%d\n", *getValue);
        // getValue = (int*)ll->vt->get_data(ll, 2);
        // printf("x:%d\n", *getValue);
        // getValue = (int*)ll->vt->get_data(ll, 3);
        // printf("x:%d\n", *getValue);


        printf("FIN PROGRAMME\n");
        #ifdef __WIN32__
                system("PAUSE");
        #endif
                return 0;
}
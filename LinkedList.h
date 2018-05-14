#ifndef LINKEDLIST_H
#define LINKEDLIST_H

/* Head of a list */
typedef struct linked_list {
    struct linked_list_VT (*vt);
    unsigned int length;
    struct linked_list_node* first;
} linked_list;

/* Virtual Table of the LinkedList */
typedef struct linked_list_VT {
    void* (*get_data)(struct linked_list*, int _index);
    unsigned int (*length)(struct linked_list*);
    void (*clear)(struct linked_list*);
    void (*push)(struct linked_list*, void *_data);
    void (*remove_last)(struct linked_list*);
    void (*remove_at)(struct linked_list*,int _index);
    void (*insert_at)(struct linked_list*,int _index, void *_data);
} linked_list_VT;

/* Méthode d'instanciations des structures */
linked_list_VT* new_linked_list_VT();
linked_list* new_linked_list();
void init_linked_list();

/* Méthodes de la virtual table */
void* LL_data(struct linked_list*, int _index);
unsigned int LL_length(struct linked_list*);
void LL_clear(struct linked_list*);
void LL_push(struct linked_list*, void *_data);
void LL_remove_last(struct linked_list*);
void LL_remove_at(struct linked_list*, int _index);
void LL_insert_at(struct linked_list*, int _index, void *_data);
#endif LINKEDLIST_H
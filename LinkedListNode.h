#ifndef LINKEDLISTNODE_H
#define LINKEDLISTNODE_H

/* A node of this list */
typedef struct linked_list_node {
    struct linked_list_node* next;
    void* data;
} linked_list_node;

linked_list_node* new_linked_list_node(void *_data);
void* free_linked_list_node(struct linked_list_node*);

#endif LINKEDLISTNODE_H
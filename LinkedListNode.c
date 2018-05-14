#include<stdlib.h>
#include<stdio.h>

#include "LinkedListNode.h"

linked_list_node* new_linked_list_node(void *_data)
{
    linked_list_node* ll_node = malloc(sizeof(linked_list_node));
    ll_node->data = _data;
    ll_node->next = NULL;
    return ll_node;
}

void* free_linked_list_node(linked_list_node *_node)
{
    if(_node->next == NULL)
    {
        void* returnData = _node->data;
        _node->data = NULL;
        free(_node);
        return returnData;
    }
    return NULL;
}
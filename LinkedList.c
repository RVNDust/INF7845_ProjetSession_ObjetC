#include<stdlib.h>
#include<stdio.h>

#include "LinkedListNode.h"

#include "LinkedList.h"

struct linked_list_VT* VT_LL = NULL;

/* Méthode d'instanciations des structures */
linked_list* new_linked_list()
{
    linked_list* ll = malloc(sizeof(linked_list));
    ll->vt = VT_LL;
    ll->length = 0;
    ll->first = NULL;
    return ll;
}

linked_list_VT* new_linked_list_VT()
{
    linked_list_VT* ll_vt = malloc(sizeof(linked_list_VT));
    ll_vt->get_data = &LL_data;
    ll_vt->length = &LL_length;
    ll_vt->clear = &LL_clear;
    ll_vt->push = &LL_push;
    ll_vt->remove_last = &LL_remove_last;
    ll_vt->remove_at = &LL_remove_at;
    ll_vt->insert_at = &LL_insert_at;
    return ll_vt;
}

void init_linked_list()
{
    if(VT_LL == NULL)
    {
        linked_list_VT* vt_ll = new_linked_list_VT();
        VT_LL = vt_ll;
    }
}
/* Méthodes de la virtual table */

//Permet de récupérer les données contenues dans le noeud à l'index donné
void* LL_data(linked_list* _this, int _index)
{
    linked_list_node* node = NULL;
    unsigned int length = _this->vt->length(_this);
    if(length >= _index)
        node = new_linked_list_node(NULL);
        node = _this->first;
        for(int i=0; i < _index-1; i++)
        {
        node = node->next;
        }
        return node->data;
     //Gérer les cas de dépassement d'index avec un message pour l'utilisateur
}

//Permet d'obtenir la longueur de la liste, celle-ci est mise à jour à chaque opération d'ajout ou de retrait d'éléments
unsigned int LL_length(linked_list* _this)
{
    return _this->length;
}

void LL_clear(linked_list* _this)
{
    while(_this->first != NULL)
    {
        _this->vt->remove_last(_this);
    }
}

void LL_push(linked_list* _this, void *_data)
{
    linked_list_node* new_node = NULL;
    linked_list_node* node = NULL;
    if(_this->first != NULL)
    {
        printf("Others !\n");
        node = _this->first;
        while(node->next != NULL)
        {
            node = node->next;
        }
        new_node = new_linked_list_node(_data);
        node->next = new_node;
        _this->length = _this->length + 1;
    }
    else
    {
        printf("First !\n");
        new_node = new_linked_list_node(_data);
        _this->first = new_node;
        _this->length = _this->length + 1;
    }
}

void LL_remove_last(linked_list* _this)
{
    if(_this->length > 1)
    {
        linked_list_node* node = _this->first;
        linked_list_node* prev_node = NULL;
        for(int i=0; i < _this->length; i++)
        {
            prev_node = node;
            node = node->next;
        }
        prev_node->next = NULL; //Suppression du lien entre l'avant dernier et le dernier noeud
        free_linked_list_node(node); //Désallocation du dernier noeud
        _this->length = _this->length - 1; //Ajustement de la longueur de la liste
    }
    else if(_this->length == 1)
    {
        linked_list_node* node = _this->first;
        _this->first = NULL;
        free_linked_list_node(node);
        _this->length = _this->length - 1; //Ajustement de la longueur de la liste
    }
}

//Permet de supprimer le noeud qui se trouve à l'index fourni
//Retourne une référence aux data qui étaient dans le noeud
void LL_remove_at(linked_list* _this, int _index)
{
    //Declarations variables locales
    linked_list_node* node = NULL;
    linked_list_node* prev_node = NULL;
    linked_list_node* next_node = NULL;
    if(_this->vt->length(_this) >= _index)
     node = _this->first;
     next_node = node->next;
     for(int i=0; i < _index-1; i++)
     {
        prev_node = node;
        node = node->next;
        next_node = node->next;
     }
     void* data = node->data;
     prev_node->next = next_node;
     node->next = NULL; //Séparation du noeud avec le reste de la liste
     free_linked_list_node(node); //Suppression du noeud
     _this->length = _this->length - 1; //Ajustement longueur liste
     //Gérer les cas de dépassement d'index avec un message pour l'utilisateur
}

void LL_insert_at(linked_list *_this, int _index, void *_data)
{    
     linked_list_node* node = NULL;
     linked_list_node* prev_node = NULL;
    if(_this->vt->length(_this) >= _index)
     node = _this->first;
     for(int i=0; i < _index-1; i++)
     {
        prev_node = node;
        node = node->next;
     }
     linked_list_node* new_node = new_linked_list_node(_data);
     prev_node->next = new_node;
     new_node->next = node;
     _this->length = _this->length + 1;
     //Gérer les cas de dépassement d'index avec un message pour l'utilisateur
}

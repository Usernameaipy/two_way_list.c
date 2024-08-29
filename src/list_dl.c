#include "list_dl.h"

struct node* init(int var){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->pref=NULL;
    root->next=NULL;
    root->variable=var;
    return root;
}

struct node* insert(struct node* root, int var){
    int trig=0;
    struct node* elem=init(var);
    if(root==NULL){
        trig=1;
    }
    if(trig==0){
        struct node* root_cp=root;
        while(root_cp->next!=NULL){
            root_cp=root_cp->next;
        }
        root_cp->next=elem;
        elem->pref=root_cp;
    }
    return elem;
}

struct node* insert_after(struct node* root, struct node* elem, int var){
    struct node* root_cp = root;
    while(root_cp!=elem || root_cp!=NULL){
        root_cp=root_cp->next;
    }
    if(root_cp!=NULL){
        struct node* next_elem = root_cp->next;
        struct node* new_elem = init(var);
        new_elem->next=next_elem;
        new_elem->pref=root_cp;
        root_cp->next=new_elem;
    }
    return root_cp;
}
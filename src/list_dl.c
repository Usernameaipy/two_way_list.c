#include "list_dl.h"

struct node* init(int var){
    struct node* root=(struct node*)malloc(sizeof(struct node));
    root->pref=NULL;
    root->next=NULL;
    root->variable=var;
    return root;
}

struct node* add(struct node* root, int var){
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
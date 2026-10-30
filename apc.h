#ifndef APC_H
#define APC_H

#include<stdio.h>


typedef struct node
{
    int data;
    struct node *prev;
    struct node *next;
}Dlist;

#endif


void remove_leading_zeros(Dlist **head, Dlist **tail);
int list_compare(Dlist *head1,Dlist *head2);
void Insert_last(Dlist **head,Dlist **tail,int data);
void Insert_first(Dlist **head,Dlist **tail,int data);
void delete_list(Dlist **head, Dlist **tail);
void addition(Dlist *hea1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
void substraction(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
void multiplication(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
void division(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);

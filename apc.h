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
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"apc.h"

int list_compare(Dlist *head1,Dlist *head2);
void Insert_last(Dlist **head,Dlist **tail,int data);
void Insert_first(Dlist **head,Dlist **tail,int data);
void delete_list(Dlist **head, Dlist **tail);
void addition(Dlist *hea1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
void substraction(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);
void multiplication(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR);

int main(int argc,char *argv[])
{
    if(argc!=4)
    {
        printf("Invalid Arguments\n");
        return 1;
    }
    Dlist *head1=NULL;
    Dlist *tail1=NULL;

    Dlist *head2=NULL;
    Dlist *tail2=NULL;
    
    Dlist *headR=NULL;
    Dlist *tailR=NULL;
    int i=0;
    char *str1=argv[1];
    while(str1[i]!='\0')
    {
        int data=str1[i]-'0';
        Insert_last(&head1,&tail1,data);
        i++;
    }

    i=0;
    char *str2=argv[3];
    while(str2[i]!='\0')
    {
        int data=str2[i]-'0';
        Insert_last(&head2,&tail2,data);
        i++;

    }
    int negative=0;
    if(strcmp(argv[2],"+")==0)
    {
        addition(head1,tail1,head2,tail2,&headR,&tailR);
    }
    else if(strcmp(argv[2],"-")==0)
    {

        if(list_compare(head1,head2)==1)
        {
            substraction(head1,tail1,head2,tail2,&headR,&tailR);
        }
        else
        {
            substraction(head2,tail2,head1,tail1,&headR,&tailR);
            negative=1;
        }
    }
    else if(strcmp(argv[2],"x")==0)
    {
        multiplication(head1,tail1,head2,tail2,&headR,&tailR);
    }
    else if(strcmp(argv[2],"/")==0)
    {
        //division(head1,tail1,head2,tail2,&headR,&tailR);
    }
    else{
        printf("Invalid operator\n");
        return 1;
    }

    Dlist *temp=headR;
    printf("result\n");
    if(negative==1)
    {
        printf("-");
    }
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
    
    return 0;

}


void Insert_last(Dlist **head,Dlist **tail,int data)
{
    Dlist *new_node=malloc(sizeof(Dlist));
    if(new_node==NULL)
    {
        printf("Memory not allocated\n");
        return;
    }
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=NULL;
    if(*head==NULL)
    {
        *head=new_node;
        *tail=new_node;
        return;
    }

    new_node->prev=*tail;
    (*tail)->next=new_node;
    *tail=new_node;
}

void Insert_first(Dlist **head,Dlist **tail,int data)
{
    Dlist *new_node=malloc(sizeof(Dlist));
    if(new_node==NULL)
    {
        printf("Memory not allocated\n");
        return;
    }
    new_node->data=data;
    new_node->prev=NULL;
    new_node->next=NULL;
    if(*head==NULL)
    {
        *head=new_node;
        *tail=new_node;
        return;
    }

    new_node->next=*head;
    (*head)->prev=new_node;
    *head=new_node;
}

void delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp=*head;
    while(temp!=NULL)
    {
        *head=temp->next;
        free(temp);
        temp=*head;
    }
    
}


int list_compare(Dlist *head1,Dlist *head2)
{
    int list1_count=0,list2_count=0;
    Dlist *temp1=head1;
    Dlist *temp2=head2;
    while(temp1!=NULL)
    {
        list1_count++;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        list2_count++;
        temp2=temp2->next;
    }
    if(list1_count>list2_count)
    {
        return 1;
    }
    else if(list1_count<list2_count)
    {
        return 0;
    }
    else{
        temp1=head1;
        temp2=head2;
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->data >temp2->data)
            {
                return 1;
            }
            else if(temp1->data < temp2->data)
            {
                return 0;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
    }

    return 1;

}

void addition(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    Dlist *temp1=tail1;
    Dlist *temp2=tail2;
    int carry=0,data;
    int num1,num2;
    while(temp1!=NULL || temp2!=NULL)
    {
        if(temp1!=NULL)
        {
            num1=temp1->data;
            temp1=temp1->prev;
        }
        else{
            num1=0;
        }
        if(temp2!=NULL)
        {
            num2=temp2->data;
            temp2=temp2->prev;
        }
        else
        {
            num2=0;
        }
        data=num1+num2+carry;
        carry=data/10;
        Insert_first(headR,tailR,data%10);
    }
    if(carry)
    {
        Insert_first(headR,tailR,carry);
    }
}

void substraction(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    Dlist *temp1=tail1;
    Dlist *temp2=tail2;
    int borrow=0,data;
    int num1,num2;
    while(temp1!=NULL || temp2!=NULL)
    {
        if(temp1!=NULL)
        {
            num1=temp1->data;
            temp1=temp1->prev;
        }
        else{
            num1=0;
        }
        if(temp2!=NULL)
        {
            num2=temp2->data;
            temp2=temp2->prev;
        }
        else{
            num2=0;
        }
        num1=num1-borrow;
        if(num1<num2)
        {
            num1=num1+10;
            borrow=1;
        }
        else{
            borrow=0;
        }
        data=num1-num2;
        Insert_first(headR,tailR,data);
    }
    while((*headR)->data==0 && (*headR)->next!=NULL)
    {
        Dlist *temp=*headR;
        *headR=(*headR)->next;
        (*headR)->prev=NULL;
        free(temp);
    }
}

void multiplication(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2,Dlist **headR,Dlist **tailR)
{
    Dlist *headR1=NULL;
    Dlist *headR2=NULL;
    Dlist *tailR1=NULL;
    Dlist *tailR2=NULL;

    Dlist *temp1;
    Dlist *temp2=tail2;
    int count=0,carry,num1,num2,data;
    while(temp2!=NULL)
    {
        temp1=tail1;
        carry=0;
        while(temp1!=NULL)
        {
            num1=temp1->data;
            num2=temp2->data;

            data=(num1*num2)+carry;
            carry=data/10;
            Insert_first(&headR2,&tailR2,data%10);
            temp1=temp1->prev;
        }
        if(carry!=0)
        {
            Insert_first(&headR2,&tailR2,carry);
        }
        for(int i=0;i<count;i++)
        {
            Insert_last(&headR2,&tailR2,0);
        }
        if(count==0)
        {
            headR1=headR2;
            tailR1=tailR2;

            headR2=NULL;
            tailR2=NULL;
        }
        else
        {
            addition(headR1,tailR1,headR2,tailR2,headR,tailR);

            delete_list(&headR1,&tailR1);
            delete_list(&headR2,&tailR2);

            headR1=*headR;
            tailR1=*tailR;

            *headR=NULL;
            *tailR=NULL;
        }
        temp2=temp2->prev;
        count++;
   }
   *headR=headR1;
   *tailR=tailR1;
}
#pragma once
#include "stdlib.h"
#include "stdio.h"
typedef struct doulink
{
    doulink* prior;
    int data;
    doulink* next;
}doulink;
doulink* initLine(doulink * head)
{
    head = (doulink*)malloc(sizeof(doulink));
    head->next = NULL;
    head->prior = NULL;
    head->data = 1;
    doulink * list=head;
    for (size_t i = 2; i < 4; i++)
    {
        doulink * body=(doulink*)malloc(sizeof(doulink));
        body->prior = NULL;
        body->next = NULL;
        body->data = i;

        list->next = body;
        body->prior = list;
        list = list->next;

    }
    return head;
}

void display(doulink * head){
    doulink * temp=head;
    while (temp) {
        //如果该节点无后继节点，说明此节点是链表的最后一个节点
        if (temp->next==NULL) {
            printf("%d\n",temp->data);
        }else{
            printf("%d <-> ",temp->data);
        }
        temp=temp->next;
    }
}
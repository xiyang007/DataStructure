#pragma once
#include "stdio.h"
#include "stdlib.h"
typedef struct Link
{
    int elem;
    Link* next;
}Link;

Link* InitLink()
{
    Link* p = (Link*)malloc(sizeof(Link));
    Link* temp = p;
    temp->elem = 1;
    temp->next = NULL;
    for (size_t i = 2; i < 5; i++)
    {
        Link *a= (Link*)malloc(sizeof(Link));
        a->elem = i;
        a->next=NULL;
        temp->next = a;
        temp = temp->next;
    }
    
    return p;
}

void Display(Link* p)
{
    Link* temp = p;
    while (temp)
    {
        printf("%d", temp->elem);
        temp = temp->next;
    }
    printf("\n");
}

Link* InsertE(Link* p, int elem, int addIndex)
{
    Link* temp = p;
    for (size_t i = 0; i < addIndex; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("ilegal\n");
            return p;
        }
    }
    Link* c = (Link*)malloc(sizeof(Link));
    c->elem = elem;
    c->next = temp->next;
    temp->next = c;
    return p;
}

Link* DeleteLink(Link* p, int deIndex)
{
    Link* temp = p;
    for (size_t i = 1; i < deIndex; i++)
    {
        temp = temp->next;
        if (temp == NULL)
        {
            printf("ilegal\n");
            return p;
        }
    }
    Link* del = temp->next;
    temp->next = temp->next->next;
    free(del);
    return p;
}

int SelectLink(Link* p, int elem)
{
    Link * t=p;
    int i=1;
    //由于头节点的存在，因此while中的判断为t->next
    while (t->next) {
        t=t->next;
        if (t->elem==elem) {
            return i;
        }
        i++;
    }
    return -1;
}

Link * ModifyLink(Link * p, int add, int newElem)
{
    Link * temp = p->next;
    for (int i=1; i<add; i++) 
    {
        temp=temp->next;
        if (temp == NULL)
        {
            printf("ilegal\n");
            return p;
        }
    }
    temp->elem = newElem;
    return p;//如果查找失败，返回-1
}
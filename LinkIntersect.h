#pragma once
#include "link.h"

bool LinkIntersect(Link * L1, Link * L2)
{
    Link * p1 = L1;
    Link * p2 = L2;
    while (p1)
    {
        while (p2)
        {
            if (p1==p2)
            {
                return true;
            }
            p2= p2->next;
        }
        p1 = p1->next;
    }

    // Link * p1 = L1;
    // Link * p2 = L2;
    // //找到 L1 链表中的最后一个节点
    // while (p1->next) {
    //     p1 = p1->next;
    // }
    // //找到 L2 链表中的最后一个节点
    // while (p2->next)
    // {
    //     p2 = p2->next;
    // }
    // //判断 L1 和 L2 链表最后一个节点是否相同
    // if (p1 == p2) {
    //     return true;
    // }
    return false;
}

bool LinkIntersectV2(Link * L1, Link * L2) 
{
    Link * plong = L1;
    Link * pshort = L1;
    Link * temp = NULL;
    int num1 = 0, num2 = 0, step = 0;

    //得到 L1 的长度
    while (plong) {
        num1++;
        plong = plong->next;
    }
    //得到 L2 的长度
    while (pshort)
    {
        num2++;
        pshort = pshort->next;
    }
    //重置plong和pshort，使plong代表较长的链表，pshort代表较短的链表
    plong = L1;
    pshort = L2;
    step = num1 - num2;
    if (num1 < num2) {
        plong = L2;
        pshort = L1;
        step = num2 - num1;
    }
    //在plong链表中找到和pshort等长度的子链表
    temp = plong;
    while (step) {
        temp = temp->next;
        step--;
    }
        //逐个比较temp和pshort链表中的节点是否相同
    while (temp && pshort) {
        if (temp == pshort) {
            return true;
        }
        temp = temp->next;
        pshort = pshort->next;
    }
    return false;
}
#pragma once
#include "link.h"

// //no head
// Link* reverse_link_no_head(Link* p)
// {
//     if (p == NULL || p->next == NULL)
//     {
//         return p;
//     }
//     Link* begin = NULL;
//     Link* mid = p;
//     Link* end = p->next;
//     while (end)
//     {
//         mid->next = begin;
//         if (end == NULL)
//         {
//             break;
//         }
        
//         begin = mid;
//         mid = end;
//         end = end->next;
//     }
//     p = mid;
//     return p;
// }

Link* iteration_reverse(Link* p)
{
    if (p == NULL || p->next == NULL)
    {
        return p;
    }
    Link* beg = NULL;
    Link* mid = p;
    Link* end = p->next;
    while (end)
    {
        //修改 mid 所指节点的指向
        mid->next = beg;
        //整体向后移动 3 个指针
        beg = mid;
        mid = end;
        end = end->next;        
    }
    //最后修改 head 头指针的指向
    mid->next = beg;
    p = mid;
    return p;
}

// Link* reverse_link_no_head_V2(Link* p)
// {
//     Link * new_head = NULL;
//     Link * temp = NULL;
//     if (p == NULL || p->next == NULL) {
//         return p;
//     }
//     while (p != NULL)
//     {
//         //del temp in p
//         temp = p;
//         p = p->next;
//         //update temp to new head
//         temp->next = new_head;
//         new_head = temp;
//     }
//     return new_head;
// }

Link* head_reverse(Link* p)
{
    Link * new_head = NULL;
    Link * temp = NULL;
    while (p)
    {
        //将 temp 从 head 中摘除
        temp = p;
        p=p->next;
        //将 temp 插入到 new_head 的头部
        temp->next = new_head;
        new_head = temp;
    }
    return new_head;
}

Link* local_reverse(Link* p)
{
    Link * beg = NULL;
    Link * end = NULL;
    if (p == NULL || p->next == NULL) {
        return p;
    }
    beg = p;
    end = p->next;
    while (end)
    {
        //将 end 从链表中摘除
        beg->next = end->next;
        //将 end 移动至链表头
        end->next = p;
        p = end;
        //调整 end 的指向，另其指向 beg 后的一个节点，为反转下一个节点做准备
        end = beg->next;
    }
    return p;
}
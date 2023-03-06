// #include "linkreverse.h"
// #include "LinkIntersect.h"
#include "doulink.h"
int main()
{
    // Link* p = InitLink();
    // Link* a = (Link*)malloc(sizeof(Link));
    // a->elem = 2;
    // a->next = p;

    // Link* b = (Link*)malloc(sizeof(Link));
    // b->elem = 3;
    // b->next = p;
    // bool ret = LinkIntersectV2(a, b);
    // Display(p);
    // p = local_reverse(p);
    // Display(p);
    doulink* head = NULL;
    head=initLine(head);
    display(head);
    printf("%d",head->next->next->prior->data);
    return 0;
}
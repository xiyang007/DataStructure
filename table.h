#include "stdlib.h"
#include "stdio.h"
#define Size 5
typedef struct table
{
    int* head;
    int len;
    int size;
}table;

table InitTable()
{
    table t;
    t.head = (int*)malloc(Size*sizeof(int));
    if (!t.head)
    {
        exit(0);
    }
    t.len = 0;
    t.size = Size;
    return t;
}

table InsertE(table t, int elem, int addIndex)
{
    if (addIndex > t.len || addIndex < 1)
    {
        printf("insert pos error\n");
        return t;
    }
    if (t.len == t.size)
    {
        t.head = (int*)realloc(t.head, (t.size+1)*sizeof(int));
        if (!t.head)
        {
            printf("new error\n");
            return t;
        }
        t.size+=1;
    }
    for (size_t i = t.len-1; i < addIndex-1; i--)
    {
        t.head[i+1] = t.head[i];
    }
    t.head[addIndex-1] = elem;
    t.len++;
    return t;
}

table DeleteTable(table t, int deIndex)
{
    if (deIndex > t.len || deIndex < 1)
    {
        printf("error delete pos\n");
        return t;
    }
    for (size_t i = deIndex; i < t.len; i++)
    {
        t.head[i-1] = t.head[i];
    }
    
    t.len--;
    return t;
}

int SelectTable(table t, int elem)
{
    for (int i=0; i<t.len; i++) {
        if (t.head[i]==elem) {
            return i+1;
        }
    }
    return -1;//如果查找失败，返回-1
}

table ModifyTable(table t, int elem, int newElem)
{
    for (int i=0; i<t.len; i++) {
        if (t.head[i]==elem) {
            t.head[i] = newElem;
        }
    }
    return t;//如果查找失败，返回-1
}

void display(table t)
{
    for (size_t i = 0; i < t.len; i++)
    {
        printf("%d", t.head[i]);
    }
    printf("\n");
}
// int main()
// {
//     table t = InitTable();
//     for (int i=1; i<=Size; i++) {
//         t.head[i-1]=i;
//         t.len++;
//     }
//     printf("顺序表中存储的元素分别是：\n");
//     display(t);
//     t = DeleteTable(t, 2);
//     display(t);
//     t=InsertE(t,3,4);
//     display(t);
//     return 0;
// }
#include <stdio.h>

struct List;
typedef struct List* list;

struct List
{
    int data;
    list next;
};

//even and odd must be !+ NULL
void split(list *l, list *even, list *odd)
{
    if(l == NULL)
        return;
    list it = *l, *evenIt = even, *oddIt = odd;
    while(it != NULL)
    {
        if((it)->data % 2 == 0)
        {
            *evenIt = it;
            it = (it)->next;
            (*evenIt)->next = NULL;
            evenIt = &(*evenIt)->next;
        }
        else // if(-//- == 1)
        {
            *oddIt = it;
            it = (it)->next;
            (*oddIt)->next = NULL;
            oddIt = &(*oddIt)->next;
        }
    }

}

void Print(list l)
{
    while(l != NULL)
    {
        printf("%d ", l->data);
        l = l->next;
    }
    printf("\n");
}

#include <time.h>
#include <stdlib.h>


list Random(int num)
{
    list head = NULL;
    list *l = &head;
    while(num > 0)
    {
        *l = malloc(sizeof(struct List));
        (*l)->data = rand() % 20;
        (*l)->next = NULL;
        l = &((*l)->next);
        --num;
    }
    return head;
}

int main(void)
{
    srand(time(NULL));
    list a = Random(10), b, c;

    Print(a);
    split(&a, &b, &c);
    Print(b);
    Print(c);
    return 0;
}

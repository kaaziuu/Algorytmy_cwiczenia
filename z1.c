#include <stdio.h>
#include <stdlib.h>

struct elem
{
    int x;
    struct elem *next;
};

typedef struct elem el;

el *create(int x)
{
    el *elem = (el *)malloc(sizeof(el));
    elem->x = x;
    elem->next = NULL;
    return elem;
}

void deleteEl(el *elem)
{
    el *help = elem;
    while (help != NULL)
    {
        help = elem->next;
        free(elem);
        elem = help;
    }
}

void pritnEl(el *elem)
{
    el *printer = elem;
    while (printer != NULL)
    {
        printf("%d\n", printer->x);
        printer = printer->next;
    }
    printf("___________\n");
}

el *getLast(el *elem)
{
    el *tmp = elem;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    return tmp;
}

el *addTop(el *elem, int y)
{
    el *newElem = (el *)malloc(sizeof(el));
    newElem->x = y;
    newElem->next = elem;
    return newElem;
}

void addBottom(el *elem, int y)
{
    el *bottom = (el *)malloc(sizeof(el));
    bottom->x = y;
    bottom->next = NULL;

    el *last = getLast(elem);
    last->next = bottom;
}

el *find(el *head, int x)
{
    el *help = head;
    int i = 0;
    while (help->x != x && help->next != NULL)
    {
        help = help->next;
        i++;
    }
    if (help->x == x)
    {
        printf("%d found on %d position\n", x, i);
        return help;
    }
    else
    {
        printf("%d not found\n", x);
        return head;
    }
}

void addAfter(el *target, int y)
{
    el *newEl = (el *)malloc(sizeof(el));
    newEl->x = y;
    newEl->next = target->next;
    target->next = newEl;
}

void addBefore(el *head, el *target, int y)
{
    el *help = head;
    while (help->next != target && help->next != NULL)
    {
        help = help->next;
    }
    el *newEl = (el *)malloc(sizeof(el));
    newEl->x = y;
    newEl->next = target;
    help->next = newEl;
}

el *pop(el *head)
{
    el *newHead = head->next;
    free(head);
    return newHead;
}

void drop(el *head)
{
    el *help = head;
    el *before = NULL;
    while (help->next != NULL)
    {
        before = help;
        help = help->next;
    }
    free(help);
    if (before != NULL)
    {
        before->next = NULL;
    }
}

el* removeEl(el *head, el *toRemove)
{
    el *help = head;
    el *before = NULL;
    while (help != toRemove && help->next != NULL)
    {
        before = help;
        help = help->next;
    }
    if(before != NULL){
        before->next = help->next;
    }
    el *returnVaule = head;
    if(head == toRemove){
        returnVaule = head->next;
    }
    free(help);
    return returnVaule;
}

int main(int argc, char const *argv[])
{
    el *head = create(5);
    // el *head;
    pritnEl(head);
    head = addTop(head, 6);
    pritnEl(head);
    addBottom(head, 9);
    head = addTop(head, 29);
    pritnEl(head);

    el *fd = find(head, 9);
    fd = find(head, 234);
    printf("___________\n");
    pritnEl(head);

    addAfter(head->next, 10);
    addBefore(head, head->next, 199);
    pritnEl(head);

    head = pop(head);
    drop(head);
    pritnEl(head);
    
    head = removeEl(head, head->next);
    pritnEl(head);

    head = removeEl(head, head);

    pritnEl(head);

    deleteEl(head);
    return 0;
}
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
    el *head = (el *)malloc(sizeof(el));
    head->x = x;
    head->next = NULL;
    return head;
}

void deleteEl(el *head)
{

    el *help = head;
    while (help != NULL)
    {
        help = head->next;
        free(head);
        head = help;
    }
}

void pritnEl(el *head)
{
    // printf("%d %p \n", head->x, head);

    if (head != NULL)
    {

        el *printer = head;
        while (printer != NULL)
        {
            printf("%d\n", printer->x);
            printer = printer->next;
        }
        printf("___________\n");
    }
}

el *getLast(el *head)
{
    if (head != NULL)
    {
        el *tmp = head;
        while (tmp->next != NULL)
        {
            tmp = tmp->next;
        }

        return tmp;
    }
    return NULL;
}

el *addTop(el *head, int y)
{
    el *newhead = (el *)malloc(sizeof(el));
    newhead->x = y;
    if (head != NULL)
    {
        newhead->next = head;
    }
    else
    {
        newhead->next = NULL;
    }
    return newhead;
}

el *addBottom(el *head, int y)
{
    if (head != NULL)
    {
        el *bottom = (el *)malloc(sizeof(el));
        bottom->x = y;
        bottom->next = NULL;

        el *last = getLast(head);
        last->next = bottom;
    }
    else
    {
        head = create(y);
    }
    return head;
}

el *find(el *head, int x)
{
    if (head != NULL)
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
    else
    {
        printf("list is empty\n");
        return NULL;
    }
}

void addAfter(el *target, int y)
{
    if (target != NULL)
    {
        el *newEl = (el *)malloc(sizeof(el));
        newEl->x = y;
        newEl->next = target->next;
        target->next = newEl;
    }
}

void addBefore(el *head, el *target, int y)
{
    if (head != NULL)
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
}

el *pop(el *head)
{
    if (head != NULL)
    {
        el *newHead = NULL;
        if (head->next != NULL)
        {
            newHead = head->next;
        }
        free(head);
        return newHead;
    }
    else
    {
        return NULL;
    }
}

el *drop(el *head)
{
    if (head != NULL)
    {
        el *help = head;
        el *before = NULL;
        while (help->next != NULL)
        {
            before = help;
            help = help->next;
        }
        el* returnData = head;
        if(help == head){
            returnData = NULL;
        }
        free(help);
        if (before != NULL)
        {
            before->next = NULL;
        }
        return returnData;
    }
    return NULL;

}

el *removeEl(el *head, el *toRemove)
{
    if (head != NULL)
    {
        el *help = head;
        el *before = NULL;
        while (help != toRemove && help->next != NULL)
        {
            before = help;
            help = help->next;
        }
        if (before != NULL)
        {
            before->next = help->next;
        }
        el *returnVaule = head;
        if (head == toRemove)
        {
            if (head->next != NULL)
            {
                returnVaule = head->next;
            }
            else
            {
                returnVaule = NULL;
            }
        }
        free(help);
        return returnVaule;
    }
    else
    {
        return NULL;
    }
}

int main(int argc, char const *argv[])
{
    // el *head = create(5);
    el *head = NULL;
    // pritnEl(head);
    // head = addTop(head, 6);
    // pritnEl(head);

    head = addBottom(head, 9);
    // head = addTop(head, 29);
    // addBottom(head, 9);

    // pritnEl(head);

    // el *fd = find(head, 9);
    // fd = find(head, 234);
    // printf("___________\n");
    pritnEl(head);

    // addAfter(head, 10);
    // addBefore(head, head, 199);
    printf("_______________\n");

    // head = pop(head);
    pritnEl(head);
    head = drop(head);
    // pritnEl(head);

    // head = removeEl(head, head->next);
    // pritnEl(head);

    // head = removeEl(head, head);

    // pritnEl(head);

    deleteEl(head);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int x;
    struct elem *next;
    struct elem *before;
} el;

void printEl(el **head)
{
    if (*head != NULL)
    {
        el *current = *head;
        el *guard = current->before;
        printf("__________________________\n");
        while (current != guard)
        {
            current = current->next;
        }
        printf("__________________________\n");

    }
    else
    {
        printf("lista jest pusta \n");
    }
}

void create(el **head, int val)
{
    el *newHead = (el *)malloc(sizeof(el));
    newHead->x = val;
    el *guard = (el *)malloc(sizeof(el));
    newHead->next = guard;
    newHead->before = guard;
    guard->next = newHead;
    guard->before = newHead;
    *head = newHead;
}
void deleteEl (el *head)
{
    if(head != NULL)
    {
        el *current = head;
        el *guard = head->before;
        while(current != guard)
        {
            printf("%d\n", current->x);
            head = current->next;
            free(current);
            current = head;
        }
        free(current);
    }
}

void addTop(el **head, int val)
{
    if (*head != NULL)
    {
        el *current = *head;
        el *guard  = current->before;
        el *newEl = (el *)malloc(sizeof(el));
        newEl->x = val;

        guard->next= newEl;
        newEl->before = guard;
        
        newEl->next= current;
        current->before = newEl;

        *head = newEl;
    }
    else
    {
        create(head, val);
    }
}

void insertBefore(el **head, int val, int index)
{
    if(*head != NULL)
    {
        el *current = *head;
        el *guard = current->before;
        int i = 0;
        while (current != guard)
        {
            if(index == i)
            {
                el *newEl = (el *)malloc(sizeof(el));
                newEl->x = val;
                newEl->before = current->before;
                
                current->before->next = newEl;

                newEl->next = current;
                current->before = newEl;
                if(index == 0)
                {
                    *head= newEl;
                }
                break;

            }
            current = current->next;
            i++;
        }
        
    }
}


void insertAfter(el **head, int val, int index)
{
    if(*head != NULL)
    {
        el *current = *head;
        el *guard = current->before;
        int i = 0;
        while (current != guard)
        {
            if(index == i)
            {
                // printf("%d", current->x);
                el *newEl = (el *)malloc(sizeof(el));
                el *next = current->next;
                newEl->x = val;
                
                current->next = newEl;
                newEl->before = current;
                next->before = newEl;
                newEl->next = next;

                break;

            }
            current = current->next;
            i++;
        }
        
    }
}

void addBottom(el **head, int val)
{
    if (*head != NULL)
    {
        el *current = *head;
        el *guard = current->before;
        current = guard->before;
        el *newEl = (el *)malloc(sizeof(el));
        newEl->x = val;

        newEl->before = current;
        current->next = newEl;

        
        newEl->next = guard;
        guard->before = newEl;

    }
    else
    {
        create(head, val);
    }
}

void printMenu()
{
    printf("0-zakoncz\n");
    printf("1-dodaj na poczatek\n");
    printf("2-dodaj na koniec\n");
    printf("3-dodaj przed\n");
    printf("4-dodaj za\n");
    printf("5-wypisz\n");
}

int main(int argc, char const *argv[])
{
    el *head = NULL;
    int dec = -1;
    int val = 0;
    int index = 0;
    while(dec != 0)
    {
        printMenu();
        scanf("%d", &dec);
        switch(dec)
        {
            case 0:
                deleteEl(head);
                break;
            case 1:
                printf("podaj wartosc \n");
                scanf("%d", &val);
                addTop(&head, val);
                break;
            case 2:
                printf("podaj wartosc \n");
                scanf("%d", &val);
                addBottom(&head, val);
                break;
            case 3:
                printf("podaj wartosc \n");
                scanf("%d", &val);
                printf("podaj index \n");
                scanf("%d", &index);
                insertBefore(&head, val, index);
                break;
            case 4:
                printf("podaj wartosc \n");
                scanf("%d", &val);
                printf("podaj index \n");
                scanf("%d", &index);
                insertAfter(&head, val, index);
                break;
            case 5:
                printEl(&head);
                break;
            default:
                printf("brak takiej opcji \n");
                break;
                
        }
    }


    // addBottom(&head, 5);
    // addBottom(&head, 6);
    // addBottom(&head, 7);
    // addBottom(&head, 8);
    // printEl(&head);
    // printf("_____________\n");
    // addTop(&head, 4);
    // addTop(&head, 3);
    // addTop(&head, 2);
    // addTop(&head, 1);
    // printEl(&head);
    // printf("_____________\n");

    // insertBefore(&head, 0, 0);
    // insertBefore(&head, 44, 4);
    // printEl(&head);
    // printf("_____________\n");

    // insertAfter(&head, -3, 0);
    // insertAfter(&head, 444, 5);
    // printEl(&head);
    return 0;
}

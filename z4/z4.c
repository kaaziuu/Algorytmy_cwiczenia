#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int x;
    struct elem *next;
} el;

// typedef struct elem el;

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
        printf("___________\n");

        el *printer = head;
        while (printer != NULL)
        {
            printf("%d\n", printer->x);
            printer = printer->next;
        }
        printf("___________\n");
    }
    else
    {
        printf("lista jest pusta");
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

void printReversed(el *head)
{
    if(head != NULL){
        el *current = head;
        el *target = getLast(head);
        printf("_________________\n");

        while (target != head)
        {
            if(current->next == target)
            {
                printf("%d\n", current->next->x);
                target = current;
                current = head;
            }
            else{
                current = current->next;
            }
        }
        printf("%d\n", head->x);
        printf("_________________\n");
        
    }else{
        printf("lista jest pusta\n");
    }
}

void printMenu()
{
    printf("1 wypisz \n");
    printf("2 wypisz od tylu \n");
    printf("3 dodaj element \n");
    printf("0 zakoncz \n");
}

int main(int argc, char const *argv[])
{
    int dec = -1;
    el *head = NULL;
    int help = 0;
    int helpVaule = 0;
    while (dec != 0)
    {
        printMenu();
        scanf("%d", &dec);
        switch (dec)
        {
        case 1:
            pritnEl(head);
            break;
        case 2:
            printReversed(head);
            break;
        case 3:
            printf("podaj liczbe jaka chcesz dodac \n");
            scanf("%d", &help);
            head = addTop(head, help);
            break;
        case 0:
            deleteEl(head);
            break;
        default:
            printf("nie ma takiej komendy");
            break;
        }
    }

    return 0;
}

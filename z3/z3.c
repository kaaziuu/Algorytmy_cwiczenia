#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int x;
    struct elem *next;
} el;

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

el *create(int x)
{
    el *head = (el *)malloc(sizeof(el));
    head->x = x;
    head->next = NULL;
    return head;
}

void addTop(el **head, int y)
{
    if (*head != NULL)
    {
        el *help = *head;
        el *copy = (el *)malloc(sizeof(el));
        copy->x = help->x;
        copy->next = help->next;
        help->next = copy;
        help->x = y;
        *head = help;
    }
    else
    {
        *head = create(y);
    }
}

void addBottom(el **head, int y)
{
    if (*head != NULL)
    {
        el *help = *head;
        while (help->next != NULL)
        {
            help = help->next;
        }
        el *newElem = (el *)malloc(sizeof(el));
        newElem->x = y;
        newElem->next = NULL;
        help->next = newElem;
    }
    else
    {
        *head = create(y);
    }
}

el *usun_wsz(el *P, int y)
{
    if (P != NULL)
    {
        el *current = P;
        el *before = NULL;
        while (current != NULL)
        {
            if (current->x == y)
            {
                if (before == NULL)
                {
                    P = P->next;
                    free(current);
                    current = P;
                }
                else
                {
                    before->next = current->next;
                    free(current);
                    current = before->next;
                }
            }
            else
            {
                before = current;
                current = current->next;
            }
        }
    }

    return P;
}

void usun_wsz2(el **P, int y)
{
    if (P != NULL)
    {
        el *current = *P;
        el *before = NULL;
        while (current != NULL)
        {
            if (current->x == y)
            {
                if(before == NULL){
                    *P = current->next;
                    free(current);
                    current = *P;
                }else{
                    before->next = current->next;
                    free(current);
                    current = before->next;
                }

            }else{
                before = current;
                current = current->next;
            }
        }
    }
}

void printMenu()
{
    printf("1 wypisz \n");
    printf("2 dodaj na gore \n");
    printf("3 dodaj na dol \n");
    printf("4 usun wszytkie sposob 1 \n");
    printf("5 usun wszytkie sposob 2 \n");
}

int main(int argc, char const *argv[])
{
    int dec = -1;
    el *head = NULL;
    int help = 0;

    while (dec != 0)
    {
        printMenu();
        scanf("%d", &dec);
        switch (dec)
        {
        case 0:
            deleteEl(head);
            break;
        case 1:
            pritnEl(head);
            break;
        case 2:
            printf("podaj liczbe jaka chcesz dodac \n");
            scanf("%d", &help);
            addTop(&head, help);
            break;
        case 3:
            printf("podaj liczbe jaka chcesz dodac \n");
            scanf("%d", &help);
            addBottom(&head, help);
            break;
        case 4:
            printf("podaj liczbe jaką chcesz usunac \n");
            scanf("%d", &help);
            head = usun_wsz(head, help);
            break;
        case 5:
            printf("podaj liczbe jaką chcesz usunac \n");
            scanf("%d", &help);
            usun_wsz2(&head, help);
            break;
        default:
            break;
        }
    }

    return 0;
}
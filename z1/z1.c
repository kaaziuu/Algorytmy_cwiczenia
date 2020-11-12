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
        printf("___________\n");
        
        el *printer = head;
        while (printer != NULL)
        {
            printf("%d\n", printer->x);
            printer = printer->next;
        }
        printf("___________\n");
    }else{
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
            printf("%d znaleziono na %d pozycji\n", x, i);
            return help;
        }
        else
        {
            printf("%d nie znaleziono\n", x);
            return head;
        }
    }
    else
    {
        printf("lista jest pusta\n");
        return NULL;
    }
}

el * addAfter(el *head, int index, int y)
{
    if(head == NULL){
        return create(y);
    }

    int i = 0;
    el *help = head;
    while (help != NULL)
    {
        if (i == index)
        {
            el *newEl = (el *)malloc(sizeof(el));
            newEl->x = y;
            newEl->next = help->next;
            help->next = newEl;
            break;
        }
        help = help->next;
        i++;
    }
    return head;
}

el* addBefore(el *head, int index, int y)
{
    if (head != NULL)
    {
        el *help = head;
        el *before = NULL;
        int i = 0;
        while (help != NULL)
        {
            if (i == index)
            {
                el *newEl = (el *)malloc(sizeof(el));
                newEl->x = y;
                if(before != NULL){
                    newEl->next = help;
                    before->next = newEl;
                    return head;
                }
                else{
                    newEl->next = head;
                    return newEl;
                }
            }else{
                i++;
                before = help;
                help = help->next;

            }
        }
    }
    else{
        head= create(y);
    }
    return head;
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
        el *returnData = head;
        if (help == head)
        {
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

el * removeEl(el *head, int x)
{
    if (head != NULL)
    {
        el *help = head;
        el *before = NULL;
        if(x==0){
            help = help->next;
            free(head);
            return help;
        }
        int i = 0;
        while (help != NULL)
        {
            if (i == x)
            {
                before->next = help->next;
                free(help);
                break;
            }
            else
            {
                i++;
                before = help;
                help = help->next;
            }
        }
        return head;
    }
    else
    {
        return NULL;
    }
}

void printMenu()
{
    printf("1 wypisz \n");
    printf("2 dodaj na gore \n");
    printf("3 dodaj na dol \n");
    printf("4 znajdz elemetn \n");
    printf("5 dodaj za elementem \n");
    printf("6 dodaj przed elementem \n");
    printf("7 usun pierwszy element\n");
    printf("8 usun ostani element\n");
    printf("9 usun konkretny element  \n");
    printf("0 zamknij działanie programu \n");
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
            printf("podaj liczbe jaka chcesz dodac \n");
            scanf("%d", &help);
            head = addTop(head, help);
            break;
        case 3:
            printf("podaj liczbe jaka chcesz dodac \n");
            scanf("%d", &help);
            head = addBottom(head, help);
            break;
        case 4:
            printf("podaj wartos jakiej szukasz \n");
            scanf("%d", &help);
            head = find(head, help);
            break;
        case 5:
            printf("podaj jaka chcesz dodac wartosc\n");
            scanf("%d", &help);
            printf("podaj pozyzje elemenut za ktorych chcesz dodac (liczymy od 0) \n");
            scanf("%d", &helpVaule);
            head = addAfter(head, helpVaule, help);
            break;
        case 6:
            printf("podaj jaka chcesz dodac wartosc\n");
            scanf("%d", &help);
            printf("podaj pozyzje elemenut przd ktorych  chcesz dodac (liczymy od 0) \n");
            scanf("%d", &helpVaule);
            head = addBefore(head, helpVaule, help);
            break;
        case 7:
            head = pop(head);
            break;
        case 8:
            head=drop(head);
            break;
        case 9:
            printf("podaj index elementu ktory chcesz usunac : ");
            scanf("%d", &help);
            head = removeEl(head, help);
            break;
        case 0:
            deleteEl(head);
            break;

        default:
            printf("blednu wybor\n");
            break;
        }
    }

    // deleteEl(head);
    return 0;
}
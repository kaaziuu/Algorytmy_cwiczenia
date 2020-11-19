#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int x;
    struct elem *next;
} el;

// typedef struct elem el;

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

void find(el **head, int y)
{
    if (*head != NULL)
    {
        el *help = *head;
        int index = 0;
        while (help != NULL)
        {
            
            if (help->x == y)
            {
                printf("%d znaleziono na pozycji %d\n", y, index);
            }
            help = help->next;
            index++;
        }
    }
    else
    {
        printf("lista jest pusta\n");
    }
}

void addAfter(el **head, int index, int y)
{
    if (index == 0 && head == NULL)
    {
        addTop(head, y);
    }
    else if (head != NULL)
    {
        el *help = *head;
        int i = 0;
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
    }
}

void addBefore(el **head, int index, int y)
{
    if (head != NULL)
    {
        el *help = *head;
        el *before = NULL;
        int i = 0;
        while (help != NULL)
        {
            if (i == index)
            {
                el *newEl = (el *)malloc(sizeof(el));
                newEl->x = y;
                if (before != NULL)
                {
                    newEl->next = help;
                    before->next = newEl;
                }
                else
                {
                    newEl->next = *head;
                    *head = newEl;
                }
                break;
            }
            else
            {
                i++;
                before = help;
                help = help->next;
            }
        }
    }
    else
    {
        addTop(head, y);
    }
}

void pop(el **head)
{
    if (head != NULL)
    {
        el *tmp = *head;
        *head = tmp->next;
        free(tmp);
    }
}

void drop(el **head)
{
    if (head != NULL)
    {
        el *help = *head;
        el *before = NULL;
        while (help->next != NULL)
        {
            before = help;
            help = help->next;
        }
        if (help == *head)
        {
            *head = NULL;
        }
        else if (before != NULL)
        {
            before->next = NULL;
        }
        free(help);
    }
}

void removeEl(el **head, int x)
{
    if (head != NULL)
    {
        el *help = *head;
        el *before = NULL;
        int i = 0;
        if (x == 0)
        {
            *head = help->next;
            free(help);
        }
        else
        {
            while (help != NULL)
            {
                if (i == x)
                {
                    before->next = help->next;
                    free(help);
                    break;
                }
                else{
                    i++;
                    before=help;
                    help = help->next;
                }
            }
        }
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
            printf("podaj wartos jakiej szukasz \n");
            scanf("%d", &help);
            find(&head, help);
            break;
        case 5:
            printf("podaj jaka chcesz dodac wartosc\n");
            scanf("%d", &help);
            printf("podaj pozyzje elemenut za ktorych chcesz dodac (liczymy od 0) \n");
            scanf("%d", &helpVaule);
            addAfter(&head, helpVaule, help);
            break;
        case 6:
            printf("podaj jaka chcesz dodac wartosc\n");
            scanf("%d", &help);
            printf("podaj pozyzje elemenut przd ktorych  chcesz dodac (liczymy od 0) \n");
            scanf("%d", &helpVaule);
            addBefore(&head, helpVaule, help);
            break;

        case 7:
            pop(&head);
            break;
        case 8:
            drop(&head);
            break;
        case 9:
            printf("podaj index elementu ktory chcesz usunac : ");
            scanf("%d", &help);
            removeEl(&head, help);
            break;
        default:
            break;
        }
    }

    return 0;
}
/**
Podstawą różnica między sposobem z z1 a z2 ze w z1 zawsze trzeba zwracać głowę
nową bądź starą natomiast w sposobie w z2 operujemy na wskaźniku na wskaznik, przez co jest
trochę szybsze, lecz w taki sposób łatwiej utracić "głowę" czyli pierwszy element
oraz według mojej opinii sposób 2 jest bardziej przyjazny, jeśli chodzi o użytkowanie kogoś z zewnątrz.
 * */
#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int x;
    struct elem *next;
} el;

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
        printf("lista jest pusta\n");
    }
}

void insert(el **head, int value, int repeat)
{
    if (*head != NULL)
    {
        el *current = *head;
        if (value < current->x || (value == current->x && repeat == 1))
        {
            el *newEl = (el *)malloc(sizeof(el));
            newEl->x = value;
            newEl->next = current;
            *head = newEl;
        }
        else if (value > current->x)
        {
            while (current != NULL)
            {
                if ((current->x < value || (current->x <= value && repeat)) && (current->next == NULL || current->next->x > value))
                {
                    el *newEl = (el *)malloc(sizeof(el));
                    newEl->x = value;
                    newEl->next = current->next;
                    current->next = newEl;
                    break;
                }
                current = current->next;
            }
        }
    }
    else
    {
        el *newEl = (el *)malloc(sizeof(el));
        newEl->x = value;
        *head = newEl;
    }
}

void marge(el **P, el **Q)
{

    if (*P != NULL && *Q != NULL)
    {
        // na current wynieram ta co zaczyna sie od mniejszej
        el *currentP = *P;
        el *currentQ = *Q;
        el *next = NULL;
        el *first = NULL;
        el *start = NULL;
        if (currentQ->x < currentP->x)
        {
            el *tmp = currentP;
            currentP = currentQ;
            currentQ = tmp;
        }
        
        start = currentP;
        while (currentP->next != NULL)
        {
            // literujemy dopoki następna p nie wieksze będzie od obecnego q
            if(currentP->next->x <= currentQ->x){
                currentP = currentP->next;
                continue;
            }
            first = currentQ;
            next = currentP->next;
            
            
            // literujemy do poki elementy q  sa mniejsze od nastepnego elementu p
            while (currentQ->next != NULL && currentQ->next->x <= next->x)
            {
                currentQ = currentQ->next;
            }
            currentP->next = first;
            currentP = currentQ;
            // currentQ = currentQ->next;

            
            if (currentQ->next != NULL)
            {
                currentQ = currentQ->next;
                currentP->next = next;
                currentP = currentP->next;
            }
            else
            {
                currentQ = currentQ->next;
                currentP->next = next;
                break;
            }
        }
        if (currentQ != NULL)
        {
            currentP->next = currentQ;
        }

        *Q = NULL;
        *P = start;
    }
}

void printMenu()
{
    printf("0-wylacz \n");
    // printf("1-wypisz \n");
    printf("1-wypisz \n");
    printf("2-dodaj element do P\n");
    printf("3-dodaj element do Q\n");
    printf("4-polacz P i Q \n");
}

int main(int argc, char const *argv[])
{
    int dec = -1;
    el *P = NULL;
    el *Q = NULL;
    int help;
    while (dec != 0)
    {
        printMenu();
        scanf("%d", &dec);
        switch (dec)
        {
        case 0:
            deleteEl(P);
            deleteEl(Q);
            break;
        case 1:
            printf("P\n");
            pritnEl(P);
            printf("Q\n");
            pritnEl(Q);
            break;

        case 2:
            printf("podaj wartosc jaka chcesz dodac \n");
            scanf("%d", &help);
            insert(&P, help, 1);
            break;

        case 3:
            printf("podaj wartosc jaka chcesz dodac \n");
            scanf("%d", &help);
            insert(&Q, help, 1);
            break;

        case 4:
            marge(&P, &Q);
            break;

        default:
            printf("brak takiej opcji");
            break;
        }
    }

    return 0;
}

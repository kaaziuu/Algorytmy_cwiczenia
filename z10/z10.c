#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int x;
    struct elem *next;
} el;

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

el *create(int x)
{
    el *head = (el *)malloc(sizeof(el));
    head->x = x;
    head->next = NULL;
    return head;
}

// 4 rekurencyjnie
void printEl(el *head)
{
    if (head != NULL)
    {
        printf("%d\n", head->x);
        printEl(head->next);
    }
}

el *printElReverse(el *head)
{
    if (head == NULL)
    {
        return head;
    }
    printElReverse(head->next);
    printf("%d\n", head->x);
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
// 3 rekurencyjnie
el *removeAll(el *P, el *before, int y)
{
    if (P == NULL)
    {
        return P;
    }
    if (P->next == NULL)
    {
        if (P->x == y)
        {
            before->next = NULL;
            free(P);
            return NULL;
        }
        else
        {
            return P;
        }
    }
    el *next = removeAll(P->next, P, y);
    
    if (P->x == y && before != NULL)
    {
        if(next != NULL)
            before->next = next;
        else{
            before->next = NULL;
        }
        free(P);
        return next;
    }
    else if (P->x == y && before == NULL)
    {
        free(P);
        return next;
    }
    return P;
}

// 5 rekurencyjnie
el *revetrRecuretion(el **head, el *elem)
{
    if (elem == NULL)
    {
        return NULL;
    }
    if (elem->next == NULL)
    {
        *head = elem;
        return elem;
    }

    el *tmpEl = revetrRecuretion(head, elem->next);
    tmpEl->next = elem;
    elem->next = NULL;
    return elem;
}

// 6 rekurencyjnie

el *insert(el *head, el *before, int val, int repeat)
{
    if (head == NULL)
    {
        el *newEl = (el *)malloc(sizeof(el));
        newEl->x = val;
        return newEl;
    }
    if (head->next == NULL)
    {
        if (before == NULL)
        {
            if (head->x > val)
            {
                el *newEl = (el *)malloc(sizeof(el));
                newEl->x = val;
                newEl->next = head;
                return newEl;
            }
            else if (head->x < val || (head->x <= val && repeat))
            {
                el *newEl = (el *)malloc(sizeof(el));
                newEl->x = val;
                head->next = newEl;
                return head;
            }
            return head;
        }
        else
        {
            if (head->x > val)
            {
                el *newEl = (el *)malloc(sizeof(el));
                newEl->x = val;
                newEl->next = head;
                before->next = newEl;
                return newEl;
            }
            else if (head->x < val || (head->x <= val && repeat))
            {
                el *newEl = (el *)malloc(sizeof(el));
                newEl->x = val;
                head->next = newEl;
            }
            return head;
        }
    }
    if (head->x > val || (head->x >= val && repeat))
    {
        el *newEl = (el *)malloc(sizeof(el));
        newEl->x = val;
        if (before)
        {
            before->next = newEl;
            newEl->next = head;
        }
        else
        {
            newEl->next = head;
            return newEl;
        }
        return head;
    }
    el *next = insert(head->next, head, val, repeat);
    return head;
}
// 8 rekurencyjnie
el *removeDuplicateSorted(el *head)
{
    if (head == NULL)
    {
        return head;
    }
    if (head->next == NULL)
    {
        return head;
    }
    el *next = removeDuplicateSorted(head->next);
    if (next->x == head->x)
    {
        head->next = next->next;
    }
    return head;
}

int isIn(el *head, int value)
{
    if (head != NULL)
    {
        el *current = head;
        while (current != NULL)
        {
            if (current->x == value)
            {
                return 1;
            }
        }
    }
    return 0;
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
void addBottom2(el **head, int y)
{
    if (*head != NULL)
    {
        el *bottom = (el *)malloc(sizeof(el));
        bottom->x = y;
        bottom->next = NULL;
        el *current = *head;
        el *last = getLast(current);
        last->next = bottom;
    }
    else
    {
        *head = create(y);
    }
}


el *removeDuplicateUnsorted(el *head, el *elem)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (elem == NULL)
    {
        return elem;
    }

    el *next = removeDuplicateUnsorted(head, elem->next);
    elem->next = next;
    el *current = head;
    while (current != elem)
    {
        if (current->x == elem->x)
        {
            return elem->next;
        }
        current = current->next;
    }

    return elem;
}

/**
 * 10.9 można rekurencja wyszukiwac konca bloku jakiego chcemy zrobić marge!!!!!!!!!!!
 */

el *getEndBlock(el *current, int val)
{
    if (current->next == NULL || current->next->x > val)
    {

        return current;
    }
    else
    {

        return getEndBlock(current->next, val);
    }
}

void merge(el **P, el **Q)
{
    if (*P != NULL && *Q != NULL)
    {
        // na current wybiera ta co zaczyna sie od mniejszej
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
            if (currentP->next->x <= currentQ->x)
            {
                currentP = currentP->next;
                continue;
            }
            first = currentQ;
            next = currentP->next;
            currentQ = getEndBlock(currentQ, next->x);
            currentP->next = first;
            currentP = currentQ;
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
    printf("1-dodaj element \n");
    printf("2-wypisz \n");
    printf("3-wypisz od tylu \n");
    printf("4-usun o warotosci \n");
    printf("5-odwroc \n");
    printf("6-usun duplikaty \n");
    printf("0-zakoncz \n");
}

void printMenu2()
{
    printf("1-dodaj element \n");
    printf("2-wypisz \n");
    printf("3-wypisz od tylu \n");
    printf("4-usun o warotosci \n");
    printf("5-usun duplikaty \n");
    printf("6-mage HEAD z Q \n");
    printf("0-zakoncz \n");
}

void unsorted()
{
    int dec = -1;
    int help;
    el *head = NULL;
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
            printf("podaj wartosc \n");
            scanf("%d", &help);
            head = addBottom(head, help);
            break;
        case 2:
            printf("___________________________\n");
            printEl(head);
            printf("___________________________\n");
            break;
        case 3:
            head = printElReverse(head);
            break;
        case 4:
            printf("podaj wartosc \n");
            scanf("%d", &help);
            head = removeAll(head, NULL, help);
            break;
        case 5:
            revetrRecuretion(&head, head);
            break;
        case 6:
            head = removeDuplicateUnsorted(head, head);
            break;
        default:
            printf("brak takiej opcji \n");
            break;
        }
    }

}


void sorted()
{
    el *head = NULL;
    el *Q=NULL;
    int PQ = 1;
    int dec = -1;
    int help;
    int duplicateType;
    printf("0-bez duplikatow \n 1-z duplikatami\n");
    scanf("%d", &duplicateType);
    while (dec != 0)
    {
        printMenu2();
        scanf("%d", &dec);

        switch (dec)
        {
        case 0:
            deleteEl(head);
            break;
        case 1:
            printf("podaj wartosc \n");
            scanf("%d", &help);
         
            printf("0-HEAD\n 1-Q\n");
            scanf("%d", &PQ);
            if(!PQ)
                head = insert(head, NULL, help, duplicateType);
            else
                Q=insert(Q, NULL, help, duplicateType);
            break;
        case 2:
            printf("HEAD\n");
            printEl(head);
            printf("Q\n");
            printEl(Q);
            break;
        case 3:
            head = printElReverse(head);
            break;
        case 4:
            printf("podaj wartosc \n");
            scanf("%d", &help);
            head = removeAll(head, NULL, help);
            break;
        case 5:
            head = removeDuplicateSorted(head);
            break;
        case 6:
            merge(&head, &Q);
            break;
        default:
            printf("brak takiej opcji \n");
            break;
        }
    }
}
int main(int argc, char const *argv[])
{
    int sortedType;

    printf("1-posortowana \n 0-nieposortowana ");
    scanf("%d", &sortedType);
    if(sortedType)
    {
        sorted();
    }
    else{
        unsorted();
    }

    return 0;
}
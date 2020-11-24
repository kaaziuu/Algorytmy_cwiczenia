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
        before->next = next;
        free(P);
        return next;
    }
    else if (P->x == y && before == NULL)
    {
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
/**
 * 10.9 można rekurencja wyszukiwac konca bloku jakiego chcemy zrobić marge!!!!!!!!!!!
 */

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
    if(current->next==NULL || current->next->x > val)
    {

        return current;
    }
    else{

        return getEndBlock(current->next, val);
    }
}

void merge(el **P,el **Q)
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
            if(currentP->next->x <= currentQ->x)
            {
                currentP = currentP->next;
                continue;
            }
            first = currentQ;
            next = currentP->next;
            currentQ = getEndBlock(currentQ, next->x);
            

            currentP->next = first;
            currentP = currentQ;
            currentQ = currentQ->next;
            if(currentQ->next != NULL)
            {
                currentQ = currentQ->next;
                currentP->next = next;
                currentP = currentP->next;
            }else{
                currentQ = currentQ->next;
                currentP->next = next;
                break;
            }

        }
        if(currentQ != NULL)
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

int main(int argc, char const *argv[])
{
    // int sortedType;
    // int duplicateType;
    // int dec = -1;
    // int help;
    // el *head = NULL;
    // el *used = NULL;
    // printf("1-posortowana \n 0-nieposortowana ");
    // scanf("%d", &sortedType);
    // if (sortedType)
    // {
    //     printf("0-bez duplikatow \n 1-z duplikatami");
    //     scanf("%d", &duplicateType);
    // }
    // while (dec != 0)
    // {
    //     printMenu();
    //     scanf("%d", &dec);

    //     switch (dec)
    //     {
    //         case 0:
    //             deleteEl(head);
    //             deleteEl(used);
    //             break;
    //         case 1:
    //             printf("podaj wartosc \n");
    //             scanf("%d", &help);
    //             if(sortedType)
    //             {
    //                 head = insert(head, help, duplicateType);
    //             }else{
    //                 head = addBottom(head, help);
    //             }
    //             break;
    //         case 2:
    //             printEl(head);
    //             break;
    //         case 3:
    //             head = printElReverse(head);
    //             break;
    //         case 4:
    //             printf("podaj wartosc \n");
    //             scanf("%d", &help);
    //             removeAll(head, help);
    //             break;
    //         case 5:
    //             reverse(&head, head);
    //             break;
    //         case 6:
    //             if(sortedType){
    //                 head = removeDuplicateSorted(head);
    //             }else{
    //                 head = removeDuplicateUnsorted(head, used);
    //                 deleteEl(used);
    //             }
    //             break;
    //         default:
    //             printf("brak takiej opcji \n");
    //             break;
    //     }
    // // }
    // el *head = NULL;
    // el *tmp = NULL;
    // head = addBottom(head, 1);
    // head = addBottom(head, 2);
    // head = addBottom(head, 3);
    // head = addBottom(head, 3);
    // head = addBottom(head, 4);
    // head = addBottom(head, 5);
    // head = addBottom(head, 6);
    // head = addBottom(head, 7);
    // head = addBottom(head, 8);
    // head = addBottom(head, 3);
    // head = addBottom(head, 3);
    // head = addBottom(head, 3);
    // printf("___________\n");

    // printEl(head);
    // printf("___________\n");
    // head = removeAll(head, NULL, 3);
    // printf("___________\n");
    // printEl(head);
    // tmp = revetrRecuretion(&head, head);
    // printf("___________\n");
    // printEl(head);

    // head = insert(head, NULL, 1, 1);
    // head = insert(head, NULL, 3, 1);
    // head = insert(head, NULL, 2, 1);
    // head = insert(head, NULL, 5, 1);
    // head = insert(head, NULL, 5, 1);
    // head = insert(head, NULL, 4, 1);
    // head = insert(head, NULL, -1, 1);
    // head = insert(head, NULL, -1, 1);
    // head = insert(head, NULL, -1, 1);
    // head = insert(head, NULL, -1, 1);
    // head = insert(head, NULL, -1, 1);
    // head = removeDuplicateSorted(head);
    // printEl(head);
    // printf("_____________________\n");
    // head = removeDuplicateUnsorted(head, head);
    // // printEl(tmp);
    // printEl(head);
    // deleteEl(head);
    // deleteEl(tmp);

    el *P = NULL;
    el *Q = NULL;
    P=insert(P, NULL, 1, 1);
    P=insert(P, NULL, 3, 1);
    P=insert(P, NULL, 3, 1);
    P=insert(P, NULL, 5, 1);
    P=insert(P, NULL, 7, 1);
    P=insert(P, NULL, 9, 1);
    P=insert(P, NULL, 9, 1);
    Q=insert(Q, NULL, 2, 1);
    Q=insert(Q, NULL, 4, 1);
    Q=insert(Q, NULL, 6, 1);
    Q=insert(Q, NULL, 8, 1);
    Q=insert(Q, NULL, 8, 1);
    Q=insert(Q, NULL, 10, 1);
    Q=insert(Q, NULL, 10, 1);

    printEl(P);
    printf("___________\n");
    printEl(Q);
    printf("___________\n");
    merge(&P, &Q);
    printEl(P);
    printf("___________\n");
    printEl(Q);
    printf("___________\n");
    
    return 0;
}
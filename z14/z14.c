#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int x;
    struct elem *next;
} el;

typedef struct elemCounter
{
    int val;
    int count;
    struct elemCounter *next;
} ct;

void create(el **head, int val)
{
    el *newEl = (el *)malloc(sizeof(el));
    el *guard = (el *)malloc(sizeof(el));
    newEl->x = val;
    guard->next = newEl;
    newEl->next = guard;
    *head = newEl;
}

el *takeGuard(el *head)
{
    if (head != NULL)
    {
        el *current = head;
        while (current->next != head)
        {
            current = current->next;
        }
        return current;
    }
    return NULL;
}

void printEl(el *head)
{
    printf("____________\n");
    if (head != NULL)
    {
        el *guard = takeGuard(head);

        el *current = head;
        while (current != guard)
        {
            printf("%d\n", current->x);
            current = current->next;
        }
    }
    else
    {
        printf("lista jest pusta \n");
    }
    printf("____________\n");
}

void addBeforeTop(el **head, int val)
{
    if (*head != NULL)
    {
        el *current = *head;
        el *guard = takeGuard(*head);
        el *newEl = (el *)malloc(sizeof(el));
        newEl->x = val;
        guard->next = newEl;
        newEl->next = current;
        *head = newEl;
    }
    else
    {
        create(head, val);
    }
}

void addAfterTop(el **head, int val)
{
    if (*head != NULL)
    {
        el *current = *head;
        el *newEl = (el *)malloc(sizeof(el));
        newEl->x = val;
        newEl->next = current->next;
        current->next = newEl;
    }
    else
    {
        create(head, val);
    }
}

int find(el *head, int val)
{
    if (head != NULL)
    {
        int index = 0;
        el *current = head;
        el *guard = takeGuard(head);
        while (current != guard)
        {
            if (current->x == val)
            {
                return index;
            }
            current = current->next;
            index++;
        }
    }
    return -1;
}

void removeEl(el **head, int index)
{
    if (*head != NULL)
    {
        int i = 0;
        el *current = *head;
        el *headT = *head;
        el *guard = takeGuard(*head);
        if (index == 0)
        {
            if (current->next == guard)
            {
                free(current);
                free(guard);
                *head = NULL;
            }
            else
            {
                guard->next = current->next;
                *head = current->next;
                free(current);
            }
        }
        else
        {
            while (current->next != guard)
            {
                if ((i + 1) == index)
                {
                    el *next = current->next;

                    current->next = next->next;
                    free(next);
                    break;
                }
                current = current->next;
                i++;
            }
        }
    }
}

void clearEl(el *head)
{
    if (head != NULL)
    {
        el *current = head;
        el *help = NULL;
        el *guard = takeGuard(head);
        while (current != guard)
        {
            help = current->next;
            free(current);
            current = help;
        }
        free(current);
    }
}

int cotain(el *head, int val)
{
    if (head != NULL)
    {
        el *guard = takeGuard(head);

        el *current = head;
        while (current != guard)
        {
            if (current->x == val)
            {
                return 1;
            }
            current = current->next;
        }
    }
    return 0;
}


void removeDuplicate(el *head)
{
    if (head != NULL)
    {
        el *guard = takeGuard(head);
        el *tmp = NULL;
        el *current = head;
        el *before = NULL;
        while (current != guard)
        {
            if (cotain(tmp, current->x))
            {
                before->next = current->next;
                free(current);
                current = before->next;
            }
            else
            {
                addAfterTop(&tmp, current->x);
                before = current;
                current = current->next;
            }
        }
    }
}
void update(ct **head, int val)
{
    if (*head != NULL)
    {
        ct *current = *head;
        while (current->next != NULL)
        {
            if (current->val == val)
            {
                current->count++;
                break;
            }
            current = current->next;
        }
        if (current->next == NULL && current->val != val)
        {
            ct *newEl = (ct *)malloc(sizeof(ct));
            newEl->next = NULL;
            newEl->val = val;
            newEl->count = 1;
            current->next = newEl;
        }
        else
        {
            current->count++;
        }
    }
    else
    {
        ct *newEl = (ct *)malloc(sizeof(ct));
        newEl->next = NULL;
        newEl->val = val;
        newEl->count = 1;
        *head = newEl;
    }
}

void clrearCt(ct *head)
{
    if(head != NULL)
    {
        ct *help = NULL;
        while(head != NULL)
        {
            help = head->next;
            free(head);
            head = help;
        }
    }
}

int mostCommon(el *head)
{
    if (head != NULL)
    {
        ct *count = NULL;
        el *current = head;
        el *guard = takeGuard(head);
        while(current != guard)
        {
            update(&count, current->x);
            current = current->next;
        }
        int toRetuntVal = count->val;
        int mostCommont = count->count;
        ct *currentCt = count;
        while(currentCt != NULL)
        {
            if(currentCt->count > mostCommont)
            {
                toRetuntVal = currentCt->val;
                mostCommont = currentCt->count;
            }
            currentCt = currentCt->next;
        }
        clrearCt(count);
        return toRetuntVal;
        
    }
    return 0;
}


void printMenu()
{
    printf("0-zakonc\n");
    printf("1-dodaj przed top\n");
    printf("2-dodaj za top\n");
    printf("3-znajdz\n");
    printf("4-usun \n");
    printf("5-wypisz \n");
    printf("6-usun duplikaty \n");
    printf("7-znajdz najczesciej wystepujaca \n");
}

int main(int argc, char const *argv[])
{
    int dec = -1;
    int help;
    int result;
    el *head = NULL;
    while (dec != 0)
    {
        printMenu();
        scanf("%d", &dec);
        switch (dec)
        {
        case 0:
            clearEl(head);
            break;
        case 1:
            printf("podaj wartosc \n");
            scanf("%d", &help);
            addBeforeTop(&head, help);
            break;
        case 2:
            printf("podaj wartosc \n");
            scanf("%d", &help);
            addAfterTop(&head, help);
            break;
        case 3:
            printf("podaj wartosc \n");
            scanf("%d", &help);
            result = find(head, help);
            printf("%d\n", result);
            if (result != -1)
            {
                printf("znaleziono na %d\n", result);
            }
            else
            {
                printf("nie znaleziono \n");
            }
            break;
        case 4:
            printf("podaj wartosc \n");
            scanf("%d", &help);
            removeEl(&head, help);
            break;
        case 5:
            printEl(head);
            break;
        case 6:
            removeDuplicate(head);
            break;
        case 7:
            result = mostCommon(head);
            printf("najczescie wystepuje %d \n", result);
            break;
        default:
            printf("brak takiej opcji\n");
            break;
        }
    }
    return 0;
}

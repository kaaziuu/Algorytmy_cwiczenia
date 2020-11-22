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

void removeDupicateSorted(el *head)
{
    if (head != NULL)
    {
        el *current = head;
        el *firstValue = head;
        while (current != NULL)
        {
            if (current->x != firstValue->x)
            {
                firstValue->next = current;
                firstValue = current;
            }
            current = current->next;
        }
        if(firstValue->next != NULL){
            firstValue->next = NULL;
        }
    }
    // return head;
}

int cotain(el *head, int val)
{
    if (head != NULL)
    {
        el *current = head;
        while (current != NULL)
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

void removeDupicateUnsorted(el *head)
{
    if (head != NULL)
    {
        el *tmp = NULL;
        el *current = head;
        el *before = NULL;
        while (current != NULL)
        {
            if (cotain(tmp, current->x))
            {
                before->next = current->next;
                current = current->next;
            }
            else
            {
                tmp = addBottom(tmp, current->x);
                before = current;
                current = current->next;
            }
        }
    }
}

void printMenu()
{
    printf("0-wylacz \n");
    // printf("1-wypisz \n");
    printf("1-wypisz \n");
    printf("2-dodaj element \n");
    printf("3-usun powtorzenia \n");
}

int main(int argc, char const *argv[])
{
    el *head = NULL;
    int type;
    int dec = -1;
    int help;
    printf("wybierz tryp \n");
    printf("0-talica posortowana \n");
    printf("1-tablica nieposortowana \n");
    scanf("%d", &type);
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
            printf("podaj wartosc jaka chcesz dodac \n");
            scanf("%d", &help);
            if (type == 0)
            {
                insert(&head, help, 1);
            }
            else
            {
                head = addBottom(head, help);
            }
            break;
        case 3:
            if (type == 0)
            {
                removeDupicateSorted(head);
            }
            else
            {
                removeDupicateUnsorted(head);
            }
            break;
        default:
            printf("brak takiej opcji \n");
            break;
        }
    }

    return 0;
}

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

void printMenu()
{
    printf("0-wylacz \n");
    // printf("1-wypisz \n");
    printf("1-dodaj element \n");
}

int main(int argc, char const *argv[])
{
    el *head = NULL;
    int dec = -1;
    int repeat;
    int help = 0;

    printf("wybierz opcje pracy programu\n");
    printf("0-bez powtorzen\n");
    printf("1-z powtorzeniami\n");
    scanf("%d", &repeat);
    while (dec != 0)
    {
        printMenu();
        scanf("%d", &dec);
        switch (dec)
        {
        case 0:
            deleteEl(head);
            break;
        // case 1:
        //     pritnEl(head);
        //     break;
        case 1:
            printf("podaj wartosc jaka chcesz dodac \n");
            scanf("%d", &help);
            insert(&head, help, repeat);
            pritnEl(head);
            break;

        default:
            printf("brak takiej opcji");
            break;
        }
    }

    return 0;
}

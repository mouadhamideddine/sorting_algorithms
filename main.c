#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

listint_t *create_listint(const int *array, size_t size)
{
    listint_t *list;
    listint_t *node;
    int *tmp;

    list = NULL;
    while (size--)
    {
        node = malloc(sizeof(*node));
        if (!node)
            return (NULL);
        tmp = (int *)&node->n;
        *tmp = array[size];
        node->next = list;
        node->prev = NULL;
        list = node;
        if (list->next)
            list->next->prev = list;
    }
    return (list);
}
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
listint_t *get_tail(listint_t *head)
{
    if (head == NULL)
        return NULL;

    while (head->next != NULL)
    {
        head = head->next;
    }

    return head;
}
listint_t *backward_list(listint_t **list)
{
    listint_t *current, *prev_node, *next_node, *temp;
    int prev_num;
    int current_num;
    current = *list;
    temp = current;
    while(current->prev != NULL)
    {
    current_num = current->n;
    prev_num = current->prev->n;
    if (prev_num > current_num)
    {
        prev_node = current->prev;
        next_node = current->next;
        current->next = prev_node;
        current->prev = prev_node->prev;
        prev_node->next = next_node;
        if (prev_node->prev != NULL)
        {
            prev_node->prev->next = current;
            prev_node->prev = current;
        }
        if (prev_node->prev == NULL)
        {
            prev_node->prev = current;
            return (temp);
        }
    }
    else
    {
        return (temp);
    }
    }
}
/**
/* insertion sort list algorithm*/
/**
 * insertion_sort_list - sorts a doubly linked list of integers in 
 * ascending order using the Insertion sort algorithm
 * list: list
 * Return: Nothing
*/
listint_t *insertion_sort_list(listint_t **list)
{
    listint_t *current;
    listint_t *current_test;
    int token = 0;

    if ( *list == NULL  || (*list)->next == NULL)
    {
        exit(EXIT_FAILURE);
    }
    current = *list;
    current = current->next;
    while(current != NULL)
    {
        print_list(*list);
        current = backward_list(&current);
        current = current->next;
    }
    return current;
}
/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
    int array[] = {5, 12, 28, 9, 3, 17, 22, 6, 14, 3, 5, 12, 28, 9, 3, 17, 22, 6, 14, 3};
    size_t n = sizeof(array) / sizeof(array[0]);
    listint_t *list = create_listint(array, n);
    listint_t *tail = get_tail(list);
    listint_t *at_index;

    list = insertion_sort_list(&list);
    //printf("at _index = %d\n", at_index->n);
    print_list(list);

    return (0);
}
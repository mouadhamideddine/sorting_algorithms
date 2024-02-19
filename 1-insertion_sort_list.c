#include "sort.h"
/**
 * forward_list - moves forward in a list
 * @list : list
 * Return: None
*/
listint_t *forward_list(const listint_t *list)
{
    while (list)
    {
        list = list->next;
    }
}
/**
 * backward_list - moves backwards in a list part of insert sort algrorithm
 * checks if prev_num > current_num if so it swaps places for ascending order list
 * @list : list
 * Return: pointer to node working with
*/
listint_t *backward_list(listint_t **list)
{
    listint_t *current, *prev_node, *next_node;
    int prev_num;
    int current_num;
    current = *list;

    while(current != NULL && current->prev != NULL)
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
            return (current);
        }
    }
    else
    {
        return (current);
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
void insertion_sort_list(listint_t **list)
{
    listint_t *current;
    listint_t *current_test;

    if ( *list == NULL  || (*list)->next == NULL)
    {
        exit();
    }
    current = *list;
    while(current != NULL)
    {
        current = current->next;
        current_test = backward_list(&current);
        if (current_test->prev == NULL)
        {
            current = current_test;
        }
    }
}
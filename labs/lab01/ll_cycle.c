#include <stddef.h>
#include <stdbool.h>
#include "ll_cycle.h"

int ll_has_cycle(node* head) {
    /* your code here */
    if (head == NULL)   return false;
    node* slow = head;
    node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        fast = fast->next->next;
        slow = slow->next;
        if (fast == NULL){
            return false;
        }
        if (fast == slow){
            return true;
        }
    }
}
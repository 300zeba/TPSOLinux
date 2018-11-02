#include "sched.h"
#include <stdio.h>
#include <stdlib.h>

struct node* newNode(struct task_struct *task){
  struct node* temp = (struct node*)malloc(sizeof(struct node));
  temp->task = task;
  temp->next = NULL;
  return temp;
}

void pop(struct node** head){
  struct node* temp = *head;
  (*head) = (*head)->next;
  free(temp);
}

void push(struct node** head, struct task_struct *task){
    struct node* start = (*head);

    struct node* temp = newNode(task);

    if ((*head)->task->burst_time > task->burst_time) {
        // Insert New Node before head
        temp->next = *head;
        (*head) = temp;
    }
    else {
        // Traverse the list and find a
        // position to insert new node
        while (start->next != NULL &&
               start->next->task->burst_time < task->burst_time) {
            start = start->next;
        }

        // Either at the ends of the list
        // or at required position
        temp->next = start->next;
        start->next = temp;
    }
}


int main(){

  return 0;
}

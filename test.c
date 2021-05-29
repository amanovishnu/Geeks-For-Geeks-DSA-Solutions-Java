#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node *next;
};
int main(void) {
    struct node *head = NULL, *newNode, *temp;
    int choice = 1;
    while(choice) {
        newNode = (struct node*) malloc(sizeof(struct node));
        printf("User Enter Data \n");
        scanf("%d" ,&(newNode->data));
        newNode->next = NULL;
        if(head == NULL)
        {
            head = temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
        printf("Do you Want to Continue (0/1)? ");
        scanf("%d",&choice);
    }
    temp = head;
    while(temp != NULL) {
        printf("%d",temp->data);
        temp = temp->next;
    }
    getch();
    return 0;
}
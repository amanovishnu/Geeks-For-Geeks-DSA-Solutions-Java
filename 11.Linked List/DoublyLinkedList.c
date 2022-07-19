#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prevNode;
    int data;
    struct node *nextNode;
};

struct node *head = NULL, *temp, *oldNode = NULL, *newNode, *currentNode;

void createDLL()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data in newNode: ");
    newNode->prevNode = NULL;
    newNode->nextNode = NULL;
    scanf("%d", &(newNode->data));
    printf("prevNode:%p\t data:%d\t nextNode:%p\n", newNode->prevNode, newNode->data, newNode->nextNode);
    if (head == NULL)
    {
        head = temp = newNode;
    }
    else
    {
        temp->nextNode = newNode;
        temp->prevNode = oldNode;
        oldNode = temp;
        temp = temp->nextNode;
        temp->prevNode = oldNode;
    }
}

void showDLL()
{
    temp = head;
    while (temp != NULL)
    {
        printf("prevNode:%p\t data:%d\t nextNode:%p\t ->Address: %p\n", temp->prevNode, temp->data, temp->nextNode, temp);
        temp = temp->nextNode;
    }
}

void lengthOfDLL()
{
    int count = 0;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->nextNode;
        count++;
    }
    printf("Length of Doubly Linked List: %d\n", count);
}

void insertNodeatBegin()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data into the newNode: ");
    scanf("%d", &(newNode->data));
    newNode->prevNode = NULL;
    newNode->nextNode = head;
    head->prevNode = newNode;
    head = newNode;
}

void insertNodeAtEnding()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data into the newNode: ");
    scanf("%d", &(newNode->data));
    newNode->nextNode = NULL;
    temp = head;
    while (temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }
    temp->nextNode = newNode;
    newNode->prevNode = temp;
    temp = newNode;
}

void insertNodeAtPos()
{
    int position = 0, i = 1, length = 0;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->nextNode;
        length++;
    }
    printf("Length of DLL: %d\n", length);
    printf("Enter the Position to Enter newNode: ");
    scanf("%d", &position);
    printf("Selected Position: %d\n", position);
    temp = head;
    if (position == 1)
    {
        printf("-----Node Will be Inserted at the begining-----\n");
        insertNodeatBegin();
    }
    else if (position == length)
    {
        printf("-----Node Will be Inserted at the Ending-----\n");
        insertNodeAtEnding();
    }
    else
    {
        while (i < position - 1)
        {
            temp = temp->nextNode;
            printf("I Value: %d\n", i);
            i++;
        }
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data into the newNode: ");
        scanf("%d", &(newNode->data));
        newNode->nextNode = temp->nextNode;
        newNode->prevNode = temp;
        temp->nextNode = newNode;
        temp = newNode;
        (temp->nextNode)->prevNode = temp;
    }
}

void deleteNodeFromBegin()
{
    printf("----- List is Deleted from Begining -----\n");
    temp = head;
    head = head->nextNode;
    head->prevNode = NULL;
    temp->nextNode = NULL;
    free(temp);
}

void deleteNodeFromEnding()
{
    printf("----- List is Deleted from Ending -----\n");
    struct node *copyNode = NULL;
    temp = head;
    while (temp->nextNode != NULL)
    {
        temp = temp->nextNode;
    }
    (temp->prevNode)->nextNode = NULL;
    free(temp);
}

void deleteNodeFromPos()
{
    int position = 0, i = 1, length = 0;
    temp = head;
    while (temp != NULL)
    {
        temp = temp->nextNode;
        length++;
    }
    printf("Length of DLL: %d\n", length);
    printf("Enter the Position to Enter newNode: ");
    scanf("%d", &position);
    printf("Selected Position: %d\n", position);
    if (position == 1)
    {
        printf("----- Node Will be Deleted from the Begining -----\n");
        deleteNodeFromBegin();
    }
    else if (position == length)
    {
        printf("----- Node Will be Deleted from the Ending -----\n");
        deleteNodeFromEnding();
    }
    else
    {
        temp = head;
        while (i < position - 1)
        {
            temp = temp->nextNode;
            i++;
        }
        struct node *intNode = NULL;
        intNode = temp->nextNode;
        temp->nextNode = intNode->nextNode;
        (intNode->nextNode)->prevNode = temp;
    }
}

void reverseDLL() {
    printf("\n ----- Reversing a Doubly Linked List ----- \n\n");
    temp = currentNode = head;
    while(temp->nextNode != NULL) {
        temp = temp->nextNode;
        currentNode->nextNode = currentNode->prevNode;
        currentNode->prevNode = temp;
        currentNode = temp;
    }
    temp->nextNode = temp->prevNode;
    temp->prevNode = NULL;
    head = temp;

}

int main(void)
{
    int choice = 1;
    while (choice)
    {
        createDLL();
        printf("Do you Want to Add a newNode (0/1): ");
        scanf("%d", &choice);
    }
    showDLL();
    lengthOfDLL();
    // insertNodeAtEnding();
    // showDLL();
    // lengthOfDLL();
    // insertNodeAtPos();
    // showDLL();
    // lengthOfDLL();
    // deleteNodeFromBegin();
    // showDLL();
    // lengthOfDLL();
    // deleteNodeFromEnding();
    // showDLL();
    // lengthOfDLL();
    // deleteNodeFromPos();
    // showDLL();
    // lengthOfDLL();
    reverseDLL();
    showDLL();
    lengthOfDLL();
    return 0;
}
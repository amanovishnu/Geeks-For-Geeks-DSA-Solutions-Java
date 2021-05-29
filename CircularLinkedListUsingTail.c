#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *tail = NULL, *newNode, *temp, *intNode ,*prevNode, *currentNode, *nextNode;

void createCLL()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data into the newNode: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (tail == NULL)
    {
        tail = temp = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->next = temp;
        tail = newNode;
    }
}

void showCLL()
{
    temp = tail->next;
    while (temp != tail)
    {
        printf("Data: %d\t nextAddress: %p\t presentAddress: %p\n", temp->data, temp->next, temp);
        temp = temp->next;
    }
    printf("Data: %d\t nextAddress: %p\t presentAddress: %p\n", temp->data, temp->next, temp);
}

void lengthCLL()
{
    int length = 0;
    temp = tail->next;
    while (temp != tail)
    {
        temp = temp->next;
        length++;
    }
    length++;
    printf("Length of Circular Linked List: %d\n", length);
}

void insertNodeAtBegin()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data into the newNode: ");
    scanf("%d", &newNode->data);
    newNode->next = tail->next;
    tail->next = newNode;
}

void insertNodeAtEnding()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data into the newNode: ");
    scanf("%d", &newNode->data);
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}

void insertNodeAtPos()
{
    int position = 0, i = 1, length = 0;
    temp = tail->next;
    while (temp != tail)
    {
        temp = temp->next;
        length++;
    }
    length++;
    printf("Length of CLL: %d\n", length);
    printf("Enter the position of newNode: ");
    scanf("%d", &position);
    printf("Selected Position: %d\n", position);
    if (position == 1)
    {
        printf("Node Will be inserted at the begining\n");
        insertNodeAtBegin();
    }
    else if (position == length)
    {
        printf("Node will be inserted at the Ending\n");
        insertNodeAtEnding();
    }
    else
    {
        temp = tail->next;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        printf("Data at node: %d\n", temp->data);
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data into newNode: ");
        scanf("%d", &newNode->data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNodeFromBegin()
{
    temp = tail->next;
    tail->next = temp->next;
    free(temp);
}

void deleteNodeFromEnding()
{
    temp = tail->next;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    temp->next = tail->next;
    free(tail);
    tail = temp;
}

void deleteNodeFromPos()
{
    int position = 0, i = 1, length = 0;
    temp = tail->next;
    while (temp != tail)
    {
        temp = temp->next;
        length++;
    }
    length++;
    printf("Length of CLL: %d\n", length);
    printf("Enter the Position to Delete Node: ");
    scanf("%d", &position);
    printf("Selected Position: %d\n", position);
    if (position == 1)
    {
        printf("Node Will be Removed From the Beginging\n");
        deleteNodeFromBegin();
    }
    else if (position == length)
    {
        printf("Node Will be Removed From the Ending\n");
        deleteNodeFromEnding();
    }
    else
    {
        temp = tail->next;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        // printf("Data: %d",temp->data);
        intNode = temp->next;
        temp->next = intNode->next;
        free(intNode);
    }
}
void reverseCLL() {
    prevNode = temp;
    currentNode = nextNode = tail->next;
    while(nextNode != tail) {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    tail = currentNode->next;
    currentNode->next = prevNode;

}

int main(void)
{
    int choice = 1;
    while (choice)
    {
        createCLL();
        printf("Do you Want to Create an newNode (0/1): ");
        scanf("%d", &choice);
    }
    showCLL();
    lengthCLL();
    // insertNodeAtBegin();
    // showCLL();
    // lengthCLL();
    // insertNodeAtEnding();
    // showCLL();
    // lengthCLL();
    // insertNodeAtPos();
    // showCLL();
    // lengthCLL();
    // deleteNodeFromBegin();
    // showCLL();
    // lengthCLL();
    // deleteNodeFromEnding();
    // showCLL();
    // lengthCLL();
    // deleteNodeFromPos();
    // showCLL();
    // lengthCLL();
    reverseCLL();
    showCLL();
    lengthCLL();
    return 0;
}
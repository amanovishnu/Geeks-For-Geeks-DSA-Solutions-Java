#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *tail = NULL, *newNode, *temp, *currnetNode, *prevNode = NULL, *nextNode;

void createCLL()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data into the newNode: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
    {
        head = tail = temp = newNode;
    }
    else
    {
        temp->next = newNode;
        temp = temp->next;
    }
    temp->next = head;
    tail = temp;
}

void lengthCLL()
{
    temp = head;
    int length = 0;
    while (temp->next != head)
    {
        temp = temp->next;
        length++;
    }
    length++;
    printf("Length of Circular Linked List: %d\n", length);
}

void showCLL()
{
    temp = head;
    while (temp->next != head)
    {
        printf("Data: %d\t nextAddress: %p\t presentAddress:%p\n", temp->data, temp->next, temp);
        temp = temp->next;
    }
    printf("Data: %d\t nextAddress: %p\t presentAddress:%p\n", temp->data, temp->next, temp);
    printf("Head Address -> %p\t Tail Address: %p\t", head, tail);
}

void insertNodeAtBegin()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data into the newNode :");
    scanf("%d", &newNode->data);
    newNode->next = head;
    tail->next = newNode;
    head = newNode;
}

void insertNodeAtEnding()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data into the newNode: ");
    scanf("%d", &newNode->data);
    newNode->next = head;
    tail->next = newNode;
    tail = newNode;
}

void insertNodeAtPos()
{
    int position = 0, i = 1, length = 0;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        length++;
    }
    length++;
    printf("Length of CLL: %d\n", length);
    printf("Enter the Postion to insert the Node: ");
    scanf("%d", &position);
    printf("Selected Position: %d\n", position);
    if (position == 1)
    {
        printf("Node Will be Inserted at the Begining\n");
        insertNodeAtBegin();
    }
    else if (position == length)
    {
        printf("Node Will be Inserted at the Ending\n");
        insertNodeAtEnding();
    }
    else
    {
        temp = head;
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data into the newNode: ");
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNodeFromBegin()
{
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = head->next;
    temp = head;
    head = head->next;
    free(temp);
}

void deleteNodeFromEnding()
{
    temp = head;
    while ((temp->next)->next != head)
    {
        temp = temp->next;
    }
    temp->next = head;
    free(tail);
    tail = temp;
}

void deleteNodeFromPos()
{
    int position = 0, i = 1, length = 0;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        length++;
    }
    length++;
    printf("Length of CLL: %d\n", length);
    printf("Enter Position to Delete Node: ");
    scanf("%d", &position);
    printf("Selected Position: %d\n", position);
    if (position == 1)
    {
        printf("Node Will be Removed from the Begining \n");
        deleteNodeFromBegin();
    }
    else if (position == length)
    {
        printf("Node Will be Removed from the Ending \n");
        deleteNodeFromEnding();
    }
    else
    {
        temp = head;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        printf("I and Data: %d\t %d\n", i, temp->data);
        currnetNode = temp;
        temp = temp->next;
        currnetNode->next = temp->next;
        free(temp);
    }
}

void reverseCLL()
{
    prevNode = tail;
    currnetNode = nextNode = head;
    while (nextNode->next != head)
    {
        nextNode = nextNode->next;
        currnetNode->next = prevNode;
        prevNode = currnetNode;
        currnetNode = nextNode;
    }
    currnetNode->next = prevNode;
    prevNode = tail;
    tail = head;
    head = prevNode;
}

int main(void)
{
    int choice = 1;
    while (choice)
    {
        createCLL();
        printf("Do you Want to Create an Other Node (0/1) :");
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
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *newNode, *head = NULL, *temp, *currentNode, *nextNode, *prevNode;

void createCLL()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data into newNode: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    if (head == NULL)
    {
        head = temp = newNode;
    }
    else
    {
        temp->next = newNode;
        temp = newNode;
    }
    temp->next = head;
}

void showCLL()
{
    temp = head;
    if (temp == NULL)
    {
        printf("Circular Linked List is Empty");
    }
    else
    {
        while (temp->next != head)
        {
            printf("Data: %d\t Next Address: %p\t Present Address: %p\n", temp->data, temp->next, temp);
            temp = temp->next;
        }
        printf("Data: %d\t Next Address: %p\t Present Address: %p\n", temp->data, temp->next, temp);
    }
}

void lengthOfCLL()
{
    int count = 0;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        count++;
    }
    count++;
    printf("Length of Circular Linked List: %d\n", count);
}

void insertNodeAtBegin()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data into the newNode: ");
    scanf("%d", &(newNode->data));
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    head = newNode;
}

void insertNodeAtEnding()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data into the newNode: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
}

void insertNodeAtPos()
{
    int position, i = 1, length = 0;
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        length++;
    }
    length++;
    printf("Length of Existing CLL: %d\n", length);
    printf("Enter the Position to Insert the newNode: ");
    scanf("%d", &position);
    printf("Selected Position: %d\n", position);
    if (position == 1)
    {
        printf("newNode will be inserted at begining\n");
        insertNodeAtBegin();
    }
    else if (position == length)
    {
        printf("newNode will be inserted at the ending\n");
        insertNodeAtEnding();
    }
    else
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data into newNode: ");
        scanf("%d", &(newNode->data));
        newNode->next = NULL;
        temp = head;
        while (i < position - 1)
        {
            temp = temp->next;
            i++;
        }
        // printf("Data: %d\n",temp->data);
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
    printf("Data of Present Node: %d\n", temp->data);
    free(temp->next);
    temp->next = head;
}

void deleteNodeFromPos()
{
    int position, i = 1, length = 0;
    printf("Enter Postion From Where Node Should be Deleted: ");
    scanf("%d", &position);
    printf("Selected Postion: %d\n", position);
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
        length++;
    }
    length++;
    printf("Length of Circular Linked List: %d\n", length);
    if (position == 1)
    {
        printf("Node Will Be Deleted From the Begining\n");
    }
    else if (position == length)
    {
        printf("Node Will Be Deleted From the Ending\n");
    }
    else
    {
        currentNode = head;
        while (i < position - 1)
        {
            currentNode = currentNode->next;
            i++;
        }
        nextNode = currentNode->next;
        currentNode->next = nextNode->next;
        free(nextNode);
        // printf("I Value: %d\n", currentNode->data);
    }
}

void reverseCLL()
{
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    prevNode = temp;
    currentNode = nextNode = head;
    while (nextNode->next != head)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    nextNode->next = prevNode;
    head = nextNode;
}

int main(void)
{
    int choice = 1;
    while (choice)
    {
        createCLL();
        printf("Do You Want to Create and Other CLL (0/1) : ");
        scanf("%d", &choice);
    }
    showCLL();
    lengthOfCLL();
    // insertNodeAtBegin();
    // showCLL();
    // lengthOfCLL();
    // insertNodeAtEnding();
    // showCLL();
    // lengthOfCLL();
    // insertNodeAtPos();
    // showCLL();
    // lengthOfCLL();
    // deleteNodeFromBegin();
    // showCLL();
    // lengthOfCLL();
    // deleteNodeFromEnding();
    // showCLL();
    // lengthOfCLL();
    // deleteNodeFromPos();
    // showCLL();
    // lengthOfCLL();
    reverseCLL();
    showCLL();
    lengthOfCLL();
    return 0;
}

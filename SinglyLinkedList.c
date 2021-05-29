#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *newNode, *temp, *prevNode, *intNode, *currentNode, *nextNode;

void createSLL()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Address of newNode Generated: %p\n", newNode);
    printf("Enter Data into the Node: ");
    scanf("%d", &newNode->data);
    newNode->next = NULL;
    if (head == NULL)
    {
        head = temp = newNode;
        printf("Address of headPointer: %p\n", head);
    }
    else
    {
        temp->next = newNode;
        temp = newNode;
    }
};

void showSLL()
{
    temp = head;
    if (temp == NULL)
    {
        printf("No SLL are Present\n");
    }
    else
    {
        while (temp != NULL)
        {
            printf("Data : %d\t Address : %p\n", temp->data, temp->next);
            temp = temp->next;
        }
    }
}

void lengthOfSLL()
{
    int count = 0;
    temp = head;
    if (temp == NULL)
    {
        count = 0;
    }
    else
    {
        while (temp != NULL)
        {
            temp = temp->next;
            count++;
        }
    }
    printf("Length of SLL: %d\n", count);
}

void insertNodeAtSLLBegin()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data in New node: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void insertNodeAtSLLEnd()
{
    temp = head;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data in to New Node: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    if (temp == NULL)
    {
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertNodeAtPos()
{
    temp = head;
    int position = 0, i = 1, count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    printf("Length of Existing SLL: %d\n", count);
    temp = head;
    printf("Enter position: ");
    scanf("%d", &position);
    printf("Selected Position: %d\n", position);
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data of newNode: ");
    scanf("%d", &(newNode->data));
    newNode->next = NULL;
    if (position == 1)
    {
        printf("Use Insert Node at Begining  Function\n");
        insertNodeAtSLLBegin();
    }
    else if (position == count)
    {
        printf("Use Insert Node at Ending  Function\n");
        insertNodeAtSLLEnd();
    }
    else
    {
        while (i < position - 1)
        {
            // printf("Data: %d\t Address: %p\t Count:%d\n", temp->data, temp->next, i);
            temp = temp->next;
            i++;
        }
        // printf("Data: %d\t Address: %p\t Count:%d -> Current Pointer\n", temp->data, temp->next, i);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNodeFromBegin()
{
    temp = head;
    head = head->next;
    free(temp);
}

void deleteNodeFromEnding()
{

    temp = prevNode = head;
    while (temp->next != NULL)
    {
        prevNode = temp;
        temp = temp->next;
    }
    prevNode->next = NULL;
    free(temp);
}

void deleteNodeFromPos()
{
    temp = head;
    int position = 0, i = 1, count = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    };
    printf("Enter the Postion :");
    scanf("%d", &position);
    printf("Selected Position: %d\n", position);
    if (position == 1)
    {
        printf("Use Deleted Node from Begining\n");
    }
    else if (position == count)
    {
        printf("Use Delete Node from Ending\n");
    }
    else
    {
        temp = intNode = head;
        while (i < position - 1)
        {
            printf("Data: %d\tAddress:%p\n", temp->data, temp->next);
            temp = temp->next;
            i++;
        }
        printf("Data: %d\tAddress:%p -> pointer\n", temp->data, temp->next);
        intNode = temp->next;
        temp->next = intNode->next;
        free(intNode);
    }
}

void reverseSLL()
{
    prevNode = 0;
    currentNode = nextNode = head;
    while (nextNode != NULL)
    {
        nextNode = nextNode->next;
        currentNode->next = prevNode;
        prevNode = currentNode;
        currentNode = nextNode;
    }
    head = prevNode;
}

int main(void)
{
    int choice = 1;
    while (choice)
    {
        createSLL();
        printf("Do you Want to Create an Other Linked List (1/0): ");
        scanf("%d", &choice);
    }
    showSLL();
    lengthOfSLL();
    // insertNodeAtSLLBegin();
    // showSLL();
    // lengthOfSLL();
    // insertNodeAtSLLEnd();
    // showSLL();
    // lengthOfSLL();
    // insertNodeAtPos();
    // showSLL();
    // lengthOfSLL();
    // deleteNodeFromBegin();
    // showSLL();
    // lengthOfSLL();
    // deleteNodeFromEnding();
    reverseSLL();
    showSLL();
    lengthOfSLL();
    return 0;
}
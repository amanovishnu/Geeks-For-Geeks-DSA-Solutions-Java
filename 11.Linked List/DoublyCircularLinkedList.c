#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prevNode;
    int data;
    struct node *nextNode;
};

struct node *newNode, *temp, *head = NULL, *tail = NULL, *currentNode, *nextNode, *intNode;

void createDCLL()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data into the newNode: ");
    scanf("%d", &newNode->data);
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->nextNode = head;
        newNode->prevNode = tail;
    }
    else
    {
        tail->nextNode = newNode;
        newNode->prevNode = tail;
        newNode->nextNode = head;
        head->prevNode = newNode;
        tail = newNode;
    }
}

void showDCLL()
{
    if (head == NULL)
    {
        printf("Doubly Circular Linked List is Empty\n");
    }
    else
    {
        temp = head;
        while (temp != tail)
        {
            printf("prevNode: %p\t Data:%d\t nextNode: %p\t ->presentNode: %p\n", temp->prevNode, temp->data, temp->nextNode, temp);
            temp = temp->nextNode;
        }
        printf("prevNode: %p\t Data:%d\t nextNode: %p\t ->presentNode: %p\n", temp->prevNode, temp->data, temp->nextNode, temp);
    }
}

void lengthDCLL()
{
    if (head == NULL)
    {
        printf("Doubly Circular Linked List is Empty\n");
    }
    else
    {
        int length = 0;
        temp = head;
        while (temp != tail)
        {
            temp = temp->nextNode;
            length++;
        }
        length++;
        printf("Length of Doubly Circular Linked List: %d\n", length);
    }
}

void reverseDCLL()
{
    if (head == NULL)
    {
        printf("Doubly Circular Linked List is Empty\n");
    }
    else
    {
        currentNode = nextNode = head;
        while (nextNode != tail)
        {
            nextNode = nextNode->nextNode;
            currentNode->nextNode = currentNode->prevNode;
            currentNode->prevNode = nextNode;
            currentNode = nextNode;
        }
        currentNode->nextNode = currentNode->prevNode;
        currentNode->prevNode = head;
        currentNode = head;
        head = tail;
        tail = currentNode;
    }
}

void insertNodeAtBegin()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data into the newNode: ");
    scanf("%d", &newNode->data);
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->nextNode = newNode;
        newNode->prevNode = newNode;
    }
    else
    {
        tail->nextNode = newNode;
        head->prevNode = newNode;
        newNode->nextNode = head;
        newNode->prevNode = tail;
        head = newNode;
    }
}

void insertNodeAtEnding()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data into the newNode: ");
    scanf("%d", &newNode->data);
    if (head == NULL)
    {
        head = tail = newNode;
        newNode->nextNode = newNode;
        newNode->prevNode = newNode;
    }
    else
    {
        head->prevNode = newNode;
        tail->nextNode = newNode;
        newNode->prevNode = tail;
        newNode->nextNode = head;
        tail = newNode;
    }
}

void deleteNodeAtBegin()
{
    if (head == NULL)
    {
        printf("Doubly Circular Linked List is Empty\n");
    }
    else
    {
        temp = head;
        head = head->nextNode;
        head->prevNode = tail;
        tail->nextNode = head;
        free(temp);
    }
}

void deleteNodeAtEnding()
{
    if (head == NULL)
    {
        printf("Doubly Circular Linked List is Empty\n");
    }
    else
    {
        temp = tail;
        tail = tail->prevNode;
        tail->nextNode = head;
        head->prevNode = tail;
        free(temp);
    }
}

void insertNodeAtPos()
{
    int position = 0, i = 1, length = 0;
    temp = head;
    while (temp != tail)
    {
        temp = temp->nextNode;
        length++;
    }
    length++;
    printf("Length of DCLL: %d\n", length);
    printf("Enter the position to insert newNode: ");
    scanf("%d", &position);
    if (position == 1)
    {
        printf("newNode will be inserted at the Begining\n");
        insertNodeAtBegin();
    }
    else if (position == length)
    {
        printf("newNode will be inserted at the Ending\n");
        insertNodeAtEnding();
    }
    else if (position > length)
    {
        printf("newNode Can't be Inserted\n");
    }
    else
    {
        temp = head;
        while (i < position - 1)
        {
            temp = temp->nextNode;
            i++;
        }
        newNode = (struct node *)malloc(sizeof(struct node));
        printf("Enter Data into the newNode: ");
        scanf("%d", &newNode->data);
        newNode->nextNode = temp->nextNode;
        newNode->prevNode = temp;
        temp->nextNode = newNode;
        (newNode->nextNode)->prevNode = newNode;
    }
}

void deleteNodeFromPos()
{
    int position = 0, i = 1, length = 0;
    temp = head;
    while (temp != tail)
    {
        temp = temp->nextNode;
        length++;
    }
    length++;
    printf("Length of DCLL : %d\n", length);
    printf("Enter Position to Remove a Node :");
    scanf("%d", &position);
    if (position == 1)
    {
        printf("Node Will be Removed from the Beginging\n");
    }
    else if (position == length)
    {
        printf("Node will Removed from the Ending\n");
    }
    else if (position > length)
    {
        printf("Node Cant be Removed\n");
    }
    else
    {
        temp = head;
        while (i < position - 1)
        {
            temp = temp->nextNode;
            i++;
        }
        intNode = temp->nextNode;
        temp->nextNode = intNode->nextNode;
        (intNode->nextNode)->prevNode = temp;
        free(intNode);
    }
}

int main(void)
{
    int selectChoice, choice = 1, selectLoop = 1;
    while (selectLoop)
    {
        printf("\n******************************\n");
        printf("1:Create a Doubly Circular Linked List\n");
        printf("2:Show Doubly Circular Linked List\n");
        printf("3:Show Length of Doubly Circular Linked List\n");
        printf("4:Insert Node at Begining of DCLL\n");
        printf("5.Insert Node at Ending of DCLL\n");
        printf("6.Insert Node at Position of DCLL\n");
        printf("7:Delete Node at Begining of DCLL\n");
        printf("8.Delete Node at Ending of DCLL\n");
        printf("9.Delete Node at Position of DCLL\n");
        printf("10.Reverse a DCLL\n");
        printf("Select any Operation on DCLL: ");
        scanf("%d", &selectChoice);
        switch (selectChoice)
        {
        case 1:
            while (choice)
            {
                createDCLL();
                printf("Do you want to Create an Other Node: ");
                scanf("%d", &choice);
            }
            break;
        case 2:
            showDCLL();
            break;
        case 3:
            lengthDCLL();
            break;
        case 4:
            insertNodeAtBegin();
            break;
        case 5:
            insertNodeAtEnding();
            break;
        case 6:
            insertNodeAtPos();
            break;
        case 7:
            deleteNodeAtBegin();
            break;
        case 8:
            deleteNodeAtEnding();
            break;
        case 9:
            deleteNodeFromPos();
            break;
        case 10:
            reverseDCLL();
            break;
        default:
            printf("Wrong Input\n");
        }
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

struct Node *f = NULL;
struct Node {
    int data;
    struct Node *next;
};

void display();
void insertion();
void deletion();

int main() {
    int choice;
    do {
        printf("\t Menu\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Choose a valid option\n");
                break;
        }
    } while (choice != 4);
    return 0;
}

void display() {
    struct Node *temp = f;
    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d \t", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void insertion() {
    struct Node *ptr = (struct Node*)malloc(sizeof(struct Node));
    printf("Enter the value to insert: ");
    scanf("%d", &ptr->data);
    ptr->next = NULL;
    if (f == NULL) {
        f = ptr;
    } else {
        struct Node *temp = f;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = ptr;
    }
    printf("Element inserted \n");
}

void deletion() {
    if (f == NULL) {
        printf("Queue underflow\n");
    } else {
        struct Node *temp = f;
        f = f->next;
        free(temp);
        printf("Element deleted \n");
    }
}
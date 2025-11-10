#include <stdio.h>
#include <stdlib.h>

struct employee {
    int ID;
    char *name;
    float salary;
    struct employee *prev;
    struct employee *next;
};

void insertAtBeginning(int ID, char *name, float salary);
void insertAfterID(int ID, char *name, float salary);
void deleteByID(int ID);
void display();

struct employee *head = NULL;

int main()
{
    int ID, choice, subChoice;
    char name[50];
    float salary;

    while (1)
    {
        printf("\nMain Menu\n");
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("\nInsert Menu\n");
                printf("1. Insert at beginning\n2. Insert after ID\n3. Back to Main Menu\n");
                printf("Enter your choice: ");
                scanf("%d", &subChoice);
                switch (subChoice)
                {
                    case 1:
                        printf("Enter ID: ");
                        scanf("%d", &ID);
                        printf("Enter Name: ");
                        scanf("%s", name);
                        printf("Enter Salary: ");
                        scanf("%f", &salary);
                        insertAtBeginning(ID, name, salary);
                        break;
                    case 2:
                        printf("Enter ID after which to insert: ");
                        scanf("%d", &ID);
                        printf("Enter Name: ");
                        scanf("%s", name);
                        printf("Enter Salary: ");
                        scanf("%f", &salary);
                        insertAfterID(ID, name, salary);
                        break;
                    case 3:
                        break;
                    default:
                        printf("Invalid choice\n");
                        break;
                }
                break;
            case 2:
                printf("Enter ID to delete: ");
                scanf("%d", &ID);
                deleteByID(ID);
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}

void insertAtBeginning(int ID, char *name, float salary)
{
    struct employee *newEmployee = (struct employee*)malloc(sizeof(struct employee));
    newEmployee->ID = ID;
    newEmployee->name = name;
    newEmployee->salary = salary;
    newEmployee->prev = NULL;
    newEmployee->next = head;
    if (head != NULL)
    {
        head->prev = newEmployee;
    }
    head = newEmployee;
}

void insertAfterID(int ID, char *name, float salary)
{
    struct employee *temp = head;
    while (temp != NULL)
    {
        if (temp->ID == ID)
        {
            struct employee *newEmployee = (struct employee*)malloc(sizeof(struct employee));
            if (!newEmployee) return;
            int newID;
            printf("Enter ID for employee: ");
            scanf("%d", &newID);
            newEmployee->ID = newID;
            newEmployee->name = name;
            newEmployee->salary = salary;
            newEmployee->next = temp->next;
            newEmployee->prev = temp;
            if (temp->next != NULL)
            {
                temp->next->prev = newEmployee;
            }
            temp->next = newEmployee;
            return;
        }
        temp = temp->next;
    }
    printf("Employee with ID %d not found\n", ID);
}

void deleteByID(int ID)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    struct employee *temp = head;
    if (head->ID == ID)
    {
        head = head->next;
        if (head != NULL)
        {
            head->prev = NULL;
        }
        free(temp);
        printf("Deleted employee with ID: %d\n", ID);
        return;
    }

    while (temp != NULL && temp->ID != ID)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("ID %d not found\n", ID);
        return;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = temp->next;
    }
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
    printf("Deleted employee with ID: %d\n", ID);
}

void display()
{
    struct employee *temp = head;
    while (temp != NULL)
    {
        printf("ID: %d, Name: %s, Salary: %.2f\n", temp->ID, temp->name, temp->salary);
        temp = temp->next;
    }
}
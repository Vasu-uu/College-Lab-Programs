#include<stdio.h>
#include<stdlib.h>

struct Node {
    int coeff;
    int pow;
    struct Node *next;
};

struct Node* poly1 = NULL;
struct Node* poly2 = NULL;
struct Node* poly_sum = NULL;

void poly_add();
void display_poly(struct Node* poly);
void insert_end(struct Node** poly_ref, int coeff, int pow);

void main()
{
    int i, n, coeff, pow;
    printf("Enter the no of terms in Polynomial 1:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter coeff and power of %d st term", i+1);
        scanf("%d %d", &coeff, &pow);
        insert_end(&poly1, coeff, pow);
    }

    printf("Enter the no of terms in Polynomial 2:");
    scanf("%d", &n);
    for(i=0; i<n; i++)
    {
        printf("Enter coeff and power of %d st term", i+1);
        scanf("%d %d", &coeff, &pow);
        insert_end(&poly2, coeff, pow);
    }

    printf("Polynomial 1:");
    display_poly(poly1);
    printf("Polynomial 2:");
    display_poly(poly2);
    printf("Sum of two polynomials:");
    poly_add();
    display_poly(poly_sum);
}

void insert_end(struct Node** poly_ref, int coeff, int pow)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->coeff = coeff;
    new_node->pow = pow;
    new_node->next = NULL;
    if (*poly_ref == NULL)
    {
        *poly_ref = new_node;
        return;
    }
    struct Node* temp = *poly_ref;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
}

void display_poly(struct Node* poly)
{
    if(poly==NULL)
    {
        printf("Polynomial is empty");
        return;
    }
    while(poly!=NULL)
    {
        printf("%d x^%d", poly->coeff, poly->pow);
        if(poly->next!=NULL)
        {
            printf(" + ");
        }
        poly=poly->next; // This line is missing in the image but logically required
    }
    printf("\n");
}

void poly_add()
{
    struct Node* p1 = poly1;
    struct Node* p2 = poly2;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->pow == p2->pow)
        {
            insert_end(&poly_sum, p1->coeff + p2->coeff, p1->pow);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if (p1->pow > p2->pow)
        {
            insert_end(&poly_sum, p1->coeff, p1->pow);
            p1 = p1->next;
        }
        else
        {
            insert_end(&poly_sum, p2->coeff, p2->pow);
            p2 = p2->next;
        }
    }
    while (p1 != NULL)
    {
        insert_end(&poly_sum, p1->coeff, p1->pow);
        p1 = p1->next;
    }
    while (p2 != NULL)
    {
        insert_end(&poly_sum, p2->coeff, p2->pow);
        p2 = p2->next;
    }
}
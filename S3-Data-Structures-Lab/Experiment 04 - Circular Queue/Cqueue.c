#include <stdio.h>

void EnQueue();
void DeQueue();
void display();
int F = -1, R = -1, CQ[10], n;

int main()
{
   int ch;
   printf("Enter the size of the queue: ");
   scanf("%d", &n);
   do {
      printf("\n Menu\n");
      printf("Enter '1' for insertion\n");
      printf("Enter '2' for deletion\n");
      printf("Enter '3' to Display\n");
      printf("Enter '4' to Exit\n");
      scanf("%d", &ch);
      switch(ch)
      {
         case 1:
            EnQueue();
            break;
         case 2:
            DeQueue();
            break;
         case 3:
            display();
            break;
         case 4:
            return 0;
         default:
            printf("Invalid choice, please try again.\n");
      }
   } while(1);
}

void EnQueue() {
   int item;
   if ((R + 1) % n == F) {
      printf("Queue overflow\n");
   } else {
      printf("Read the element: ");
      scanf("%d", &item);
      if (F == -1 && R == -1) {
         F = 0;
      }
      R = (R + 1) % n;
      CQ[R] = item;
   }
}

void DeQueue() {
   if (F == -1 && R == -1) {
      printf("Queue underflow\n");
   } else {
      printf("Deleted element: %d\n", CQ[F]);
      if (F == R)
      {
         F = -1;
         R = -1;
      }
      else {
         F = (F + 1) % n;
      }
   }
}

void display()
{
   int i;
   if(F==-1 && R==-1)
   {
      printf("\n Queue is empty..");
   }
   else
   {
      i=F;
      while(1) {
         printf("%d \t", CQ[i]);
         if(i==R)
            break;
         i=(i+1)%n;
      }
      printf("\n");
   }
}
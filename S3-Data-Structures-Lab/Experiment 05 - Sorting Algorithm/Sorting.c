#include <stdio.h>
#include <stdlib.h>

void Bubble_Sort(int arr[], int n);
void Insertion_Sort(int arr[], int n);
void Selection_Sort(int arr[], int n);
void display(int arr[], int n);
void copy_arr(int source[], int destination[], int n);

int main()
{
   int n, ch, arr[10], temparr[10];
   printf("Enter the limit of the array: ");
   scanf("%d", &n);
   printf("Enter %d elements: ", n);
   for (int i = 0; i < n; i++)
   {
      scanf("%d", &arr[i]);
   }

   while (1)
   {
      printf("\n");
      printf("Enter '1' for Bubble Sort\nEnter '2' for Insertion Sort\n");
      printf("Enter '3' for Selection Sort\nEnter '4' for Exit\n");
      scanf("%d", &ch);
      switch (ch)
      {
         case 1:
            copy_arr(arr, temparr, n);
            Bubble_Sort(temparr, n);
            break;
         case 2:
            copy_arr(arr, temparr, n);
            Insertion_Sort(temparr, n);
            break;
         case 3:
            copy_arr(arr, temparr, n);
            Selection_Sort(temparr, n);
            break;
         case 4:
            return 0;
         default: printf("Enter choices between 1 to 4\n");
      }
   }
}

void Insertion_Sort(int arr[], int n)
{
   int i, j, key;
   for (i = 1; i < n; i++)
   {
      key = arr[i];
      j = i - 1;
      while (j >= 0 && arr[j] > key)
      {
         arr[j + 1] = arr[j];
         j = j - 1;
      }
      arr[j + 1] = key;
      printf("Array after pass %d:", i);
      display(arr, n);
   }
}

void Selection_Sort(int arr[], int n)
{
   int i, j, minIndex, temp;
   for (i = 0; i < n - 1; i++)
   {
      minIndex = i;
      for (j = i + 1; j < n; j++)
      {
         if (arr[j] < arr[minIndex])
         {
            minIndex = j;
         }
      }
      if (i != minIndex)
      {
         temp = arr[i];
         arr[i] = arr[minIndex];
         arr[minIndex] = temp;
      }
      printf("Array after pass %d:", i + 1);
      display(arr, n);
   }
}

void Bubble_Sort(int arr[], int n)
{
   int i, j, temp;
   for (i = 0; i < n - 1; i++)
   {
      for (j = 0; j < n - 1 - i; j++)
      {
         if (arr[j] > arr[j + 1])
         {
            temp = arr[j];
            arr[j] = arr[j + 1];
            arr[j + 1] = temp;
         }
      }
      printf("Array after pass %d:", i + 1);
      display(arr, n);
   }
}

void display(int arr[], int n)
{
   int i;
   for (i = 0; i < n; i++)
   {
      printf("%d ", arr[i]);
   }
   printf("\n");
}

void copy_arr(int source[], int destination[], int n)
{
   int i;
   for (i = 0; i < n; i++)
   {
      destination[i] = source[i];
   }
}
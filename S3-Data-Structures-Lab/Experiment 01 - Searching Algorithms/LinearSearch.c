#include<stdio.h>
void main()
{
   int n,i,key;
   printf("Enter the limit:");
   scanf("%d",&n);
   int array[n];
   printf("Enter %d elements:",n);
   for(i=0;i<n;i++)
   {
      scanf("%d",&array[i]);
   }
   printf("Enter the key:");
   scanf("%d",&key);
   for(i=0;i<n;i++)
   {
      if(array[i]==key)
      {
         break;
      }
   }
   if(i<n)
   {
      printf("Element found at position %d \n",i+1);
   }
   else
      printf("Element not found\n");
}
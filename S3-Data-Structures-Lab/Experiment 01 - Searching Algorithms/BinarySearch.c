#include<stdio.h>

void sort(int a[], int n)
{
   int i,j,t;
   for(i=0;i<n-1;i++)
   {
      for(j=0;j<n-1-i;j++)
      {
         if(a[j]>a[j+1])
         {
            t=a[j];
            a[j]=a[j+1];
            a[j+1]=t;
         }
      }
   }
}

void main()
{
   int a[10],i,n,key;
   printf("Enter how many elements:");
   scanf("%d",&n);
   printf("Enter the elements:");
   for(i=0;i<n;i++)
   {
      scanf("%d",&a[i]);
   }
   sort(a,n);
   printf("The sorted array is:\n");
   for(i=0;i<n;i++)
   {
      printf("%d",a[i]);printf("\t");
   }

   printf("\nEnter the element to be searched:");
   scanf("%d",&key);
   int low=0,high=n-1,mid=0;
   while(low<=high)
   {
      mid=(low+high)/2;
      if(key==a[mid])
      {
         printf("Element found at position:%d \n",mid+1);
         break;
      }
      if(key>a[mid])
      {
         low=mid+1;
      }
      if(key<a[mid])
      {
         high=mid-1;
      }
   }
   if(low>high)
   {
      printf("Unsuccessful search \n");
   }
}
#include<stdio.h>
void main()
{
   int i,j,sm[10][10],sr[10][10],r,c;
   printf("Enter number of rows:");
   scanf("%d",&r);
   printf("Enter number of columns:");
   scanf("%d",&c);
   printf("Enter the elements:\n");
   for(i=0;i<r;i++)
   {
      for(j=0;j<c;j++)
      {
         scanf("%d",&sm[i][j]);
      }
   }
   printf("Entered Matrix \n");
   for(i=0;i<r;i++)
   {
      for(j=0;j<c;j++)
      {
         printf("%d \t",sm[i][j]);
      }
      printf("\n");
   }
   int k=1;
   sr[0][0]=r;
   sr[0][1]=c;
   for(i=0;i<r;i++)
   {
      for(j=0;j<c;j++)
      {
         if(sm[i][j]!=0)
         {
            sr[k][0]=i;
            sr[k][1]=j;
            sr[k][2]=sm[i][j];
            k++;
         }
      }
   }
   k=k-1;
   sr[0][2]=k;
   printf("Sparse Matrix Representation \n");
   for(i=0;i<=k;i++)
   {
      for(j=0;j<3;j++)
      {
         printf("%d \t",sr[i][j]);
      }
      printf("\n");
   }
}
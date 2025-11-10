#include<stdio.h>

int hashTable[10];

void initHashtable();
int HashCode(int key, int n);
void insert(int key, int n);
void displayHashtable();

int main()
{
   int n, key;
   initHashtable();
   printf("Enter the size of Hash Table: ");
   scanf("%d", &n);
   while(1)
   {
      printf("Enter key to be inserted (or -1 to exit): ");
      scanf("%d", &key);
      if (key == -1)
      {
         printf("Exiting...\n");
         break;
      }
      insert(key, n);
      displayHashtable();
   }
   return 0;
}

void initHashtable()
{
   for(int i = 0; i < 10; i++)
   {
      hashTable[i] = -1;
   }
}

int HashCode(int key, int n)
{
   return key % n;
}

void insert(int key, int n)
{
   int Index = HashCode(key, n);
   int OriginalIndex = Index;
   while(hashTable[Index] != -1)
   {
      printf("\nCollision detected at Index %d\n", Index);
      Index = (Index + 1) % 10; // Note: Hardcoded to 10
      if(OriginalIndex == Index)
      {
         printf("\nHash Table is full. Cannot insert\n");
         return;
      }
   }
   hashTable[Index] = key;
   printf("\nkey (%d) inserted at Index %d\n", key, Index);
}

void displayHashtable()
{
   printf("\nCurrent Hash Table:\n");
   for (int i = 0; i < 10; i++) // Note: Hardcoded to 10
   {
      if (hashTable[i] != -1)
      {
         printf("Hash[%d] = %d\n", i, hashTable[i]);
      }
      else
      {
         printf("Hash[%d] = \n", i);
      }
   }
   printf("\n");
}
#include<stdio.h>
#include<string.h>

int main()
{
   char puzzle[10][10] = { 0 };
   char line[10] = { 0 };
   int i,j, rows=0;
   FILE *fp;
   fp = fopen("arr.txt", "r");
   if (fp == NULL) { 
      printf("Error in opening file\n");
      return 1;
   }

   while (fgets(line, sizeof(line), fp) != NULL)
   {
      if(fgets(line, 10, fp) != NULL){
         for(i = 0; i < (strlen(line) - 1); i++)
            puzzle[rows][i] = line[i];
      }
      rows++;   
   }
   for(i = 0; i < 10; i++)
      for(j = 0; j < 10; j++)
         printf("%c", puzzle[i][j]);
}
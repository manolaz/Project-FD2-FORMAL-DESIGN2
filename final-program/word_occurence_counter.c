#include <stdio.h>
#include<string.h>

int occurence(char text[100], char word[20])
{
   int i, j, ls, lw, temp, countW=0, chk;
   ls = strlen(text);
   lw = strlen(word);
   for(i=0; i<ls; i++)
   {
      temp = i;
      for(j=0; j<lw; j++)
      {
         if(text[i]==word[j])
            i++;
      }
      chk = i-temp;
      if(chk==lw)
         countW++;
      i = temp;
   }
   return countW;
}
#include <stdio.h>
#include<string.h>

/*@
requires \nothing;
ensures (\result.success) ==> (\result.countW > 0) ;
assigns \nothing;
*/
int counter(char text[100])
{
   int i,ls, countW=0;
   ls = strlen(text);
   for (i = 0; text[i] != '\0';i++)
   {
    if( text[i] == ' ' && text[i+1] != ' ')
        countW++;
   }
   return countW;
}

/*@ assigns \nothing ;
ensures \result >= 0 ;*/
int main(void) {

   const char hello[] = { 'h', 'e', 'l', 'l', 'o', '\0'};

   /*@ assert \valid_read(&hello[0]) && \valid_read(&helli[0]) ; */
   counter(hello);
   return 0;
} 
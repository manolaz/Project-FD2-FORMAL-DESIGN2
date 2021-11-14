#include <stdint.h>
#include <string.h>
#include <stdio.h>

/*@  
    requires validPointers: valid_read_string(s1) && valid_read_string(s2);
    requires validLengthS1: n >= strlen(s1) >= 0;
    requires validLengthS2: n >= strlen(s2) >= 0;
    assigns \nothing ;
    allocates \nothing ;  
    frees \nothing ;
    behavior allEqual:
        assumes \forall integer k; 0 <= k <= strlen(s1) ==> s1[k] == s2[k];
        ensures \result == 0;
    behavior SomeDifferent:
        assumes \exists integer k; 0 <= k <= strlen(s1) && s1[k] != s2[k];
        ensures \result != 0;
    
    disjoint behaviors;
    complete behaviors;
    */ 
int stringCompare(const char* s1, const char* s2, size_t n) {
    if (s1 == s2) 
        return 0;
    size_t i = 0;

    /*@ assert \valid_read(s1) ; */
    /*@ assert \valid_read(s2) ;*/
    /*@ loop invariant index: 0 <= i <= strlen(\at(s1,Pre));
        loop invariant index_1: 0<= i <= strlen(\at(s2,Pre));
        loop invariant s1_pos: s1 == \at(s1,Pre)+i;
        loop invariant s2_pos: s2 == \at(s2,Pre)+i;
        loop invariant equal: \forall integer j; 0<= j < i ==> \at(s1,Pre)[j] == \at(s2,Pre)[j];
        loop invariant not_eos: \forall integer j; 0<= j < i ==> \at(s1,Pre)[j] != 0;
        loop assigns i , s1, s2; */    
    while (*s1 == *(s2++))
    {
        /*@ assert i <= n ; */
        ++i;
        if (*(s1++) == '\0')
            return 0;
    }
   
    return *(s1) - *(--s2);
}

/*@
  requires valid_string(str);
  requires strlen(str) < SIZE_MAX;
  assigns \nothing ;
  ensures rightResult: \result == strlen(\old(str));
  ensures rightEndCharacter: str[\result] == '\0' ;  */
size_t stringLength(const char* str) {
    size_t result = 0;

    /*@ loop assigns result ;
        loop invariant 0 <= result <= strlen(str);
        loop invariant \forall integer i; 0<= i < result ==> str[i]!=0;
    */
    while (str[result++] != '\0');

    return --result;

}

/*@
assigns \nothing ;
ensures \result >= 0 ;
*/
int main(void) {

   const char hello[] = { 'h', 'e', 'l', 'l', 'o', '1', '\0'};
   const char bonjour[] =  { 'b', 'o', 'n', 'j', 'o', 'u', 'r', '\0'};

   /*@ assert \valid_read(&hello[0]) && \valid_read(&bonjour[0]) ; */
   stringCompare(hello, bonjour, 7);
   return 0;
} 
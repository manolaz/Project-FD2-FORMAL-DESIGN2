#include <stdbool.h>
#include <limits.h>

typedef unsigned int size_t;
typedef struct Average avg;
struct Average
{
    bool success;
    long long average;
};
/*@
axiomatic Sum{
    logic integer sum(int * t , integer start, integer end);

    axiom sum_false :
        \forall int *t, integer start , integer stop;
        start >= stop ==> sum(t,start,stop) == 0;

    axiom sum_true_start :
        \forall int *t, integer start , integer stop;
        0 <= start < stop ==>
        sum(t,start,stop) == sum(t,start,start+1) + sum(t,start+1,stop);

    axiom sum_true_end :
        \forall int *t, integer start , integer stop;
        0 <= start < stop ==>
        sum(t,start,stop) == sum(t,start,stop-1) + sum(t,stop-1,stop);

    axiom sum_split :
        \forall int *t, integer start , integer stop, integer middle;
        0 <= start<=  middle < stop ==>
        sum(t,start,stop) == sum(t,start,middle) + sum(t,middle,stop);


    axiom sum_alone :
        \forall int *t, integer start;
        (0<=start)
        ==>
        sum(t,start,start+1) == t[start] ;
}

*/
/*@
requires \valid(array + (0..size-1));
ensures (!\result.success) ==> size == 0 ;
ensures (\result.success) ==> (\result.average == sum(array,0,size)/size) ;
assigns \nothing;
*/
avg average(int *array, size_t size)
{
    //we use a structure to be sure that the function finish without error
    avg ret;
    ret.success = true;
    ret.average = 0;
    if (size == 0)
    {
        //if the size == 0 the function will fail
        ret.success = false;
        return ret;
    }
    else
    {
        /*
        the average is the sum of all the element of the array divided by the size
        An int is between - 2^15-1 and 2^15-1 that imply that the sum of
        all the element of an array is between
        -2^15 * size and 2^15 * size as size is between 0 and 2^16
        the sum is between -2^31 and 2^31
        a long long is between -2^63 and 2^63

        the sum of all the element can be inside a long long.
        */
        long long sum = 0;

        /*@
        loop assigns i, sum ;
        loop invariant 0 <= i <= size;
        loop invariant sum == sum(array,0,i);
        loop invariant INT_MIN * i <= sum <= INT_MAX * i;
        */

        for (size_t i = 0; i < size; i++)
        {
            //@assert INT_MIN * i <= sum <= INT_MAX * i;

            sum += array[i];
            //@assert  i+1 <= size;

            //@assert INT_MIN * (i+1) <= sum <= INT_MAX * (i+1);
            //@assert ((LLONG_MIN < INT_MIN * size ) && (LLONG_MAX > INT_MAX* size));
            //@assert LLONG_MIN <= sum <= LLONG_MAX;

            //@assert sum == sum(array,0,i) + array[i];
        }
        ret.average = sum / size;
        return ret;
    }
}
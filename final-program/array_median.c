#include <stdbool.h>
#include <limits.h>

typedef unsigned int size_t;
typedef struct Median med;

/*@
    requires \valid(a);
    requires \valid(b);
    ensures *a == \old(*b);
    ensures *b == \old(*a);
    assigns *a,*b;
    */
    int swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
        return a,b;
    }

    /*@
    requires \valid(t +(leftmost..rightmost));
    requires 0 <= leftmost < INT_MAX;
    requires 0 <= rightmost < INT_MAX;
    decreases (rightmost - leftmost);
    assigns *(t+(leftmost..rightmost));
    */
    int * quickSort(int * t, int leftmost, int rightmost)
    {
        // Base case: No need to sort arrays of length <= 1
        if (leftmost >= rightmost)
        {
            return;
        }  
        // Index indicating the "split" between elements smaller than pivot and 
        // elements greater than pivot
        int pivot = t[rightmost];
        int counter = leftmost;
        /*@
            loop assigns i, counter, *(t+(leftmost..rightmost));
            loop invariant 0 <= leftmost <= i <= rightmost + 1;
            loop invariant 0 <= leftmost <= counter <= i;
            loop invariant \forall int i; leftmost <= i < counter ==> t[i] <= pivot;
            loop variant rightmost - i;
        */
        for (int i = leftmost; i <= rightmost; i++)
        {
            if (t[i] <= pivot)
            {
                /*@assert \valid(&t[counter]);*/
                /*@assert \valid(&t[i]);*/
                swap(&t[counter], &t[i]);
                counter++;
            }
        }

        // NOTE: counter is currently at one plus the pivot's index 
        // (Hence, the counter-2 when recursively sorting the left side of pivot)
        if (counter >= 2)
        return quickSort(t, leftmost, counter-2); // Recursively sort the left side of pivot
        if (counter < INT_MAX)
        return quickSort(t, counter, rightmost);   // Recursively sort the right side of pivot
    }

// struct Median
// {
//     int median;
// };

// Function for calculating median
/*@
requires \valid(array + (0..size-1));
ensures (!\result.success) ==> size == 0 ;
ensures (\result.success) ==> (\result.median <= sum(array,0,size)) ;
assigns \nothing;
*/
int median(int * array, size_t size)
{
    int median=0;
    // First we sort the array
    int * sorted_array = quickSort(array, array, array + size);
 
    // check for even case
    if (size % 2 != 0)
        median = sorted_array[size/2];
    else
        median = (sorted_array[(size - 1) / 2] + sorted_array[size / 2]) / 2.0;

    return median;
}
#include <limits.h>
/*@
    requires \valid(a);
    requires \valid(b);
    ensures *a == \old(*b);
    ensures *b == \old(*a);
    assigns *a,*b;
    */
    void swap(int *a, int *b)
    {
        int temp = *a;
        *a = *b;
        *b = temp;
    }

    /*@
    requires \valid(t +(leftmost..rightmost));
    requires 0 <= leftmost < INT_MAX;
    requires 0 <= rightmost < INT_MAX;
    decreases (rightmost - leftmost);
    assigns *(t+(leftmost..rightmost));
    */
    void quickSort(int * t, int leftmost, int rightmost)
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
        quickSort(t, leftmost, counter-2); // Recursively sort the left side of pivot
        if (counter < INT_MAX)
        quickSort(t, counter, rightmost);   // Recursively sort the right side of pivot
    }
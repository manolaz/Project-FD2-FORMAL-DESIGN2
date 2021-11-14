typedef unsigned int size_t;
/*@ axiomatic Sum_Int {
      logic int sum_int(int *values, integer begin, integer end)
          reads values[begin .. (end - 1)];

      axiom empty_int:
        \forall int *p, integer begin, end; begin >= end
            ==> sum_int(p, begin, end) == 0;

      axiom range_int:
        \forall int *p, integer begin, end; begin < end
            ==> sum_int(p, begin, end) == sum_int(p, begin, end - 1) + p[end - 1];
}
*/

/*@ requires \valid_read(values + (0 .. size - 1));

    assigns \nothing;

    ensures \result == sum_int(values, 0, size);
*/
int sum_int_array(const int *values, size_t size)
{
    int sum = 0;
    /*@ loop invariant 0 <= index <= size;
        loop invariant sum == sum_int(values, 0, index);
        loop assigns sum, index;
        loop variant size - index;
    */
    for (size_t index = 0; index < size; index++)
    {
        sum += values[index];
    }
    return sum;
}
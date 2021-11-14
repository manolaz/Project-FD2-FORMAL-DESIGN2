/*@
assigns sum;
requires size > 0;
requires \forall int i; 0 <= i < size ==> \valid (array + i);
loop assigns i;
loop invariant 0<=i<size;
ensures \result == \sum(0,size−1,\lambda integer i; array[i]);
*/
int sum(int ∗array , int size) 
{
	int sum=0;
	for (int i = 0; i < size ; i++) 
	{
		sum = sum+array[i];
	}
	return sum;
}

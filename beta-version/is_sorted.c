/*@
requires size >= 0;
requires \valid(t + (0..size - 1));
ensures \result == 0 || \result == 1;
ensures (\result == 0) ==> \exists int i; 0 <= i < size - 1 ==> t[i] > t[i + 1];
assigns \nothing;
*/
int is_asc(int *t, int size) {
    if (size == 0) return 1;
    /*@
    loop assigns i;
    loop invariant 1 <= i <= size;
    loop invariant \forall int j; 1 <= j < i ==> t[j - 1] <= t[j];
    loop variant size - i;
    */
    for (int i = 1; i < size; i++) {
        if (t[i] < t[i - 1]) return 0;
    }
    return 1;
}

/*@
requires size >= 0;
requires \valid(t + (0..size - 1));
ensures \result == 0 || \result == 1;
ensures (\result == 0) ==> \exists int i; 0 <= i < size - 1 ==> t[i] < t[i + 1];
assigns \nothing;
*/
int is_desc(int *t, int size) {
    if (size == 0) return 1;

    /*@
    loop assigns i;
    loop invariant 1 <= i <= size;
    loop invariant \forall int j; 1 <= j < i ==> t[j - 1] >= t[j];
    loop variant size - i;
    */
    for (int i = 1; i < size; i++) {
        if (t[i] > t[i - 1]) return 0;
    }
    return 1;
}

/*@
predicate is_asc(int *t, int size) = \forall int j, int k; 0 <= j <= k < size ==> t[j] <= t[k];
predicate is_desc(int *t, int size) = \forall int j, int k; 0 <= j <= k < size ==> t[j] >= t[k];
predicate not_sorted(int *t, int size) = \exists int i, j, k, l; (0 <= i <= j <= k <= l < size) ==> (t[i] > t[j] && t[k] < t[l]);

lemma array_is_sorted_asc: \forall int *t, int size; (\forall int i; 0 <= i < size - 1 ==> t[i] <= t[i + 1]) ==> is_asc(t, size);
lemma array_is_sorted_desc: \forall int *t, int size; (\forall int i; 0 <= i < size - 1 ==> t[i] >= t[i + 1]) ==> is_desc(t, size);
*/

/*@
requires size >= 0;
requires \valid(t + (0..size - 1));
ensures \result == 0 || \result == 1;
ensures \result == 0 ==> not_sorted(t, size);
ensures \result == 1 ==> is_asc(t, size) || is_desc(t, size);
assigns \nothing;
*/
int is_sorted(int *t, int size) {
    if (size == 0) return 1;
    if (is_asc(t, size) == 1 || is_desc(t, size) == 1) return 1;
    return 0;
}

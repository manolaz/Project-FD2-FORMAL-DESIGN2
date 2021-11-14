# Project-FD2-FORMAL-DESIGN2
Formal Specification Languages

Project to to:

1/Computing the sum of values of an array of int.

==> frama-c -wp -wp-rte  final-program/sum2.c 
[kernel] Parsing final-program/sum2.c (with preprocessing)
[rte] annotating function inc_cell
[wp] 5 goals scheduled
[wp] [Alt-Ergo 2.4.1] Goal typed_inc_cell_ensures : Timeout (Qed:3ms) (10s)
[wp] Proved goals:    4 / 5
  Qed:               2  (0.83ms-1ms-2ms)
  Alt-Ergo 2.4.1:    2  (15ms-20ms) (82) (interrupted: 1)


2/Computing the average value of an array of int.

==> final-program/array_average.c

3/Computing the median value of an array of int.

==> final-program/array_median.c

4/Counting exactly the number of words in a text

==>final-program/words_counter.c

5/Counting the number of occurences of a word in a text

==>final-program/word_occurence_counter.c

6/Compare 2 differents strings

==>final-program/strings_compare.c

frama-c -wp -wp-rte  final-program/strings_compare.c

## Command to execute the Frama C prover

```bash
 frama-c -wp -wp-rte  final-program/"program.c"
```

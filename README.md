# Project FORMAL DESIGN 2 Prover ACSL Frama-C
Formal Specification Languages

Master of Computer Science 

University of Bordeaux 

Instructor: Professor Hugo GIMBERT

## Team members:

+ Nguyen Vu Anh Trung

+ Nguyen Quoc Khanh

+ Mr Nguyen Chi Cong


November 10, 2021 



## Project programs:

1/Computing the sum of values of an array of int.

==> final-program/sum2.c

2/Computing the average value of an array of int.

==> final-program/array_average.c

3/Computing the median value of an array of int.

==> final-program/array_median.c

4/Counting exactly the number of words in a text

==>final-program/words_counter.c

5/Counting the number of occurences of a word in a text

==>final-program/word_occurence_counter.c

6/Compare 2 differents strings "hello" vs "bonjour"

==>final-program/strings_compare.c

## Command to execute the Frama C prover

```bash
 frama-c -wp -wp-rte  final-program/"program.c"
```


## Bibliographies:

1.Combined static and dynamic analyses in Frama-C: An Overview (Nikolai Kosmatov, CEA, France)

https://www.youtube.com/watch?v=iC4i25jBaYg
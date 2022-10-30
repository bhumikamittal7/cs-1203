/*
for any comparison based sorting algorithm,
HOW MUCH time it takes to sort a list of n elements

n -> 2 branches of decision making 

there is starting list [x1, x2, x3, ... xn] --> sorted list
there are n! possible ways to sort the list
1 out of n! is the correct answer

How many IFs do we need to write to sort a list of n elements?
log_2 (n!) = log_2 (n * (n-1) * (n-2) * ... * 1) = log_2 (n) + log_2 (n-1) + log_2 (n-2) + ... + log_2 (1) > log_2(n^n) = n*log_2(n)
- Need more than nlogn time to do it.
*/
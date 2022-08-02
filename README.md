# PUSH_SWAP

## Summary

This project will make you sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various types of algorithms and choose the most appropriate solution (out of many) for an optimized data sorting.

Version: 6


### Ways to solve the problem

1. Treat the stacks as doubly linked lists, hence having all the operations laid out by the rules as possible.
2. Sort the stack using quick sort algorithm.

// Random ideas inside my head :point_down:
3. Try to find a good pivot and place half the items in the other list.
4. You can also try to run the operations that are similar on 

### NOTES FOR SELF

```
SET n   = 0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15

LIS l1  = 0, 2, 6, 9, 11, 15.
SET m   = 8, 4, 12, 10, 14, 1, 5, 13, 3, 7

sorted_b= 1, 3, 4, 5, 7, 8, 10, 12, 13, 14
Indexes = 0, 1, 2, 3, 4, 5,  6,  7,  8,  9

8, 4, 12, 10, 14, 1, 5, 13, 3, 7
```
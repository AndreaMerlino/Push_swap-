42 Push_Swap

Because swap_push isn't as natural

Given a set of integers, sort it using a predefined set of instructions using two stacks. The instruction set is defined below. This program outputs a program in push_swap instructions that sorts the input integers.

⚠️ Warning: Don't copy/paste anything you don't understand: it's bad for you, and for the school.

INSTRUCTION SET
(For the following instructions, if the instruction is not possible, the part of it that can't be executed won't.)

sa (swap a): Swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.

rrr : rra and rrb at the same time.

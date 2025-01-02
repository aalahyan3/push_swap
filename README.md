# Push_Swap
this project about satck sorting, it's wierd be cause stack is not the best Data Structure to sort data on, but the goal of theproject is to solve a pretty tricky problem, because you only havesome sets of instructions to use, and you can the minimum you can.
# TASK
you have 2 stacks a and b, a containts a random integers, Sort them on a and use b as an asset
# Instructions
`sa` swap a
`sb` swap b
`ra` rotate_a (top be in the bottom)
`rb` same for b
`rra` reverse_rotate_a (bottom in the top)
`rrb` you know ;)
`rr` ra and rb at the same time
`rrr` rra and rrb at the same time
# Algorithm
  #### 1. push all from a to be save 3 (push smallests first)
  #### 2. sort the remaining 3 in b
  #### 3. push from b to a, each node from b must target the `closest larget`number from a
  #### 4. calculate the cost of each node, and push the cheapest (cost = moves to bring node_b t + moves to bring target node_a to top + 1 (push move)

# Benchmarks
  ### for 80% score : less than 700 moves for satck of size = 100. `(my average = 600 moves)`
  ### for 100% score : less that 5500 moves for a stack of size = 500. `(my average = 4700 moves)`

# Bonus
make a prgram that executes the the instructions outputed from push-swap and see if they actually sort the stack by outputing `OK` or  `KO`

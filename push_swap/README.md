# PUSH_SWAP

## Overview

Apply the **LIS** algorithm. The numbers that belong to the sequence stay in **stack A**, while other numbers move to **stack B**. Then, calculate the operations for each number in **stack B** to move it back to **stack A**, choosing the number with the least moves. After moving all the numbers back to **stack A**, perform a final check to see if the first number is the smallest.

## Process

- **Parsing**
  - Handle invalid arguments
    - Empty args
    - Non-integer values
    - Integer overflow or underflow
  - Check for duplicate numbers.
- **LIS**: Apply the Longest Increasing Subsequence algorithm to get sequence.
```
for (int i = 0; i < n; i++)
{
	for (int j = 0; j < i; j++)
	{
		if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
		{
			lis[i] = lis[j] + 1;
			prev[i] = j;
		}
	}
}
```
- **Move to B**: Transfer numbers not part of the LIS to **stack B**.
- **Move to A**: Move numbers back to **stack A** using the fewest operations.
- **Final Check**: Ensure that the first number in **stack A** is the smallest.

## Possible Improvement

- If the LIS length is ≤ 3 (possible in the case of a reverse sorted sequence), there's no need to apply the LIS algorithm. Instead, simply leave the three numbers in **stack A** and move the rest to **stack B**.

- **Move to B**: Transfer numbers not part of the LIS to **stack B**.
- **Move to A**: Move numbers back to **stack A** using the fewest operations.  Don't know why that rrr+ra/rb doesn't perform well
- **Final Check**: Ensure that the first number in **stack A** is the smallest.

## Possible Improvement

- If the LIS length is ≤ 3 (possible in the case of a reverse sorted sequence), there's no need to apply the LIS algorithm. Instead, simply leave the three numbers in **stack A** and move the rest to **stack B**.
- Using **Linked List** for stacks 

### Useful Links
- [Understanding the program](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Project explaining applying LIS algorithm](https://github.com/sisittu99/push_swap/blob/master/README_EN.md)
- [Visualizer in Python](https://github.com/10257/push_swap_viz_kivy)
- [Another Visualizer](https://github.com/o-reo/push_swap_visualizer)
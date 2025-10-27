# Compare Two Linked Lists 

Problem:
Determine whether two singly linked lists are identical: same node values in the same order and same length.

Approach (my strategy):
- Use two pointers, one for each list.
- Iterate both lists simultaneously:
  - If both nodes are non-null, compare their values. If values differ, return false.
  - Advance both pointers.
- After the loop, return true only if both pointers are null (lists ended together); otherwise return false.
- Prefer an iterative implementation to keep O(1) extra space.

Edge cases:
- Both lists empty -> true.
- One empty and the other non-empty -> false.
- Early mismatch in values -> false.

Time complexity:
- O(n) where n = max(length of list1, length of list2). Each node is visited at most once.

Space complexity:
- O(m+n) extra space (only a few pointers).

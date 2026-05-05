from typing import Optional

class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        def get_reversed_list(head: ListNode) -> ListNode:
            prev_node, curr_node = None, head 
            
            while curr_node is not None:
                next_node = curr_node.next
                curr_node.next = prev_node
                
                prev_node = curr_node
                curr_node = next_node
            
            return prev_node
        
        def get_number_from_linked_list(head: ListNode) -> int:
            curr = head 
            num = 0
            while curr is not None:
                num += curr.val
                num *= 10 
                curr = curr.next 
            return num // 10
        
        curr = get_reversed_list(l1)
        n1 = get_number_from_linked_list(curr)
        
        curr = get_reversed_list(l2)
        n2 = get_number_from_linked_list(curr)
        
        s = n1 + n2
        digits = []
        
        if s == 0: digits.append(ListNode(0))
        while s:
            digits.append(ListNode(s % 10))
            s //= 10
        
        if len(digits) == 1: return digits[0]
        
        for i in range(1, len(digits)):
            digits[i - 1].next = digits[i]
        
        return digits[0]
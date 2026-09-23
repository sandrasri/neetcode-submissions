# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: Optional[ListNode]
        :type k: int
        :rtype: Optional[ListNode]
        """
        if not head or k == 1:
            return head
        
        finalNode = ListNode(0)
        current_tail = finalNode
        stack = []

        curr = head
        while curr:
            while curr and len(stack) < k:
                stack.append(curr)
                curr = curr.next
            
            if len(stack) == k:
                while stack:
                    node = stack.pop()
                    current_tail.next = node
                    current_tail = current_tail.next
                
                current_tail.next = None
            
            else:
                if stack:
                    current_tail.next = stack[0]
        
        return finalNode.next
        
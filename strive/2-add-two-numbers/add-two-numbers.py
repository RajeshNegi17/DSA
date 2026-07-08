# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        dummy = ListNode(0)
        ans = dummy
        carry = 0
        while l1 or l2 :
            l1val = l1.val if l1 else 0
            l2val = l2.val if l2 else 0
        
            value = l1val + carry + l2val
            carry = value//10
            if value>9 :
                value = value%10
            new = ListNode(value)
            ans.next = new
            ans = ans.next
            if l1: l1 = l1.next
            if l2: l2 = l2.next
        if carry!=0:
            ans.next = ListNode(carry)
        return dummy.next
        
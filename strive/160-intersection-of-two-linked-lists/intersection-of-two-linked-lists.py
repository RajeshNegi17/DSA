# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        one = headA
        two = headB

        while one!=two :
            if one:
                one = one.next
            else:
                one = headB

            if two:
                two = two.next
            else:
                two = headA

        return one
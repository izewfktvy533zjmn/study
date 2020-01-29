# Definition for singly-linked list.

class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None



class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        ans = ListNode(-1)
        ans_tmp = ans
        
        while (not l1 == None) and (not l2 == None):
            if l1.val >= l2.val:
                node = ListNode(l2.val)
                l2 = l2.next
            
            else:
                node = ListNode(l1.val)
                l1 = l1.next
            
            ans_tmp.next = node
            ans_tmp = node
            
        if l1 == None:
            while not l2 == None:
                node = ListNode(l2.val)
                l2 = l2.next
                
                ans_tmp.next = node
                ans_tmp = node
        
        else:
            while not l1 == None:
                node = ListNode(l1.val)
                l1 = l1.next
                
                ans_tmp.next = node
                ans_tmp = node
            
            
        return ans.next
    

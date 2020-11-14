# Populating Next Right Pointers in Each Node

"""
# Definition for a Node.
class Node:
    def __init__(self, val: int = 0, left: 'Node' = None, right: 'Node' = None, next: 'Node' = None):
        self.val = val
        self.left = left
        self.right = right
        self.next = next
"""
from queue import Queue 
class Solution:
    def connect(self, root: 'Node') -> 'Node':
        if not root:
            return root
        q = Queue()
        q.put(root)
        
        while not q.empty():
            sz = q.qsize()
            prev = None
            for i in range(sz):
                curr = q.get()
                if(curr.left):
                    q.put(curr.left)
                if(curr.right):
                    q.put(curr.right)
                if(prev):
                    prev.next = curr
                prev = curr
            prev.next = None
        return root
#!/usr/bin/env python3

class Node(object):
    def __init__(self, results):
        self.results = results
        self.prev = None
        self.next = None



class LinkedList(object):
    def __init__(self):
        self.haed = None
        self.tail = None


    def move_to_front(self, node):
        pass


    def append_to_front(self, node):
        pass


    def remove_to_tail(self, node):
        pass



class Cache(object):
    def __init__(self, max_size):
        self.max_size = max_size
        self.size = 0
        self.lookup = {} # key: query, value: Node
        self.linked_list = LinkedList()


    def set(self, query, results):
        node = self.lookup.get(query)
        
        if node is not None:
            node.results = results
            self.linked_list.move_to_front(node)
        
        else:
            if self.size == self.max_size:
                self.lookup.pop(self.linked_list.tail.query, None)
                self.linked_list.remove_to_tail()

            else:
                self.size += 1

            new_node = Node(results)
            self.linked_list.append_to_front(new_node)
            self.lookup[query] = new_node



    def get(self, query):
        node = self.lookup.get(query)

        if node is not None:
            self.linked_list.move_to_front(node)
            return node.results

        else:
            return None


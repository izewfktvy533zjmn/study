#!/usr/bin/env python3

class Node(object):
    def __init__(self, results):
        self.results = results
        self.prev = None
        self.next = None



class LinkedList(object):
    def __init__(self):
        self.head = None
        self.tail = None


    def move_to_front(self, node):
        if self.head == self.tail:
            pass

        if node is self.tail:
            self.tail = self.tail.prev
            node.next = self.head
            self.head = node

        elif node is not self.head:
            node.prev.next = node.next
            node.next = self.head
            self.head = node


    def append_to_front(self, node):
        if self.head is None:
            self.head = node
            self.tail = node
        
        else:
            self.head.prev = node
            node.next = self.head
            self.head = node


    def remove_to_tail(self):
        if self.tail is None:
            pass
        
        else:
            self.tail.prev.next = None
            self.tail =  self.tail.prev



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
                print("OK")
                self.lookup.pop(query, None)
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



if __name__ == '__main__':
    cache = Cache(3)
    
    cache.set("test1", "TEST1")
    print("cahce.linked_list", cache.linked_list.head.results, cache.linked_list.tail.results)
    print("set test1 as TEST1")

    cache.set("test2", "TEST2")
    print("set test2 as TEST2")
    print("cahce.linked_list", cache.linked_list.head.results, cache.linked_list.tail.results)
    
    cache.set("test3", "TEST3")
    print("set test3 as TEST3")

    cache.set("test4", "TEST4")
    print("set test4 as TEST4")

    print(cache.get("test2"))
    print("cahce.linked_list", cache.linked_list.head.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.next.results, cache.linked_list.tail.results)
    print()
    print("cahce.linked_list", cache.linked_list.head.next.next.next.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.next.next.next.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.next.next.next.next.results, cache.linked_list.tail.results)

    cache.set("test5", "TEST5")
    print("cahce.linked_list", cache.linked_list.head.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.next.results, cache.linked_list.tail.results)
    
    cache.set("test6", "TEST6")
    print("cahce.linked_list", cache.linked_list.head.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.next.results, cache.linked_list.tail.results)

    cache.set("test7", "TEST7")
    print("cahce.linked_list", cache.linked_list.head.results, cache.linked_list.tail.results)
    
    print("cahce.linked_list", cache.linked_list.head.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.next.results, cache.linked_list.tail.results)
    print()
    print("cahce.linked_list", cache.linked_list.head.next.next.next.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.next.next.next.results, cache.linked_list.tail.results)
    print("cahce.linked_list", cache.linked_list.head.next.next.next.next.next.results, cache.linked_list.tail.results)


    print(cache.get("test3"))
    print(cache.get("test4"))
    print(cache.get("test1"))


#!/usr/bin/env python3

import unittest
from lru_cache import Cache



class TestCache(unittest.TestCase):
    def test_set_1(self):
        query = "test1"
        results = "TEST1"
        expected = "TEST1"

        cache = Cache(3)
        cache.set(query, results)
        
        self.assertEqual(expected, cache.linked_list.head.results)
        self.assertEqual(expected, cache.linked_list.tail.results)


    def test_set_2(self):
        query1 = "test1"
        results1 = "TEST1"

        query2 = "test2"
        results2 = "TEST2"

        cache = Cache(3)
        cache.set(query1, results1)
        cache.set(query2, results2)

        self.assertEqual("TEST2", cache.linked_list.head.results)
        self.assertEqual("TEST1", cache.linked_list.tail.results)

        self.assertEqual(None, cache.linked_list.head.prev)
        self.assertEqual("TEST1", cache.linked_list.head.next.results)

        self.assertEqual("TEST2", cache.linked_list.tail.prev.results)
        self.assertEqual(None, cache.linked_list.tail.next)
    

    def test_set_3(self):
        query1 = "test1"
        results1 = "TEST1"

        query2 = "test2"
        results2 = "TEST2"

        query3 = "test3"
        results3 = "TEST3"

        cache = Cache(3)
        cache.set(query1, results1)
        cache.set(query2, results2)
        cache.set(query3, results3)

        self.assertEqual("TEST3", cache.linked_list.head.results)
        self.assertEqual("TEST1", cache.linked_list.tail.results)

        self.assertEqual(None, cache.linked_list.head.prev)
        self.assertEqual("TEST2", cache.linked_list.head.next.results)
        
        self.assertEqual("TEST3", cache.linked_list.head.next.prev.results)
        self.assertEqual("TEST1", cache.linked_list.head.next.next.results)


        self.assertEqual("TEST2", cache.linked_list.tail.prev.results)
        self.assertEqual(None, cache.linked_list.tail.next)
    
 
    def test_set_3(self):
        query1 = "test1"
        results1 = "TEST1"

        query2 = "test2"
        results2 = "TEST2"

        query3 = "test3"
        results3 = "TEST3"

        query4 = "test4"
        results4 = "TEST4"


        cache = Cache(3)
        cache.set(query1, results1)
        cache.set(query2, results2)
        cache.set(query3, results3)
        cache.set(query4, results4)

        self.assertEqual("TEST4", cache.linked_list.head.results)
        self.assertEqual("TEST2", cache.linked_list.tail.results)

        self.assertEqual(None, cache.linked_list.head.prev)
        self.assertEqual("TEST3", cache.linked_list.head.next.results)
        
        self.assertEqual("TEST4", cache.linked_list.head.next.prev.results)
        self.assertEqual("TEST2", cache.linked_list.head.next.next.results)


        self.assertEqual("TEST3", cache.linked_list.tail.prev.results)
        self.assertEqual(None, cache.linked_list.tail.next)
    
            

    def test_get_1(self):
        query1 = "test1"
        results1 = "TEST1"

        query2 = "test2"
        results2 = "TEST2"

        cache = Cache(3)
        cache.set(query1, results1)
        cache.set(query2, results2)
        ret = cache.get(query1)

        self.assertEqual(results1, ret)
        self.assertEqual("TEST1", cache.linked_list.head.results)
        self.assertEqual("TEST2", cache.linked_list.tail.results)
    
        self.assertEqual(None, cache.linked_list.head.prev)
        self.assertEqual("TEST2", cache.linked_list.head.next.results)

        self.assertEqual("TEST1", cache.linked_list.tail.prev.results)
        self.assertEqual(None, cache.linked_list.tail.next)
     
    
    def test_get_2(self):
        query1 = "test1"
        results1 = "TEST1"

        query2 = "test2"
        results2 = "TEST2"

        query3 = "test3"
        results3 = "TEST3"

        cache = Cache(3)
        cache.set(query1, results1)
        cache.set(query2, results2)
        cache.set(query3, results3)
        
        ret = cache.get(query1)
        self.assertEqual(results1, ret)
       
        ret = cache.get(query2)
        self.assertEqual(results2, ret)
        
        self.assertEqual("TEST2", cache.linked_list.head.results)
        self.assertEqual("TEST3", cache.linked_list.tail.results)

        self.assertEqual("TEST1", cache.linked_list.head.next.results)
        self.assertEqual("TEST1", cache.linked_list.tail.prev.results)






if __name__ == "__main__":
    unittest.main()

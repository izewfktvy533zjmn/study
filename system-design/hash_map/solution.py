#!/usr/bin/env python3
import hashlib



class Item(object):
    def __init__(self, key, value):
        self.key = key
        self.value = value



class HashTable(object):
    def __init__(self, size):
        self.size = size
        self.table = [[] for _ in range(self.size)]


    def _hash_function(self, key):
        hs = hashlib.md5(key.encode())
        key_int  = int.from_bytes(hs.digest(), 'little')
        
        return key_int % self.size


    def set(self, key, value):
        hash_index = self._hash_function(key)

        for item in self.table[hash_index]:
            if item.key == key:
                item.value = value
                return 

        self.table[hash_index].append(Item(key, value))


    def get(self, key):
        hash_index = self._hash_function(key)

        for item in self.table[hash_index]:
            if item.key == key:
                return item.value

        raise KeyError("Key not found")


    def remove(self, key):
        hash_index = self._hash_function(key)

        for index, item in enumerate(self.table[hash_index]):
            if item.key == key:
                del self.table[hash_index][index]
                return 

        raise KeyError("Key not found")



if __name__ == '__main__':
    hash_map = HashTable(10)

    while(1):
        command_str = input("command > ")

        if command_str == "set":
            key = input("key > ")
            value = input("value > ")

            hash_map.set(key, value)

        elif command_str == "get":
            key = input("key > ")
            value = hash_map.get(key)

            print(value)
        
        elif command_str == "remove":
            key = input("key > ")
            hash_map.remove(key)
        
        elif command_str == "exit":
            break
            
        else:
            print("error")


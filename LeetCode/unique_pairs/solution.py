#!/usr/bin/env python3

class Solution:
    def uniquePairs(self, nums, target):
        ans = []
        used = []

        for index, num in enumerate(nums):
            candidate_pair = target - num

            if candidate_pair in nums[index+1:] and not (num in used):
                ans.append((num, candidate_pair))
                used.append(num)
                used.append(candidate_pair)
        
        return len(ans)
    

    def another(self, nums, target):
        ans = set()
        used = []

        for num in nums:
            if target - num in used:
                ans.add((num, target - num))
            
            else:
                used.append(num)

        return len(ans)



if __name__ == '__main__':
    s = Solution()

    if 2 == s.uniquePairs([1, 1, 2, 45, 46, 46], 47):
        print("test case 1 is passed")
    else:
        print("test case 1 is unpassed")

    if 1 == s.uniquePairs([1, 1], 2):
        print("test case 2 is passed")
    else:
        print("test case 2 is unpassed")

    
    if 1 == s.uniquePairs([1, 5, 1, 5], 6):
        print("test case 3 is passed")
    else: 
        print("test case 3 is unpassed")

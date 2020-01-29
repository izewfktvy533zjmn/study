#!/usr/bin/env python3

class Solution:
    def searchSuggestionsSystem(self, products, searchWord):
        products = sorted(products)
        

        searchWord_ch = list(searchWord)
        #print(searchWord_ch)
        
        table = []
        for product in products:
            product_ch = list(product)
            #print(product_ch)
            
            i = 0
            diff = []

            if len(product_ch) <= len(searchWord_ch):
                while i < len(product_ch):
                    if not i == 0:
                        diff.append(diff[i-1] + abs(ord(searchWord_ch[i]) - ord(product_ch[i])))
                    else:
                        diff.append(abs(ord(searchWord_ch[i]) - ord(product_ch[i])))
                    i += 1
                
                while i < len(searchWord_ch):
                    if not i == 0:
                        diff.append(diff[i-1] + ord(searchWord_ch[i]))
                    else:
                        diff.append(ord(searchWord_ch[i]))

                    i += 1

            else:
                while i < len(searchWord_ch):
                    if not i == 0:
                        diff.append(diff[i-1] + abs(ord(searchWord_ch[i]) - ord(product_ch[i])))
                    else:
                        diff.append(abs(ord(searchWord_ch[i]) - ord(product_ch[i])))

                    i += 1
                
                while i < len(product_ch):
                    if not i == 0:
                        diff.append(diff[i-1] + ord(product_ch[i]))
                    else:
                        diff.append(ord(product_ch[i]))
                            
                    i += 1
            
            table.append(diff)

        
        answer = []
        for i in range(len(searchWord)):
            ans = []

            count = 0
            for index, element in enumerate(table):
                if element[i] == 0:
                    ans.append(products[index])
                    count += 1

                    if count == 3:
                        break
            
            answer.append(ans)

        return answer



if __name__ == '__main__':
    s = Solution()
    print(s.searchSuggestionsSystem(["mobile","mouse","moneypot","monitor","mousepad"], "mouse"))
    print(s.searchSuggestionsSystem(["havana"], "havana"))
    print(s.searchSuggestionsSystem(["bags","baggage","banner","box","cloths"], "bags"))
    print(s.searchSuggestionsSystem(["havana"], "tatiana"))

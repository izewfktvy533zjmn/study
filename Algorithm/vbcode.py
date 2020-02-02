class VBCode:
    def _createNumber(self, n):
        b_lst = []

        while True:
            b_lst.append(n % 128)

            if n < 128:
                break

            n = n // 128

        b_lst[0] += 128

        return b_lst[::-1]

    
    def encode(self, nums_lst):
        bs_lst = []

        for num in nums_lst:
            bs_lst.append(self._createNumber(num))

        return bs_lst


    def decode(self, bs_lst):
        nums_lst = []

        for bs in bs_lst:
            n = 0
            
            for b in bs:
                if b < 128:
                    n = n * 128 + b
                else:
                    n = n * 128 + b - 128

            nums_lst.append(n)
            n = 0
        
        return nums_lst
        

if __name__ == '__main__':
    vb = VBCode()
    
    nums_lst = [6, 130, 152, 282]
    print(nums_lst)

    encoded_nums = vb.encode(nums_lst)
    print(encoded_nums)

    decoded_nums = vb.decode(encoded_nums)
    print(decoded_nums)


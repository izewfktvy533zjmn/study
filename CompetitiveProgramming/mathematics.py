#!/usr/bin/env python3


# 素数判定
def is_prime(num):
	if num == 2:
		return True
	
	if num % 2 == 0 or num == 1:
		return False
	
	for i in range(3, num, 2):
		if num % i == 0:
			return False

	return True


# 最大公約数
def gcd(a, b):
	if a < b:
		t = a
		a = b 
		b = t
	
	while b != 0:
		t = a % b
		a = b
		b = t

	return a


# 最小公倍数
def lcm(a, b):
	return a * b / gcd(a, b)


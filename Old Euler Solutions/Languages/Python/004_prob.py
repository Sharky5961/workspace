'''
A palindromic number reads the same both ways.
The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
'''

max = 0

for x in range(999, 0, -1):
    for y in range(999, 0, -1):
        num = x * y

        if str(num) == str(num)[::-1] and max < num:
            max = num

print(max)

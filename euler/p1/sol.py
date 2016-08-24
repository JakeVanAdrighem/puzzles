'''
Doing this statically is significantly easier than to offer a dynamic option. 
In the case of a computation of a constant set of numbers up to a constant
maximum, we simply add loops
'''
vals = [3,5]
totalsum = 0
for num in range(1,1000):
	if num % 3 == 0:
		totalsum += num
		continue
	if num % 5 == 0:
		totalsum += num

print totalsum

val = 600851475143
biggest = 1

def isPrime(value):
	for num in range(2,value):
		if value % num == 0:
			return False
	return True
for x in range(1, 90000):
	if val % x == 0:
		if not isPrime(x):
			continue
		else:	
			biggest = x

print biggest

x = 0
y = 0
for val in range(1,101):
	x += val * val
	y += val
y = y * y
print y - x

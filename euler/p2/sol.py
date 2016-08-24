sum = 0
older = 1
old   = 2
new   = 0
totalsum   = 0
while old < 4000000:
	if old % 2 == 0:
		totalsum += old
	new = older + old
	older = old
	old = new

print totalsum

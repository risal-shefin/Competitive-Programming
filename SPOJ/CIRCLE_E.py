import math

t = int(input())
i = 1
while i <= t:
	inp = input()
	li = inp.split()
	r1 = float( li[0]); r2 = float(li[1]); r3 = float(li[2])
	d = (r1 * r2) + (r2 * r3) + (r3 * r1) + 2.0 * math.sqrt( (r1 + r2 + r3) * (r1 * r2 * r3) )
	ans = (r1 * r2 * r3) /  d
	print ( format(ans, '.6f'))

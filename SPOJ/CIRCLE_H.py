import math
import decimal

t = int(input())
i = 1
decimal.getcontext().prec = 85
while i <= t:
	inp = input()
	li = inp.split()
	r1 = decimal.Decimal(li[0]); r2 = decimal.Decimal(li[1]); r3 = decimal.Decimal(li[2])
	ans = (r1 * r2) + (r2 * r3) + (r3 * r1) + 2 * decimal.Decimal( (r1 + r2 + r3) * (r1 * r2 * r3) ).sqrt()
	ans = (r1 * r2 * r3) /  ans
	print ( decimal.Decimal(str(ans)).quantize(decimal.Decimal('.00000000000000000000000000000000000000000000000001'), rounding = decimal.ROUND_DOWN))

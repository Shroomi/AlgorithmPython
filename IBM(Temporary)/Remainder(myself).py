from time import time

def modulus(ans, kStep, p):
#input(integer): base(ans), exponent(kStep), divisor(p)
#output(integer): the value of (ans^kStep)%p
	result = 0
	if kStep == 1:
		result = ans % p
		return result
	if kStep % 2 == 0:
		temp = modulus(ans, kStep // 2, p)
		result = temp * temp % p
		return result
	else:
		temp = modulus(ans, kStep // 2, p)
		result = (temp * temp % p) * ans % p
		return result

def factorialMod(a, k, p):
#input(integer): base(a), factorial(k), divisor(p)
#output(integer): the value (a^k!)%p
	ans = a
	for kStep in range(1, k+1):
		ans = modulus(ans, kStep, p)
	return ans

if __name__=="__main__":
	x = input('please input base a, factorial k, divisor p(divided by English comma):\n')
	base, k, mod = [int(i) for i in x.split(',')]
	start = time()
	answer = factorialMod(base, k, mod)
	stop = time()
	print('time consume: ' + str(stop - start) + 's')
	print('answer: ' + str(answer))
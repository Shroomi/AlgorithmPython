#case1 answer: 1
#case2 answer: 754458156
from operator import mul
from functools import reduce
from tqdm import tqdm

def chunks(l, n):
   """Yield successive n-sized chunks from l."""
   for i in range(0, len(l), n):
       yield l[i:i + n]

def modexp_rl(a, b, n):
   r = 1
   while 1:
       if b % 2 == 1:
           r = r * a % n
       b /= 2
       if b == 0:
           break
       a = a * a % n

   return r

def modular_pow(base, exponent, modulus):

   result = 1
   base = base % modulus
   while exponent > 0:
       if (exponent % 2 == 1):
          result = (result * base) % modulus
       exponent = exponent >> 1
       base = (base * base) % modulus
   return result

if __name__=="__main__":
	x = input('请输入底数a, 阶乘数k, 除数p(以逗号分隔):\n')
	base, k, mod = [int(i) for i in x.split(',')]
	ks = range(1,k+1)
	l = chunks(ks,1)
	prod = []
	for j in l: 
		prod.append(reduce(mul, j, 1))
	pbar = tqdm(total=len(prod))
	for i in prod:
		base = modular_pow(base,i,mod)
		pbar.update(1)
	print(base)
	pbar.close()
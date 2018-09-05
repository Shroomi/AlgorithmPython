def Exchange(array, i, j):
	temp = array[i]
	array[i] = array[j]
	array[j] = temp

def QuickSort(array, left, right):
	if left >= right:
		return
	flag = array[left]
	i = left
	j = right
	while i < j:
		while array[j] >= flag and i < j:
			j = j - 1
		while array[i] <= flag and i < j:
			i = i + 1
		Exchange(array, i, j)
	if(i == j and array[i] < flag):
		Exchange(array, left, i)
	mid = i
	QuickSort(array, left, mid-1)
	QuickSort(array, mid+1, right)


if __name__ == '__main__':
	array = [6,1,2,7,9,3,4,5,10,8]
	QuickSort(array, 0, len(array) - 1)
	print(array)
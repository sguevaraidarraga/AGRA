def upper(lst, v):
	l, h = 0, len(lst)-1
	while l <= h:
		m = (l+h)//2
		if lst[m] <= v:
			l = m+1
		else:
			h = m-1
	return l
def lower(lst, v):
	l, h = 0, len(lst)-1
	while l <= h:
		m = (l+h)//2
		if lst[m] < v:
			l = m+1
		else:
			h = m-1
	return l
def count(l, v):
	return upper(l, v) - lower(l, v)
def main():
	print(count([1, 2, 2, 2, 3, 4, 4, 5], 4))
main()
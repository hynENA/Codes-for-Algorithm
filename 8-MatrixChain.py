def MATRIX_CHAIN_ORDER(p):
	n = len(p)
	s = [[0 for j in range(n)] for i in range(n)]
	m = [[0 for j in range(n)] for i in range(n)]
	for l in range(2, n):			#l is the chain length
		for i in range(1, n-l+1):
			j = i + l - 1
			m[i][j] = 1e9
			for k in range(i, j):
				q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j]
				if q < m[i][j]:
					m[i][j] = q
					s[i][j] = k
	print()
	PRINT_OPTIMAL_PARENS(s, 1, n-1)
	print()
	
def PRINT_OPTIMAL_PARENS(s, i, j):
	if i == j:
		print('A', end = '')
		print(i, end = '')
	else:
		print('(', end = '')
		PRINT_OPTIMAL_PARENS(s, i, s[i][j])
		PRINT_OPTIMAL_PARENS(s, s[i][j]+1, j)
		print(')', end = '')
		
A = [10, 20,30,50]
MATRIX_CHAIN_ORDER(A)

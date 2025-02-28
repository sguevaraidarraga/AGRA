from collections import deque

def bfs(g, vis, i):
	ans = True
	q = deque()
	q.append(i)
	while len(q) > 0 and ans:
		v = q.popleft()
		for w in g[v]:
			if vis[w] == -1:
				vis[w] = 1 if vis[v] == 0 else 0
				q.append(w)
			if vis[v] == vis[w]:
				ans = False
	return ans 
def isBipartite(g):
	ans = True
	vis = [-1 for _ in range(len(g))]
	i = 0
	while i < len(g) and ans:
		if vis[i] == -1:
			vis[i] = 0
			ans = bfs(g, vis, i)
		i += 1
	return ans
def main():
	g = [[1, 2], [0, 4], [0, 3, 4], [2], [1, 2], [2, 6, 7], [0, 5], [0, 5]]
	g2 = [[1, 2], [0, 4], [0, 3, 4], [2, 4], [1, 2], [2, 6, 7], [0, 5], [0, 5]]
	print(isBipartite(g2))
main()
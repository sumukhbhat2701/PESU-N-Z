"""
You can create any other helper funtions.
Do not modify the given functions 
"""
from queue import PriorityQueue as PQ
from queue import LifoQueue as STACK

def A_star_Traversal(cost, heuristic, start_point, goals):
	"""
	Perform A* Traversal and find the optimal path 
	Arcumulative:
	cost: cost matrix (list of floats/int)
	heuristic: heuristics for A* (list of floats/int)
	start_point: Staring node (int)
	goals: Goal states (list of ints)
	Returns:
	path: path to goal state obtained from A*(list of ints)
	"""
	path = []
	cumulative_g = []
	parent = []
	pq = PQ()
	visited = []
	for i in range(len(cost)):
		visited.append(0)
		cumulative_g.append(-1)
		parent.append(-1)

	cumulative_g[start_point] = 0
	pq.put((heuristic[start_point], start_point))
	found = -1

	while(not pq.empty()):
		_, ptr = pq.get()
		if(ptr in goals):
			found = ptr
			break
		if(visited[ptr]):
			continue
		visited[ptr] = 1
		for n in range(1, len(cost)):
			if(cost[ptr][n]!=0 and not visited[n] and cost[ptr][n] != -1):
				parent[n] = ptr
				cumulative_g[n] = cumulative_g[ptr] + cost[ptr][n]
				f = cumulative_g[n] + heuristic[n]
				pq.put((f, n))

	if(found == -1):
		return path
	
	path.append(found)
	p = parent[found]
	
	while(p!=-1):
		path.append(p)
		p = parent[p]

	path.reverse()
	return path

def DFS_Traversal(cost, start_point, goals):
	"""
	Perform DFS Traversal and find the optimal path 
	cost: cost matrix (list of floats/int)
	start_point: Staring node (int)
	goals: Goal states (list of ints)
	Returns:
	path: path to goal state obtained from DFS(list of ints)
	"""
	path = []
	visited = []
	parent = []
	for i in range(len(cost)):
		visited.append(0)
		parent.append(-1)		
	
	stack = STACK()
	stack.put(start_point)
	found = -1

	while(not stack.empty()):
		ptr = stack.get()
		if(ptr in goals):
			found = ptr
			break
		if(visited[ptr]):
			continue
		visited[ptr] = 1
		for n in range(len(cost)-1, 0, -1):
			if(cost[ptr][n]!=0 and not visited[n] and cost[ptr][n] != -1):
				stack.put(n)
				parent[n] = ptr

	if(found == -1):
		return path
	
	path.append(found)
	p = parent[found]
	
	while(p!=-1):
		path.append(p)
		p = parent[p]

	path.reverse()

	return path

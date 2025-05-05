# Function to find the root of an element with path compression
def find(parent, x):
    if parent[x] != x:
        parent[x] = find(parent, parent[x])  # Path compression
    return parent[x]

# Function to union two subsets
def union(parent, rank, x, y):
    rootX = find(parent, x)
    rootY = find(parent, y)

    if rootX != rootY:
        # Union by rank
        if rank[rootX] > rank[rootY]:
            parent[rootY] = rootX
        elif rank[rootX] < rank[rootY]:
            parent[rootX] = rootY
        else:
            parent[rootY] = rootX
            rank[rootX] += 1

# Kruskal's algorithm
def kruskal(n, edges):
    parent = list(range(n))
    rank = [0] * n
    mst = []

    # Sort edges by weight
    edges.sort(key=lambda edge: edge[2])

    for u, v, w in edges:
        if find(parent, u) != find(parent, v):  # If u and v are not connected
            union(parent, rank, u, v)
            mst.append((u, v, w))

    return mst

# User input
n = int(input("Enter the number of vertices: "))  # Number of vertices
m = int(input("Enter the number of edges: "))  # Number of edges

edges = []
for _ in range(m):
    u, v, w = map(int, input("Enter edge (u v weight): ").split())
    edges.append((u, v, w))

# Call Kruskal's algorithm
mst = kruskal(n, edges)

# Output the MST
print("\nEdges in the Minimum Spanning Tree:")
for u, v, w in mst:
    print(f"{u} -- {v} == {w}")

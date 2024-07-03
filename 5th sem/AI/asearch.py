import heapq
graph_b = {
    'A': {'B': 22, 'D': 30},
    'B': {'A': 22, 'C': 20, 'D': 11},
    'C': {'B': 20},
    'D': {'A': 30, 'B': 11, 'E': 25, 'F': 10},
    'E': {'D': 25, 'F': 25, 'G': 40},
    'F': {'D': 10, 'E': 25, 'G': 12, 'H': 6},
    'G': {'E': 40, 'F': 12, 'H': 6},
    'H': {'F': 6, 'G': 6}
}
# Depth-First Search (DFS)
def heuristic(node, goal):
    # Example heuristic function (straight-line distance or any estimation)
    heuristics = {
        'A': 46, 'B': 39, 'C': 41, 'D': 29,
        'E': 38, 'F': 17, 'G': 6, 'H': 0
    }
    return heuristics[node]




def a_star_search(graph, start, goal):
    open_set = []
    heapq.heappush(open_set, (0, start))
    came_from = {}
    g_score = {node: float('inf') for node in graph}
    g_score[start] = 0
    f_score = {node: float('inf') for node in graph}
    f_score[start] = heuristic(start, goal)
   
    while open_set:
        _, current = heapq.heappop(open_set)
       
        if current == goal:
            path = []
            while current in came_from:
                path.append(current)
                current = came_from[current]
            path.append(start)
            path.reverse()
            return path
       
        for neighbor, weight in graph[current].items():
            tentative_g_score = g_score[current] + weight
            if tentative_g_score < g_score[neighbor]:
                came_from[neighbor] = current
                g_score[neighbor] = tentative_g_score
                f_score[neighbor] = g_score[neighbor] + heuristic(neighbor, goal)
                heapq.heappush(open_set, (f_score[neighbor], neighbor))
   
    return None




# Test A* on Graph b
print("\nA* Search for Graph b from 'A' to 'H':")
path = a_star_search(graph_b, 'A', 'H')
print("Path:", path)

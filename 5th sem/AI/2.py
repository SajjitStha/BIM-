# Graph b
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
print("Graph B:", graph_b)
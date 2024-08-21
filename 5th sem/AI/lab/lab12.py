from collections import deque

def bfs(a, b, target):
    # Map is used to check the existence of the state in our visited set
    visited = set()
    # Queue to hold the water in jugs and the path to that state
    queue = deque([((0, 0), [])])

    while queue:
        (jug1, jug2), path = queue.popleft()
        # Check if this state is already visited
        if (jug1, jug2) in visited:
            continue
        # If not, add the state to visited
        visited.add((jug1, jug2))
        # Check if we have reached the solution
        if jug1 == target or jug2 == target:
            return path + [(jug1, jug2)]

        # Possible moves list
        possible_moves = [
            (a, jug2), # Fill Jug1
            (jug1, b), # Fill Jug2
            (0, jug2), # Empty Jug1
            (jug1, 0), # Empty Jug2
            # Pour Jug1 to Jug2
            (jug1 - min(jug1, b - jug2), jug2 + min(jug1, b - jug2)),
            # Pour Jug2 to Jug1
            (jug1 + min(jug2, a - jug1), jug2 - min(jug2, a - jug1))
        ]
          # Enqueue all the valid moves
        for move in possible_moves:
            if move not in visited:
                queue.append((move, path + [(jug1, jug2)]))

    # If no solution is found
    return "No solution found"

# Example usage: Jug sizes 4 and 3, target 2 liters
result = bfs(4, 3, 2)
for step in result:
    print(f"Jug 1: {step[0]} liters, Jug 2: {step[1]} liters")
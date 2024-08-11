def tower_of_hanoi(n, from_rod, to_rod, aux_rod):
    """
    Args:
        n (int): The number of disks.
        from_rod (str): The rod where disks are initially located.
        to_rod (str): The rod where disks need to be moved.
        aux_rod (str): The auxiliary rod used for temporary storage.
    """
    if n == 1:
        print(f"Move disk 1 from {from_rod} to {to_rod}")
        return
    tower_of_hanoi(n-1, from_rod, aux_rod, to_rod)
    print(f"Move disk {n} from {from_rod} to {to_rod}")
    tower_of_hanoi(n-1, aux_rod, to_rod, from_rod)

def main():
    # Get user input
    n = int(input("Enter the number of disks: "))
    
    # Solve the Tower of Hanoi problem
    tower_of_hanoi(n, 'A', 'C', 'B')

if __name__ == "__main__":
    main()
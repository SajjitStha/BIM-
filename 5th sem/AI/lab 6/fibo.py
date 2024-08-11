def fibonacci(n):
    if n <= 0:
        print("Input should be a positive integer.")
    elif n == 1:
        return 0
    elif n == 2:
        return 1
    else:
        return fibonacci(n-1) + fibonacci(n-2)

def display_fibonacci(up_to):
    """
    Args:
        up_to (int): The number up to which to display the Fibonacci sequence.
    """
    for i in range(1, up_to + 1):
        print(f"Fibonacci of {i} is {fibonacci(i)}")

def main():
    # Get user input
    num = int(input("Enter a positive integer: "))
    
    # Display Fibonacci sequence up to the user-defined number
    display_fibonacci(num)

if __name__ == "__main__":
    main()
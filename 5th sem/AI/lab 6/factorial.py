def factorial(n):
    if n == 0:
        # Base case: factorial of 0 is 1
        return 1
    else:
        # Recursive case: n! = n * (n-1)!
        return n * factorial(n-1)

def main():
    # Get user input
    num = int(input("Enter a number: "))
    
    # Calculate factorial
    result = factorial(num)
    
    # Print result
    print(f"The factorial of {num} is {result}")

if __name__ == "__main__":
    main()
class Factorial:
    def __init__(self):
        self.result = 1

    def find_fact(self, n):
        self.result = 1
        if n < 0:
            return "Factorial is not defined for negative numbers."
        elif n == 0 or n == 1:
            return 1
        else:
            for i in range(1, n + 1):
                self.result *= i
            return self.result

# Example usage in main function
if __name__ == "__main__":
    factorial_obj = Factorial()
    num = int(input("Enter a number to find its factorial: "))
    factorial = factorial_obj.find_fact(num)
    print(f"The factorial of {num} is: {factorial}")

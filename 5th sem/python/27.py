class ArraySum:
    def __init__(self):
        self.sum = 0

    def calculate_sum(self, a):
        self.sum = 0
        for num in a:
            self.sum += num
        return self.sum

# Example usage in main function
if __name__ == "__main__":
    array_sum_obj = ArraySum()
    arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    total_sum = array_sum_obj.calculate_sum(arr)
    print(f"The sum of the array elements is: {total_sum}")
    
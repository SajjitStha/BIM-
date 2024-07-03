class Rectangle:
    def __init__(self, length, breadth):
        self.length = length
        self.breadth = breadth
        self.area = 0  # Initialize area to 0 initially

    def computeArea(self):
        # Method to compute area of the rectangle
        self.area = self.length * self.breadth

    def displayArea(self):
        # Method to display area of the rectangle
        print("Area of rectangle with length {} and breadth {} is: {}".format(self.length, self.breadth, self.area))


# Main program
if __name__ == "__main__":
    # Create two rectangle objects
    rectangle1 = Rectangle(5, 10)
    rectangle2 = Rectangle(3, 8)

    # Compute area for each rectangle
    rectangle1.computeArea()
    rectangle2.computeArea()

    # Display area of each rectangle
    rectangle1.displayArea()
    rectangle2.displayArea()

    # Determine and display area of larger rectangle
    if rectangle1.area > rectangle2.area:
        print("Rectangle 1 has a larger area.")
        rectangle1.displayArea()
    elif rectangle2.area > rectangle1.area:
        print("Rectangle 2 has a larger area.")
        rectangle2.displayArea()
    else:
        print("Both rectangles have the same area.")

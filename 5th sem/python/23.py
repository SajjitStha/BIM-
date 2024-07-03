class Rectangle:
    def __init__(self):
        self.length = 0
        self.breadth = 0
        self.area = 0

    def set(self):
        self.length = float(input("Enter length of rectangle: "))
        self.breadth = float(input("Enter breadth of rectangle: "))

    def calculate(self):
        self.area = self.length * self.breadth
        print("Area of rectangle:", self.area)

class Imain:
    @staticmethod
    def main():
        rect = Rectangle()
        rect.set()
        rect.calculate()

# Running the main function
Imain.main()

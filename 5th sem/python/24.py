import math

class Quadratic:
    def __init__(self):
        self.a = 0
        self.b = 0
        self.c = 0
        self.x1 = 0
        self.x2 = 0

    def input(self):
        self.a = float(input("Enter coefficient a: "))
        self.b = float(input("Enter coefficient b: "))
        self.c = float(input("Enter coefficient c: "))

    def calculate(self):
        discriminant = self.b**2 - 4 * self.a * self.c
        if discriminant >= 0:
            self.x1 = (-self.b + math.sqrt(discriminant)) / (2 * self.a)
            self.x2 = (-self.b - math.sqrt(discriminant)) / (2 * self.a)

    def display(self):
        print("Root 1:", self.x1)
        print("Root 2:", self.x2)

class Imain:
    @staticmethod
    def main():
        quad = Quadratic()
        quad.input()
        quad.calculate()
        quad.display()

# Running the main function
Imain.main()

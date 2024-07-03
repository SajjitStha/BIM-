def print_pyramid(rows):
    for i in range(rows):
        for j in range(i + 1):
            print('*', end='')
        for k in range(2 * (rows - i - 1)):
            print(' ', end='')
        for l in range(i + 1):
            print('*', end='')
        print()

print_pyramid(5)

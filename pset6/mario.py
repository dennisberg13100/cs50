from cs50 import get_int


def main():
    n = get_size()

    for i in range(n):
        for j in range(n-i-1):
            print(" ", end="")
        for k in range(i+1):
            print("#", end="")
        print("  ", end="")
        for l in range(i+1):
            print("#", end="")
        print()


def get_size():
    while True:
        n = get_int("Height: ")
        if n > 0 and n < 9:
            break
    return n


main()
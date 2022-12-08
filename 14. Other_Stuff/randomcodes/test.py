def fact(n):
    return 1 if n < 2 else n * fact(n-1)

def choose(n, k):
    return fact(n) // (fact(k) * fact(n-k))

def main():
    i, j = 0, 0
    sum = 0

    for i in range(0, 11):
        x = choose(10,i)
        y = choose(10-i,5)
        a = pow((1/6), i+5)
        b = pow((4/6), 10-i-5)

        out = x * y * a * b
        sum = sum + out
        print("i = ", i, "j = ", 5, "out = ", out)
        print("p = ", out/0.01302381020423715)
        print("#====================================================")
    print("sum = ", sum)
    


main()
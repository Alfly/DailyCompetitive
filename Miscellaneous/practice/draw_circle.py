def print_star_circle(r):
    for i in range(-r, r+1):
        print(" " * 10, end='')
        for j in range(-r, r+1):
            if i*i + j*j <= r*r:
                print("*", end="")
            else:
                print(" ", end="")
        print("")

print_star_circle(10)
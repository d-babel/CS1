# Mario by Drew Babel

#recieving user unput
while True:
    try:
        height = int(input("height: "))
        if 1 <= height <= 8:
            break
        else:
            print("height must be between 1 and 8")

#printing mario pyramid
for i in range(1, height + 1):
    spaces = ' ' * (height - i)
    hashes = '#' * i
    print(f)

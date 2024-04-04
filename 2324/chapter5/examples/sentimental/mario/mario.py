# Mario by Drew Babel

# recieving user unput
while True:
    try:
        height = input("height: ")
        # check for non-valid inputs
        if height.isdigit() and 1 <= int(height) <= 8:
            height = int(height)
            break
        else:
            print("height must be between 1 and 8")

# printing mario pyramid
for i in range(1, height + 1):
    spaces = ' ' * (height - i)
    hashes = '#' * i
    # f-string allows string literals "{}"
    print(f"{spaces}{hashes}  {hashes}")

# Cash by Drew Babel

while True:
    cash_input = input("change owed: ")
    try:
        cash = float(cash_input)
        if cash > 0:
            break
        else:
            #handle non pos input
            print("enter valid num")
    except ValueError:
        #handle non-numeric & empty input
        print("enter valid num")

#convert dollar to cent
coins = int(cash * 100)

# list of coin values
coin_values = [25, 10, 5, 1]
count = 0

for value in coin_values:
    while coins >= value:
        coins -= value
        count += 1

print(count)

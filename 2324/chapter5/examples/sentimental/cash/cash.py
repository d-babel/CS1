# Cash by Drew Babel

while True:
    # check if valid input
    cash = input("change owed: ")
    if cash.isdigit():
        cash = float(cash)
        if cash > 0:
            break
    print("enter a valid num")

coins = int(cash * 100)

# list of coin values
coin_values = [25, 10, 5, 1]
count = 0

for value in coin_values:
    while coins >= value:
        coins -= value
        count += 1

print(count)

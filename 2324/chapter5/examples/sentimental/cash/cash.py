# Cash by Drew Babel

while True:
    cash = input("change owed: ")
    if cash.isdigit() and cash > 0:
        cash = float(cash)
        break
    else:
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

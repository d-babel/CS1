# Cash by Drew Babel

while True:
    cash = float(input("change owed: "))
    if cash > 0:
        break

coins = int(cash * 100)

# list of coin values
coin_values = [25, 10, 5, 1]
count = 0

for value in coin_values:
    while coins >= value:
        coins -= value
        count += 1

print(count)

# Read about Python dictionaries here: https://www.w3schools.com/python/python_dictionaries.asp
# car1 is a dict. It contains keys and values. "make" is a key. "Toyota" is a value.
car1 = {"make": "Toyota", "model": "Corolla", "year": "2015", "color": "green"}

# This returns the value associated with the key "make"
str = car1["make"]
print(str)

# print out "I have a green 2015 Toyota Corolla" where the values are filled in from the dict.
print(f"I have a {car1['color']} {car1['year']} {car1['make']} {car1['model']}")

# create at least three more cars with keys for make, model, year, and color.
car2 = {"make": "Toyota", "model": "Civic", "year": "2017", "color": "blue"}
car3 = {"make": "Ford", "model": "Mustang", "year": "2018", "color": "red"}
car4 = {"make": "Chevrolet", "model": "Camaro", "year": "2021", "color": "black"}

# create a list called "garage" that contains all of these cars.
garage = [car1, car2, car3, car4]

# print the contents of your garage.
print(garage)

# You got a brand new car! You get to choose the make, model, year, and color.
# Now add it to the garage. Bonus if you can create the car and add it
# in a single line of code.
garage.append({"make": "Tesla", "model": "Model 3", "year": "2022", "color": "white"})

# Iterate through the list and print out "I have a [color] [make] [model]" for each car in the garage.
for car in garage:
    print(f"I have a {car['color']} {car['make']} {car['model']}")

# Iterate through the list and print out every car that is newer than 2020.
for car in garage:
    if int(car["year"]) > 2020:
        print(f"{car['make']} {car['model']} is newer than 2020")


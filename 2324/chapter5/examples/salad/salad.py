# Salad by Drew Babel

# Let's create a Salad!
# Read this: https://www.w3schools.com/python/python_ref_list.asp

# Create a salad with five different ingredients.
# One of them must be a carrot.
salad = ["carrot", "lettuce", "tomato", "chicken", "ranch"]

# Print the ingredients in your salad.
for ingredient in salad:
    print(ingredient)

# Add three new ingredients to your salad. One of them must be a carrot.
salad.extend(["spinach", "cucumbers", "peppers"])

# Print the ingredients in your salad.
for ingredient in salad:
    print(ingredient)

# Now, use a Python list method to remove ALL carrots from your salad. #nocarrots

salad = [ingredient for ingredient in salad if ingredient != "carrot"]

for ingredient in salad:
     print(ingredient)

# Create a separate function that removes carrots from a salad.

def remove_carrots(salad):
    return [ingredient for ingredient in salad if ingredient != "carrot"]

# Create a function that removes any given ingredient from a salad.

def remove_ingredient(salad):
    ingredient = input("What ingredient do you want to remove from your salad? ")
    return [item for item in salad if item != ingredient]

# Create a function that builds a new salad by doing the following:
#   Prompt the user for the number of ingredients
#   Prompt the user for each ingredient and edd it to salad
def build_salad(salad):
    ingredients_amount = input("How many ingredients would you like?")
    

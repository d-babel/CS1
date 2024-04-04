# Cash by Drew Babel

def get_positive_float(prompt):
    while True:
        user_input = input(prompt)
        try:
            value = float(user_input)
            if value > 0:
                return value
            else:
                

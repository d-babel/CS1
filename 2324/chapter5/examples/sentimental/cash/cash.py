def main():
    while True:
        try:
            change_owed = float(input("change owed: "))
            if change_owed >= 0:
                break
            

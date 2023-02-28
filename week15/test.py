import datetime

def getDate():
    return datetime.datetime.now().strftime("%Y-%m-%d")

def getTime():
    return datetime.datetime.now().strftime("%H:%M:%S")

def getDateTime():
    return datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")

def main():
    print("Today's date is:", getDate())
    print("The current time is:", getTime())
    print("The current date and time is:", getDateTime())

if __name__ == "__main__":
    main()
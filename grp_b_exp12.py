def binary_search(names, tels, to_find):
    low, high = 0, len(names) - 1
    while low <= high: 
        mid = (low + high) // 2
        if names[mid] == to_find:
            print(f"Phone number of {to_find} is {tels[mid]}")
            return True
        elif names[mid] > to_find: 
            high = mid - 1
        else:
            low = mid + 1
    print("Name not found")
    return False


def recursive_binary(names, tels, low, high, to_find): 
    if low > high:
        print("Name not found")
        return False
    mid = (low + high) // 2
    if names[mid] == to_find:
        print(f"Phone number of {to_find} is {tels[mid]}")
        return True
    elif names[mid] > to_find:
        return recursive_binary(names, tels, low, mid - 1, to_find)
    else:
        return recursive_binary(names, tels, mid + 1, high, to_find)


def fib_search(names, tels, to_find):
    fib2, fib1 = 0, 1
    fibM = fib2 + fib1
    
    while fibM < len(names):
        fib2, fib1 = fib1, fibM
        fibM = fib2 + fib1
    
    offset = -1
    while fibM > 1:
        i = min(offset + fib2, len(names) - 1)
        if names[i] < to_find:
            fibM, fib1, fib2 = fib1, fib2, fibM - fib1
            offset = i
        elif names[i] > to_find:
            fibM, fib1, fib2 = fib2, fib1 - fib2, fibM - fib1
        else:
            print(f"Phone number of {to_find} is {tels[i]}")
            return True
    print("Name not found")
    return False


# Input the number of friends
n = int(input("Enter number of friends: "))
names = []
tels = []

# Collecting names and phone numbers
for _ in range(n):
    name = input("Enter friend's name: ")
    tel = input("Enter friend's mobile number: ")
    names.append(name)
    tels.append(tel)

# Sort names and corresponding telephone numbers
names.sort()
tels.sort()

# Temporary list to hold the sorted names and corresponding numbers
sorted_names = []
sorted_tels = []

for name in names:
    index = names.index(name)  
    sorted_names.append(name)
    sorted_tels.append(tels[index])

# Replace original lists with sorted lists
names = sorted_names
tels = sorted_tels

to_find = input("Enter the name of the friend to search: ")

while True:
    print("\nChoose a search method:")
    print("1. Binary Search")
    print("2. Recursive Binary Search")
    print("3. Fibonacci Search")
    print("4. Exit")
    
    ch = int(input("Enter your choice: "))
    
    if ch == 1:
        found = binary_search(names, tels, to_find)
    elif ch == 2:
        found = recursive_binary(names, tels, 0, len(names) - 1, to_find)
    elif ch == 3:
        found = fib_search(names, tels, to_find)
    elif ch == 4:
        print("Thank you for using the program!")
        break
    else:
        print("Invalid choice, please try again.")
        continue
    
    if not found:
        new_tel = input(f"{to_find} not found. Enter mobile number to add: ")
        names.append(to_find)
        tels.append(new_tel)
        
        names.sort()
        tels.sort()

        # Create a temporary list to hold the sorted names and corresponding numbers
        sorted_names = []
        sorted_tels = []

        for name in names:
            index = names.index(name)
            sorted_names.append(name)
            sorted_tels.append(tels[index])

        names = sorted_names
        tels = sorted_tels
        
        print(f"{to_find} added to the phonebook.")

# Final output
print("Updated list of friends:")
for i in range(len(names)):
    print(f"{names[i]}: {tels[i]}")

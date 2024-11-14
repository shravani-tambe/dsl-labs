# Linear Search
def linear(key, n, lst): 
    for i in range(n): 
        if key == lst[i]:
            return True
    return False

#Binary Search
def binary(key, n, lst): 
    s = 0
    e = n - 1
    while s <= e: 
        mid = (s + e) // 2
        if lst[mid] == key: 
            return True
        elif key < lst[mid]: 
            e = mid - 1
        else: 
            s = mid + 1 
    return False

# Sentinel Search
def sentinal(key, n, lst): 
    last = lst[n - 1]
    lst[n - 1] = key
    i = 0  
    while lst[i] != key:
        i += 1
    lst[n - 1] = last  
    return i < n - 1 or lst[n - 1] == key

#Fibonacci Search
def fib(key, n, lst): 
    if n == 0: 
        return False 
    fib1, fib2 = 0, 1
    fib3 = fib1 + fib2 
    
    while fib3 < n: 
        fib1, fib2 = fib2, fib3 
        fib3 = fib1 + fib2 
        
    offset = -1
    while fib3 > 1: 
        i = min(offset + fib2, n - 1) 
        
        if lst[i] < key: 
            fib3 = fib2 
            fib2 = fib1 
            fib1 = fib3 - fib2 
            offset = i 
        elif lst[i] > key: 
            fib3 = fib1 
            fib2 = fib2 - fib1 
            fib1 = fib3 - fib2
        else: 
            return True
    if fib2 == 1 and lst[offset + 1] == key:  
        return True
    return False

def give_ans(ans): 
    if ans:
        print("The student attended the program")
    else: 
        print("The student did not attend the program")

n = int(input("Enter number of students who attended the program: "))
lst = []
for i in range(n): 
    roll = int(input("Enter roll number of student: ")) 
    lst.append(roll)

key = int(input("Enter roll number of student to be found: "))

print("Choose searching algorithm to be used: \n 1. Linear Search \n 2. Binary Search \n 3. Fibonacci Search \n 4. Sentinel Search \n 5. Exit")
ch = int(input("Enter choice: "))
while ch != 5: 
    if ch < 1 or ch > 5: 
        print("Invalid choice")
    elif ch == 1: 
        ans = linear(key, n, lst)
        give_ans(ans)
    elif ch == 2:  # Binary search requires sorted list
        lst.sort()
        ans = binary(key, n, lst)
        give_ans(ans)
    elif ch == 3:  # Fibonacci search requires sorted list
        lst.sort()
        ans = fib(key, n, lst)
        give_ans(ans)
    elif ch == 4:  
        ans = sentinal(key, n, lst)
        give_ans(ans)
    ch = int(input("Enter choice: "))

if ch == 5: 
    print("Thank you for using the program.")

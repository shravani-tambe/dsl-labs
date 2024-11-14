tot = int(input("Enter total number of students in the academy: "))

cricket = []
badminton = []
football = []

# Function to find students who play both cricket and badminton
def opt1(cricket, badminton): 
    intersect = []
    for i in cricket: 
        if i in badminton and i not in intersect:
            intersect.append(i)
    return intersect

# Function to find students who play either cricket or badminton but not both
def opt2(cricket, badminton):
    result = []
    for i in cricket:
        if i not in badminton and i not in result:
            result.append(i)
    for i in badminton:
        if i not in cricket and i not in result:
            result.append(i)
    return result

# Function to find number of students who play neither cricket nor badminton
def opt3(cricket, badminton, tot): 
    all_cricket_badminton = cricket + badminton
    unique_cricket_badminton = []
    
    # Remove duplicates
    for i in all_cricket_badminton:
        if i not in unique_cricket_badminton:
            unique_cricket_badminton.append(i)
    
    # Calculate students who play neither cricket nor badminton
    neither_count = tot - len(unique_cricket_badminton)
    return neither_count

# Function to find students who play cricket and football but not badminton
def opt4(cricket, badminton, football): 
    result = []
    for i in cricket:
        if i in football and i not in badminton and i not in result:
            result.append(i)
    return len(result)

a = int(input("Enter number of students who play cricket: "))
b = int(input("Enter number of students who play badminton: "))
c = int(input("Enter number of students who play football: "))

print("Enter roll numbers of students playing cricket:")
for i in range(a): 
    val = int(input())
    if val not in cricket:  # Avoid duplicates
        cricket.append(val)

print("Enter roll numbers of students playing badminton:")
for i in range(b): 
    val = int(input())
    if val not in badminton:  # Avoid duplicates
        badminton.append(val)

print("Enter roll numbers of students playing football:")
for i in range(c): 
    val = int(input())
    if val not in football:  # Avoid duplicates
        football.append(val)

print('''Select operation to perform on this set of students: 
      1. Find list of students who play both cricket and badminton
      2. Find list of students who play either cricket or badminton but not both
      3. Find number of students who play neither cricket nor badminton
      4. Find number of students who play cricket and football but not badminton.
      5. Exit''')

ch = int(input("Enter your choice: "))
while ch != 5: 
    if ch < 1 or ch > 5: 
        print("Invalid choice")
    elif ch == 1: 
        print("The students who play both cricket and badminton are:", opt1(cricket, badminton))
    elif ch == 2: 
        print("The students who play either cricket or badminton but not both are:", opt2(cricket, badminton))  
    elif ch == 3:
        print("The number of students who play neither cricket nor badminton is:", opt3(cricket, badminton, tot))
    elif ch == 4: 
        print("The number of students who play cricket and football but not badminton is:", opt4(cricket, badminton, football))
    ch = int(input("Enter your choice: "))

if ch == 5: 
    print("Thank you for using the program.")

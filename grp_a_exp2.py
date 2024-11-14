lst = []
absent = []

# Input total students and their marks
n = int(input("Enter number of students in the class: "))
for i in range(n):  
    marks = input(f"Enter marks of student {i + 1}: ")
    if marks.lower() == "absent":
        absent.append(marks)
    elif marks.isdigit() and 0 <= int(marks) <= 100:
        lst.append(int(marks))
    else:
        print("Invalid input, please enter a number between 0 and 100 or 'absent'.")

# Function to calculate the average score of the class
def calc_avg(s):
    if len(s) == 0:
        return 0 
    total_sum = sum(s)  
    average = total_sum / len(s)  
    return average

# Function to find the highest and lowest scores
def highlow(s):
    if len(s) > 0:
        high = max(s)
        low = min(s)
        print("Highest score in class:", high)
        print("Lowest score in class:", low)
    else:
        print("No values to check")

# Function to count students who were absent
def check_absent(absent):
    return len(absent)

# Function to display the mark with the highest frequency
def calc_freq(s):
    if len(s) == 0:
        print("No marks available to check frequency.")
        return
    freq = 0  
    ans = None  
    for i in s: 
        count = s.count(i)
        if count > freq: 
            freq = count
            ans = i
    
    print(f"The marks {ans} appeared {freq} times, which is the highest frequency.")


print("Choose operation to be performed \n 1. Find average score of the class \n 2. Find the highest and lowest scores of the class \n 3. Count of students who were absent for the test \n 4. Display marks with highest frequency \n 5. Exit")

while True: 
    ch = int(input("Enter choice: "))
    if ch == 1: 
        print("Average of all students in the class:", calc_avg(lst))
    elif ch == 2: 
        highlow(lst)
    elif ch == 3: 
        print("The number of students absent are:", check_absent(absent))
    elif ch == 4: 
        calc_freq(lst)
    elif ch == 5: 
        print("Thank you for using the program.")
        break
    else: 
        print("Invalid choice, please enter a valid option.")

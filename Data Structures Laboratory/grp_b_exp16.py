def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    
    pivot = arr[0]  # First element as the pivot
    left = []   # Elements less than pivot
    middle = [] # Elements equal to pivot
    right = []  # Elements greater than pivot
    
    #Partition
    for item in arr:
        if item < pivot:
            left.append(item)
        elif item == pivot:
            middle.append(item)
        else:
            right.append(item)

    return quick_sort(left) + middle + quick_sort(right)

n = int(input("Enter the number of students: "))
percentages = []  

for i in range(n):
    score = float(input(f"Enter percentage of student {i + 1}: "))  
    percentages.append(score)

sorted_percentages = quick_sort(percentages)

print("\nTop five scores in ascending order:")
if len(sorted_percentages) >= 5:
    top_five_scores = sorted_percentages[-5:]  # Displaying the last five scores i.e. top scores
else:
    top_five_scores = sorted_percentages  
    
for score in top_five_scores:
    print(score)

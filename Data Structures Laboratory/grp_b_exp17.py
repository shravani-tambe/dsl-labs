def bucket_sort(arr):
    bucket_count = 10  # Number of buckets
    buckets = []  
    
    # Initialize empty buckets
    for _ in range(bucket_count):
        buckets.append([])

    for number in arr:
        index = int(number // 10) 
        if index >= bucket_count:  
            index = bucket_count - 1
        buckets[index].append(number)  

    # Sort each bucket and combine
    sorted_percentages = []  
    for bucket in buckets:
        sorted_bucket = sorted(bucket) 
        for num in sorted_bucket: 
            sorted_percentages.append(num)

    return sorted_percentages

# Input: Number of students
num_students = int(input("Enter the number of students: "))
percentages = []  

for i in range(num_students):
    score = float(input(f"Enter percentage of student {i + 1}: "))  
    percentages.append(score)

sorted_percentages = bucket_sort(percentages)

# Displaying the top five scores
print("\nTop five scores in ascending order:")
if len(sorted_percentages) >= 5:
    top_five_scores = sorted_percentages[-5:]  
else:
    top_five_scores = sorted_percentages  

for score in top_five_scores:
    print(score)

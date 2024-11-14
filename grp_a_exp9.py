# Function to add two matrices
def add_matrices(matrix1, matrix2, n, m):
    result = []
    for i in range(n):
        row = []
        for j in range(m):
            row.append(matrix1[i][j] + matrix2[i][j])
        result.append(row)
    print("Addition of both matrices:")
    for row in result:
        print(row)

# Function to subtract two matrices
def subtract_matrices(matrix1, matrix2, n, m):
    result = []
    for i in range(n):
        row = []
        for j in range(m):
            row.append(matrix1[i][j] - matrix2[i][j])
        result.append(row)
    print("Subtraction of both matrices:")
    for row in result:
        print(row)

# Function to multiply two matrices
def multiply_matrices(matrix1, matrix2, n, m):
    if len(matrix1[0]) != len(matrix2):
        print("Matrix should have columns of matrix1 = rows of matrix2")
        return
    result = []
    for i in range(n):
        row = []
        for j in range(len(matrix2[0])):
            sum = 0
            for k in range(m):
                sum += matrix1[i][k] * matrix2[k][j]
            row.append(sum)
        result.append(row)
    print("Multiplication of both matrices:")
    for row in result:
        print(row)

# Function to transpose a matrix
def transpose_matrix(matrix, n, m):
    result = []
    for j in range(m):  
        row = []
        for i in range(n): 
            row.append(matrix[i][j])
        result.append(row)
    print("Transpose of matrix 1:")
    for row in result:
        print(row)

matrix1 = []
n = int(input("Enter number of rows in both matrices: "))
m = int(input("Enter number of columns in both matrices: "))

print("Enter values to add in matrix 1:")
for i in range(n):
    row = []
    for j in range(m):
        a = int(input())
        row.append(a)
    matrix1.append(row)

print("Matrix 1:", matrix1)

matrix2 = []
print("Enter values to add in matrix 2:")
for i in range(n):
    row = []
    for j in range(m):
        b = int(input())
        row.append(b)
    matrix2.append(row)

print("Matrix 2:", matrix2)


print("Choose an operation for both matrices: \n 1. Addition \n 2. Subtraction \n 3. Multiplication \n 4. Transpose")
ch = int(input("Enter choice: "))


if ch == 1:
    add_matrices(matrix1, matrix2, n, m)
elif ch == 2:
    subtract_matrices(matrix1, matrix2, n, m)
elif ch == 3:
    multiply_matrices(matrix1, matrix2, n, m)
elif ch == 4:
    transpose_matrix(matrix1, n, m)
else:
    print("Invalid choice.")

# Example for a 2D array of integers
rows = int(input("Enter the number of rows: "))
matrix = []

# Loop to read each row as space-separated integers
for _ in range(rows):
    row = list(map(int, input("Enter space-separated integers for row: ").split()))
    matrix.append(row)

# Print the entire matrix
print("Matrix:")
print(matrix)
 
# Print each element individually in a formatted way
print("Matrix elements individually:")
for arr in matrix:
    for ele in arr:
        print(ele, end=" ")  # Print each element followed by a space
    print()  # Newline after each row

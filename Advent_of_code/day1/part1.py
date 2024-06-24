def search(filepath):
    with open(filepath, "r") as file:
        lines = file.readlines()

    nums = ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']
    ans = 0
    
    for line in lines:
        each = line.strip()
        arr = [char for char in each if char.isdigit() and char in nums]
        
        if len(arr) > 0:
            concatenated = arr[0] + arr[-1]
            ans += int(concatenated)

    return ans

# Example usage
filepath = "callibaration.txt"  # Make sure the file name matches exactly
cal = search(filepath)
print(cal)

                
def parse(array):
    ans = []
    nums_in_words = ['one', 'two', 'three', 'four', 'five', 'six', 'seven', 'eight', 'nine']
    for char in array:
        if char.isdigit():
            ans.append(char)
        else:
            

def window(line):
    arr = []
    for step in line:
        for character in range(step,step+5):
            arr.append(character)
            found = parse(arr)
            
            if found is not None:
                return found
            else:
                return None

filepath = "callibaration.txt"  # Make sure the file name matches exactly
cal = parse(filepath)
print(cal)
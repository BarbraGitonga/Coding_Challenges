import re
from typing import List, Tuple
from random import randint

def split_puzzle(filename: str) -> Tuple[List, List]:
    with open(filename, "r") as file:
        list_1 = []
        list_2 = []
        
        for line in file:
            clean_line = re.sub("\n", "", line)
            one_list = clean_line.split(sep="   ")
            list_1.append(one_list[0])
            list_2.append(one_list[1])
            
    file.close()
    return (list_1, list_2)

def quicksort_lists_ascending(array: List) -> List:
    # If the input array contains fewer than two elements,
    # then return it as the result of the function
    if len(array) < 2:
        return array
    
    low, same, high = [], [], []
    
    pivot = array[randint(0, len(array)-1)]
    
    for item in array:
        # Elements that are smaller than the `pivot` go to
        # the `low` list. Elements that are larger than
        # `pivot` go to the `high` list. Elements that are
        # equal to `pivot` go to the `same` list.
        if item < pivot:
            low.append(item)
        elif item == pivot:
            same.append(item)
        elif item > pivot:
            high.append(item)
    
    return quicksort_lists_ascending(low) + same + quicksort_lists_ascending(high)

def sum_differences(list1: List[str], list2: List[str]) -> int:
    i = 0
    sum = 0
    min_length = min(len(list1), len(list2), 1000)  
    for i in range(min_length):
        sum += abs(int(list1[i]) - int(list2[i]))
        i+=1
    return sum

filename = "location.txt"

list_1, list_2 = split_puzzle(filename=filename)

sorted_1 = quicksort_lists_ascending(list_1)
sorted_2 = quicksort_lists_ascending(list_2)

difference = sum_differences(sorted_1, sorted_2)

print(f"Difference: {difference}")
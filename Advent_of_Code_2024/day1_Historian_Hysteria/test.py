from typing import Tuple, List
import re
def split_puzzle(filename: str) -> Tuple[List, List]:

    with open(filename, "r") as file:
        list_1 = []
        list_2 = []
        
        for line in file:
            clean_line = re.sub("\n", "", line)
            one_list = clean_line.split(sep="   ")
            print(f"one list: {one_list}")
            
            for i, index in enumerate(one_list):
                if (i + 1) % 2 == 0: 
                    list_1.append(index)
                list_2.append(index)
        print(one_list)
    return (list_1, list_2)

filename = "location.txt"
list_1, list_2 = split_puzzle(filename=filename)

print (f" lists: list 1 {list_1} \n, list 2{list_2}")
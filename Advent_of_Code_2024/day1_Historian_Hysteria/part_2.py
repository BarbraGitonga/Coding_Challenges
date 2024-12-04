import re
from typing import Tuple, List
def split_puzzle(filename: str) -> Tuple[List, List]:
    with open(filename, "r") as file:
        list_1 = []
        list_2 = []
        
        for line in file:
            clean_line = re.sub("\n", "", line)
            one_list = clean_line.split(sep="   ")
            list_1.append(int(one_list[0]))
            list_2.append(int(one_list[1]))
            
    file.close()
    return (list_1, list_2)

def calculate_similarity_score(left_list: List[int], right_list: List[int]) -> int:
    i = 0
    j = 0
    sum = 0
    for i in range(len(left_list)):
        for j in range(len(right_list)):
            mul = 0
            if left_list[i] == right_list[j]:
                mul +=1
            sum += left_list[i] * mul
    
    return sum

filename = "location.txt"
left_list, right_list = split_puzzle(filename=filename)
score = calculate_similarity_score(left_list=left_list, right_list=right_list)
print(score)

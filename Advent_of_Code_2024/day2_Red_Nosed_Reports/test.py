with open("test.txt", "r") as file:
    i=0
    for i, line in enumerate(file, 1):
        try:
            levels = list(map(int, line.split()))
        except ValueError:
            print(f"Line {i}: Invalid data - {line.strip()}")
            continue

        length = len(levels)
        print(f"1. {levels[:i]}")
        print(f"2. {levels[i+1:]}")
        mod = levels[:i] + levels[i+1:]
        print(f"mod: {mod}")
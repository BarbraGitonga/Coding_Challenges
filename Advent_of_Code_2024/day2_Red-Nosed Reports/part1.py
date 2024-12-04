def is_ascending(levels: list[int]) -> bool:
    for i in range(len(levels) - 1):
        difference = levels[i + 1] - levels[i]
        if not (1 <= difference <= 3):
            return False
    return True

def is_descending(levels: list[int]) -> bool:
    for i in range(len(levels) - 1):
        difference = levels[i + 1] - levels[i]
        if not (-3 <= difference <= -1):
            return False
    return True

def safe_calculator(filename: str) -> int:
    with open(filename, "r") as file:
        safe_count = 0
        for i, line in enumerate(file, 1):
            try:
                levels = list(map(int, line.split()))
            except ValueError:
                print(f"Line {i}: Invalid data - {line.strip()}")
                continue

            # Check safety
            if is_ascending(levels) or is_descending(levels):
                print(f"Line {i}: Safe")
                safe_count += 1
            else:
                print(f"Line {i}: Unsafe")

    return safe_count

# Example usage
filename = "test.txt"
safety = safe_calculator(filename=filename)
print(f"Total safe reports: {safety}")

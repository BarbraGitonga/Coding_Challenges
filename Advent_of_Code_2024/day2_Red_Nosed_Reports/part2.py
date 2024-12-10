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
        
def is_safe_with_dampener(levels: list[int]) -> bool:
    """Check if a report is safe with the Dampener logic."""
    # Check if already safe
    if is_ascending(levels) or is_descending(levels):
        return True

    # Try removing each level and check if it becomes safe
    for i in range(len(levels)):
        modified_levels = levels[:i] + levels[i+1:]  # Remove the i-th level
        print(modified_levels)
        if is_ascending(modified_levels) or is_descending(modified_levels):
            return True

    return False

def safe_calculator_with_dampener(filename: str) -> int:
    """Calculate the total number of safe reports in the file with Dampener logic."""
    with open(filename, "r") as file:
        safe_count = 0
        for i, line in enumerate(file, 1):
            try:
                levels = list(map(int, line.split()))
            except ValueError:
                print(f"Line {i}: Invalid data - {line.strip()}")
                continue

            # Check safety with Dampener logic
            if is_safe_with_dampener(levels):
                print(f"Line {i}: Safe")
                safe_count += 1
            else:
                print(f"Line {i}: Unsafe")

    return safe_count

filename = "reports.txt"
safety = safe_calculator_with_dampener(filename=filename)
print(f"Total safe reports: {safety}")
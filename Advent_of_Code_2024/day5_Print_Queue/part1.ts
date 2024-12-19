const splitInstructions = (line: string, leftArr: Array<string>, rightArr: Array<string>): [Array<string>, Array<string>] => {
    const lineArr = line.split("|");
    leftArr.push(lineArr[0]);
    rightArr.push(lineArr[1]);

    return [leftArr, rightArr];
};

const compareMid = (line: string, leftArr: Array<string>, rightArr: Array<string>): number => {
    const updates = line.split(",").map(x => x.trim()).filter(x => x !== ""); // Ensure clean updates
    if (updates.length === 0) {
        console.error("Empty updates array for line:", line);
        return 0; // Default value for empty updates
    }

    for (let i = 0; i < updates.length; i++) {
        for (let j = 0; j < rightArr.length; j++) {
            if (rightArr[j] === updates[i]) { // Check if the number is in the right array
                const priority = leftArr[j]; // Number that takes priority
                for (let k = i; k < updates.length; k++) { // Check if priority digit appears later
                    if (updates[k] === priority) {
                        return 0; // Conflict found, return 0
                    }
                }
            }
        }
    }

    const mid = Math.floor(updates.length / 2);
    const midValue = updates[mid];
    const midNumber = Number(midValue); // Safely convert to number

    if (isNaN(midNumber)) {
        return 0; // Default value for invalid numbers
    }

    return midNumber;
};


async function processFile(filename: string) {
    var sum = 0;
    try {
        // Read the file content
        const fileContent = await Deno.readTextFile(filename);

        // Normalize line endings to ensure consistent splitting
        const normalizedContent = fileContent.replace(/\r\n/g, "\n");

        // Split the content into two sections at the first empty line
        const sections = normalizedContent.split("\n\n");
        if (sections.length < 2) {
            throw new Error("File format incorrect. Ensure there's an empty line separating instructions and updates.");
        }

        const [instructionsSection, updatesSection] = sections;

        // Split instructions into lines and then into left and right arrays
        const instructions = instructionsSection.split("\n").filter(line => line.trim() !== "");
        const leftArray: Array<string> = [];
        const rightArray: Array<string> = [];
        for (const instruction of instructions) {
            const parts = instruction.split("|");
            if (parts.length !== 2) {
                throw new Error(`Malformed instruction line: "${instruction}"`);
            }
            leftArray.push(parts[0].trim());
            rightArray.push(parts[1].trim());
        }

        // Split updates into an array of update strings
        const updates = updatesSection.split("\n").map(line => line.trim()).filter(line => line !== "");

        for (const update of updates){
            sum += compareMid(update, leftArray, rightArray)
        }
        console.log("Sum of mid: ", sum);
    } catch (error) {
        console.error("Error processing file:", error.message);
    }
}

// Specify the file to read
const filename = "print.txt"; // Replace with the actual file path
processFile(filename);

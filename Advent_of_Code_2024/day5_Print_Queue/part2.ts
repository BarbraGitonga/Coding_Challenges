const splitInstructions = (line: string, leftArr: Array<string>, rightArr: Array<string>): [Array<string>, Array<string>] => {
    const lineArr = line.split("|");
    leftArr.push(lineArr[0]);
    rightArr.push(lineArr[1]);

    return [leftArr, rightArr];
};

const compareMid = (line: string, leftArr: Array<string>, rightArr: Array<string>): number => {
    const updates = line.split(",").map(x => x.trim()).filter(x => x !== ""); // Clean updates
    if (updates.length === 0) {
        console.error("Empty updates array for line:", line);
        return 0;
    }

    // Check if the update is in the wrong order
    let isWrongOrder = false;

    for (let i = 0; i < updates.length; i++) {
        for (let j = i + 1; j < updates.length; j++) {
            const indexI = rightArr.indexOf(updates[i]);
            const indexJ = rightArr.indexOf(updates[j]);

            if (indexI !== -1 && indexJ !== -1 && leftArr[indexI] === updates[j]) {
                isWrongOrder = true;
            }
        }
    }

    if (!isWrongOrder) {
        return 0; // Skip correctly-ordered updates
    }

    // Rearrange the update based on the page ordering rules
    const priorityMap = new Map<string, string>();
    for (let i = 0; i < rightArr.length; i++) {
        priorityMap.set(rightArr[i], leftArr[i]);
    }

    updates.sort((a, b) => {
        const priorityA = priorityMap.get(a) || a;
        const priorityB = priorityMap.get(b) || b;
        return priorityB.localeCompare(priorityA); // Higher priority comes first
    });

    // Calculate the middle digit
    const mid = Math.floor(updates.length / 2);
    const midValue = updates[mid];
    const midNumber = Number(midValue);

    if (isNaN(midNumber)) {
        console.error(`Invalid middle value: "${midValue}" in updates:`, updates);
        return 0;
    }

    return midNumber;
};

async function processFile(filename: string) {
    let sum = 0;
    try {
        const fileContent = await Deno.readTextFile(filename);
        const normalizedContent = fileContent.replace(/\r\n/g, "\n");
        const sections = normalizedContent.split("\n\n");
        if (sections.length < 2) {
            throw new Error("File format incorrect. Ensure there's an empty line separating instructions and updates.");
        }

        const [instructionsSection, updatesSection] = sections;
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

        const updates = updatesSection.split("\n").map(line => line.trim()).filter(line => line !== "");
        console.log("Left Array:", leftArray);
        console.log("Right Array:", rightArray);
        console.log("Updates:", updates);

        for (const update of updates) {
            sum += compareMid(update, leftArray, rightArray);
        }

        console.log("Sum of middle digits of rearranged updates:", sum);
    } catch (error) {
        console.error("Error processing file:", error.message);
    }
}

// Specify the file to read
const filename = "test.txt"; // Replace with the actual file path
processFile(filename);

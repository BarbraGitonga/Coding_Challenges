const masSearch = (file: Array<Array<string>>, i: number, j: number, row: number, col: number): number => {
    const mas = RegExp(/MAS|SAM/);
    let sum = 0;
    const index = file[i][j];
    const directions = [
        [1, 1],   // Diagonal Down-Right
        [-1, -1], // Diagonal Up-Left
        [1, -1],  // Diagonal Down-Left
        [-1, 1]   // Diagonal Up-Right
    ];

    if (index === "A") {
        // Check diagonals for "MAS" pattern
        const topLeft = file[i - 1]?.[j - 1] || "";
        const topRight = file[i - 1]?.[j + 1] || "";
        const bottomLeft = file[i + 1]?.[j - 1] || "";
        const bottomRight = file[i + 1]?.[j + 1] || "";

        let word1 = topLeft + "A" + bottomRight;
        let word2 = topRight + "A" + bottomLeft;

        if ((mas.test(word1) == true) && (mas.test(word2) == true)){
            sum++;
        }
    }

    return sum;
};

async function main(filename: string) {
    try {
        let sum = 0;

        // Read and process the file into a 2D array
        const file = (await Deno.readTextFile(filename))
            .trim()
            .split("\n")
            .map(line => line.split(""));

        const row = file.length;
        const col = file[0]?.length || 0;

        for (let i = 0; i < row; i++) {
            for (let j = 0; j < col; j++) {
                sum += masSearch(file, i, j, row, col);
            }
        }

        console.log("Sum:", sum);
    } catch (error) {
        if (error instanceof Deno.errors.NotFound) {
            console.error(`Error: File '${filename}' not found.`);
            Deno.exit(1);
        }
        console.error("Error reading file:", error);
        Deno.exit(1);
    }
}

let filename = "xmas.txt";
main(filename);

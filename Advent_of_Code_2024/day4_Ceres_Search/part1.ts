const xmasSearch = (file: Array<Array<string>>, i: number, j: number, row: number, col: number): number => {
    let sum = 0;
    const xmas = RegExp(/XMAS/); 
    const index = file[i][j];
    const directions = [
        [0, 1],   // Forward (Right)
        [0, -1],  // Backward (Left)
        [1, 0],   // Down
        [-1, 0],  // Up
        [1, 1],   // Diagonal Down-Right
        [-1, -1], // Diagonal Up-Left
        [1, -1],  // Diagonal Down-Left
        [-1, 1]   // Diagonal Up-Right
    ];
    

    if (index === "X") {
        for (const [dx, dy] of directions) {
            let word = ""; // Reset `word` for each direction
            for (let k = 0; k < 4; k++) {
                const x = i + dx * k;
                const y = j + dy * k;

                // Check bounds
                if (x < 0 || x >= row || y < 0 || y >= col) break;

                word += file[x][y];
            }
            // Check if the word matches "XMAS"
            if (xmas.test(word)) {
                sum++;
            }
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
                sum += xmasSearch(file, i, j, row, col);
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

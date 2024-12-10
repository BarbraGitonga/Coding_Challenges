const multiplier = (mulArray:  RegExpMatchArray | null): number => {
    const re = new RegExp(/\d+/, "g");
    var sum = 0
    if (mulArray != null){
        for(var i = 0; i<mulArray.length; i++){
            var digits = mulArray[i].match(re);
            if (digits != null){
                var mul = (+digits[0]) * (+digits[1]);
                sum += mul;
            }
        }
    }
    return sum;
};

const regex = (line: string): number => {
    const re = new RegExp(/(mul)\((\d+),(\d+)\)/, "g");
    const clean = line.match(re);
    const sum = multiplier(clean);
    return sum;
};

async function readInput(filename: string): Promise<string> {
    const text = await Deno.readTextFile(filename);
    return text;
};

async function main(filename: string) {
    try {
        let sum = 0;
        const file = await Deno.readTextFile(filename);
        const lines = file.split("\n");

        for (const line of lines) {
            console.log(line);
            sum += regex(line);
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

let filename = "mul.txt";
main(filename);




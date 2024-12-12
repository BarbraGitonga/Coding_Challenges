const multiplyDo = (mulArray: RegExpMatchArray | null): number => {
    const re = new RegExp(/\d+/, "g");
    let isInsideDontBlock = false;
    var sum = 0;

    if (mulArray !== null) {
        console.log("Processing matches:", mulArray);
        for(var i = 0; i<mulArray.length; i++) {
            if (mulArray[i] == "don't") {
                isInsideDontBlock = true;
                continue;
            }

            if (mulArray[i] == "do") {
                isInsideDontBlock = false;
                continue;
            }

            if (isInsideDontBlock == true) {
                continue;
            }

            var digits = mulArray[i].match(re);
            if (digits != null) {
                var mul = (+digits[0]) * (+digits[1]);
                console.log(`Multiplying ${digits[0]} * ${digits[1]} = ${mul}`);
                sum += mul;
            }
        }
    }
    return sum;
};

const regexNew = (line: string): number => {
    const re = new RegExp(/((mul)\((\d+),(\d+)\))|don't|do/, "g");
    const captured = line.match(re);
    const sum = multiplyDo(captured);
    return sum;
};

async function mains(filename: string) {
    try {
        let sum = 0;
        const file = await Deno.readTextFile(filename);
        sum += regexNew(file);
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

let filenames = "mul.txt";
mains(filenames);
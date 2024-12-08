class MazeGenerator {
    constructor(random) {
        this.random = random;
        this.grid = null;
        this.width = 0;
        this.height = 0;
        this.start = null;
        this.finish = null;
    }

    // Represents a single cell in the maze
    static Cell = class {
        constructor(x, y) {
            this.x = x;
            this.y = y;
            this.walls = { top: true, right: true, bottom: true, left: true };
            this.visited = false;
        }
    };

    // Create the grid of cells
    createGrid(width, height) {
        this.width = width;
        this.height = height;
        this.grid = [];
        for (let y = 0; y < height; y++) {
            const row = [];
            for (let x = 0; x < width; x++) {
                row.push(new MazeGenerator.Cell(x, y));
            }
            this.grid.push(row);
        }
    }

    // Get unvisited neighbors of a cell
    getNeighbors(cell) {
        const neighbors = [];
        const { x, y } = cell;

        if (y > 0) {
            const top = this.grid[y - 1][x];
            if (!top.visited) {
                neighbors.push({ cell: top, direction: 'top' });
            }
        }
        if (x < this.width - 1) {
            const right = this.grid[y][x + 1];
            if (!right.visited) {
                neighbors.push({ cell: right, direction: 'right' });
            }
        }
        if (y < this.height - 1) {
            const bottom = this.grid[y + 1][x];
            if (!bottom.visited) {
                neighbors.push({ cell: bottom, direction: 'bottom' });
            }
        }
        if (x > 0) {
            const left = this.grid[y][x - 1];
            if (!left.visited) {
                neighbors.push({ cell: left, direction: 'left' });
            }
        }

        return neighbors;
    }

    // Generate the maze using the depth-first search algorithm
    generateMaze(width, height) {
        this.createGrid(width, height);

        const stack = [];
        const start = this.grid[0][0];
        this.start = start; // Set start point
        start.visited = true;
        start.walls.left = false; 
        stack.push(start);

        while (stack.length > 0) {
            const current = stack.pop();
            const neighbors = this.getNeighbors(current);

            if (neighbors.length > 0) {
                stack.push(current);
                const nextIndex = Math.floor(this.random() * neighbors.length);
                const next = neighbors[nextIndex];

                switch (next.direction) {
                    case 'top':
                        current.walls.top = false;
                        next.cell.walls.bottom = false;
                        break;
                    case 'right':
                        current.walls.right = false;
                        next.cell.walls.left = false;
                        break;
                    case 'bottom':
                        current.walls.bottom = false;
                        next.cell.walls.top = false;
                        break;
                    case 'left':
                        current.walls.left = false;
                        next.cell.walls.right = false;
                        break;
                }

                next.cell.visited = true;
                stack.push(next.cell);
            }
        }
        this.finish = this.grid[height - 1][width - 1]; // Set finish point
        this.finish.walls.right = false;
    }

    // Get the generated grid
    getGrid() {
        return this.grid;
    }
    getStartAndFinish() {
        return { start: this.start, finish: this.finish };
    }
}

class MazeLineGenerator {
    constructor(mazeGenerator, cellSize) {
        this.mazeGenerator = mazeGenerator;
        this.cellSize = cellSize;
    }

    generateLines() {
        const lines = [];
        const grid = this.mazeGenerator.getGrid();
        const cellSize = this.cellSize;

        for (let y = 0; y < grid.length; y++) {
            for (let x = 0; x < grid[y].length; x++) {
                const cell = grid[y][x];
                const startX = x * cellSize;
                const startY = y * cellSize;

                if (cell.walls.top) {
                    lines.push({ x1: startX, y1: startY, x2: startX + cellSize, y2: startY });
                }
                if (cell.walls.right) {
                    lines.push({ x1: startX + cellSize, y1: startY, x2: startX + cellSize, y2: startY + cellSize });
                }
                if (cell.walls.bottom) {
                    lines.push({ x1: startX, y1: startY + cellSize, x2: startX + cellSize, y2: startY + cellSize });
                }
                if (cell.walls.left) {
                    lines.push({ x1: startX, y1: startY, x2: startX, y2: startY + cellSize });
                }
            }
        }

        return lines;
    }
}

class MazeTextRenderer {
    constructor(mazeGenerator, blockSize) {
        this.mazeGenerator = mazeGenerator;
        this.grid = this.mazeGenerator.getGrid();
        this.width = this.grid[0].length;
        this.height = this.grid.length;
        this.cellBlockSize = blockSize;
        this.output = Array(this.height * this.cellBlockSize+1).fill(null).map(() => Array(this.width * this.cellBlockSize+1).fill(' '));
    }

    render() {
        const { start, finish } = this.mazeGenerator.getStartAndFinish();

        for (let y = 0; y < this.height; y++) {
            for (let x = 0; x < this.width; x++) {
                const cell = this.grid[y][x];
                const topLeftX = x * this.cellBlockSize;
                const topLeftY = y * this.cellBlockSize;

                if (cell.walls.top) {
                    for (let i = 0; i <= this.cellBlockSize; i++) {
                        this.output[topLeftY][topLeftX + i] = '#';
                    }
                }

                if (cell.walls.bottom) {
                    for (let i = 0; i <= this.cellBlockSize; i++) {
                        this.output[topLeftY + this.cellBlockSize][topLeftX + i] = '#';
                    }
                }
                if (cell.walls.left) {
                    for (let i = 0; i <= this.cellBlockSize; i++) {
                        this.output[topLeftY + i][topLeftX] = '#';
                    }
                }
                if (cell.walls.right) {
                    for (let i = 0; i <= this.cellBlockSize; i++) {
                        this.output[topLeftY + i][topLeftX + this.cellBlockSize] = '#';
                    }
                }
            }
        }

        // Mark start and finish
        const markPoint = (point, symbol) => {
            const x = point.x * this.cellBlockSize + Math.floor(this.cellBlockSize / 2);
            const y = point.y * this.cellBlockSize + Math.floor(this.cellBlockSize / 2);
            this.output[y][x] = symbol;
        };

        markPoint(start, 'S');
        markPoint(finish, 'F');
    }
    print()
    {
        console.log(output.map(row => row.join('')).join('\n'));
    }
    getSize()
    {
        return {width:this.height * this.cellBlockSize+1, height:this.height * this.cellBlockSize+1};
    }
    getPixel(x, y)
    {
        return this.output[y][x];
    }
}

/*
// Example usage:
const maze = new MazeGenerator();
maze.generateMaze(20, 7);
console.log(maze)
const textRenderer = new MazeTextRenderer(maze);
textRenderer.render();
*/
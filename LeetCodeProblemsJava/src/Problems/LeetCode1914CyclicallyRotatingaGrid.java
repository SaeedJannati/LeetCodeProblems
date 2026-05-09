package Problems;

public class LeetCode1914CyclicallyRotatingaGrid {
    public int[][] rotateGrid(int[][] grid, int k) {
        int layersCount = Math.min(grid.length / 2, grid[0].length / 2);
        int width = grid[0].length;
        int height = grid.length;
        for (int i = 0; i < layersCount; i++) {
            int layerLength = 2 * (width - 2 * i) + 2 * (height - 2 * i) - 4;
            int[][] layer = new int[layerLength][2];
            int counter = 0;
            for (int j = i; j < width - i; j++) {
                layer[counter][1] = (i * width + j);
                layer[counter++][0] = grid[i][j];
            }
            for (int j = i + 1; j < height - i - 1; j++) {
                layer[counter][1] = (j * width + width - i - 1);
                layer[counter++][0] = grid[j][width - i - 1];
            }
            for (int j = width - i - 1; j >= i; j--) {
                layer[counter][1] = ((height - i - 1) * width + j);
                layer[counter++][0] = grid[height - i - 1][j];
            }
            for (int j = height - i - 2; j > i; j--) {
                layer[counter][1] = (j * width + i);
                layer[counter++][0] = grid[j][i];
            }
            for (int j = 0; j < layerLength; j++) {
                grid[layer[j][1] / width][layer[j][1] % width] =
                        layer[(j + (k % layerLength)) % layerLength][0];
            }

        }
        return grid;
    }
}

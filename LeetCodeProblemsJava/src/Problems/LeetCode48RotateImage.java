package Problems;

import java.util.HashMap;

public class LeetCode48RotateImage extends BaseProblem {
    public void rotate(int[][] matrix) {
        int n = matrix.length;
        if (n % 2 == 0) {
            for (int i = 0; i < n / 2; i++) {
                for (int j = 0; j < n / 2; j++) {
                    doRotate(matrix, i, j, n);
                }
            }
        } else {
            for (int i = 0; i <= n / 2; i++) {
                for (int j = 0; j < n / 2; j++) {
                    doRotate(matrix, i, j, n);
                }
            }
        }

    }

    private  void doRotate(int[][] matrix, int i, int j, int n) {
        HashMap<Integer, Integer> map = new HashMap<>();
        int row = i;
        int col = j;
        int newRow, newCol;
        for (int k = 0; k < 4; k++) {
            newRow = col;
            newCol = n - 1 - row;
            map.put(newRow * n + newCol, matrix[row][col]);
            row = newRow;
            col = newCol;

        }
        for (var pair : map.entrySet()) {
            matrix[pair.getKey() / n][pair.getKey() % n] = pair.getValue();
        }
    }

    @Override
    public void Run() {
        int[][] matrix =
//                {{1,2,3,4,5},{6,7,8,9,10},{11,12,13,14,15},{16,17,18,19,20},{21,22,23,24,25}};
//                {{5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}};
                {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
        rotate(matrix);
        for (int i = 0, e = matrix.length; i < e; i++) {
            for (int j = 0; j < e; j++) {
                System.out.print(matrix[i][j] + ",");
            }
            System.out.println();
        }
    }
}

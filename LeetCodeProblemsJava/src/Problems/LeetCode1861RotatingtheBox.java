package Problems;

import java.util.Arrays;
import java.util.stream.IntStream;

public class LeetCode1861RotatingtheBox extends BaseProblem{
    public char[][] rotateTheBox(char[][] boxGrid) {
        int height = boxGrid.length;
        int width = boxGrid[0].length;
        int secondPointer = width;
        for (int i = 0; i < height; i++) {
            secondPointer = width-1;
            for (int j = width - 1; j >= 0; j--) {
                if (boxGrid[i][j] == '*') {
                    secondPointer=j-1;
                    continue;
                }
                if(boxGrid[i][j]!='#')
                    continue;
                boxGrid[i][j] = '.';
                boxGrid[i][secondPointer] = '#';
                secondPointer--;
            }
        }
        char[][] result = new char[width][height];
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                result[j][height - 1 - i] = boxGrid[i][j];
            }
        }
        return result;
    }

    @Override
    public void Run() {
        char[][] boxGrid = {{'#', '#', '*', '.', '*', '.'},
                {'#', '#', '#', '*', '.', '.'},
                {'#', '#', '#', '.', '#', '.'}};
//                {{'#', '.', '*', '.'},
//                {'#', '#', '*', '.'}};
        var gird=rotateTheBox(boxGrid);
        Character[][] boxed = Arrays.stream(gird).map(chars -> IntStream.range(0, chars.length)
                        .mapToObj(j -> chars[j])
                        .toArray(Character[]::new))
                .toArray(Character[][]::new);
        Auxileries.Print(boxed);
    }
}

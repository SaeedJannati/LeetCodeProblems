namespace LeetCodeProblems.Problems;

public class LeetCode79WordSearch : BaseProblemClass
{
    public bool Exist(char[][] board, string word)
    {
        List<WordSoFar> words = [];
        Dictionary<char, int> dictionary = [];


        foreach (var c in word)
        {
            if (dictionary.ContainsKey(c))
                dictionary[c]++;
            else
                dictionary[c] = 1;
        }


        var chars = word.ToArray().ToList();
        if (dictionary[word[0]] > dictionary[word[^1]])
            chars.Reverse();
        var boardDict = new Dictionary<char, int>();
        for (int row = 0; row < board.Length; row++)
        for (int col = 0; col < board[row].Length; col++)
        {
            if (boardDict.ContainsKey(board[row][col]))
                boardDict[board[row][col]]++;
            else
            {
                boardDict[board[row][col]] = 1;
            }
        }

        foreach (var pair in dictionary)
        {
            if (!boardDict.ContainsKey(pair.Key))
                return false;
            if (boardDict[pair.Key] < pair.Value)
                return false;
        }
        foreach (var c in chars)
        {
            AddLayer(words, board, c);
            if (words.Count == 0)
                return false;
        }

        return words.Count > 0;
    }

    private void AddLayer(List<WordSoFar> words, char[][] board, char c)
    {
        if (words.Count == 0)
        {
            for (int i = 0; i < board.Length; i++)
            {
                for (int j = 0; j < board[0].Length; j++)
                {
                    if (board[i][j] != c)
                        continue;
                    var wordSoFar = new WordSoFar();
                    wordSoFar.row = i;
                    wordSoFar.col = j;
                    wordSoFar.TryAddPoint(i, j);
                    words.Add(wordSoFar);
                }
            }

            return;
        }

        for (int i = words.Count - 1; i >= 0; i--)
        {
            var newPoses = FindChar(words[i].row, words[i].col, c, board);
            if (newPoses.Count == 0)
            {
                words.RemoveAt(i);
                continue;
            }

            bool filled = false;
            var temp = new WordSoFar
            {
                row = words[i].row,
                col = words[i].col
            };
            foreach (var kvp in words[i].dict)
            {
                var newSortedList = new SortedList<int, int>(kvp.Value);
                temp.dict[kvp.Key] = newSortedList;
            }

            foreach (var pos in newPoses)
            {
                if (!filled)
                {
                    if (!words[i].TryAddPoint(pos.row, pos.col))
                        continue;
                    filled = true;
                    continue;
                }

                if (!temp.CanAdd(pos.row, pos.col))
                    continue;
                var temp2 = new WordSoFar
                {
                    row = temp.row,
                    col = temp.col
                };
                foreach (var kvp in temp.dict)
                {
                    var newSortedList = new SortedList<int, int>(kvp.Value);
                    temp2.dict[kvp.Key] = newSortedList;
                }

                temp2.TryAddPoint(pos.row, pos.col);
                words.Add(temp2);
            }

            if (!filled)
                words.RemoveAt(i);
        }
    }

    private List<(int row, int col)> FindChar(int row, int col, char c, char[][] board)
    {
        var outPut = new List<(int row, int col)>();
        List<int> rows = [];
        List<int> cols = [];
        if (row > 0)
            rows.Add(row - 1);
        if (row < board.Length - 1)
            rows.Add(row + 1);
        if (col > 0)
            cols.Add(col - 1);
        if (col < board[0].Length - 1)
            cols.Add(col + 1);
        rows.ForEach(r =>
        {
            if (board[r][col] == c)
                outPut.Add((r, col));
        });
        cols.ForEach(co =>
        {
            if (board[row][co] == c)
                outPut.Add((row, co));
        });
        return outPut;
    }

    private class WordSoFar
    {
        public Dictionary<int, SortedList<int, int>> dict = [];
        public int row;
        public int col;

        public bool CanAdd(int aRow, int aCol)
        {
            if (!dict.ContainsKey(aRow))
                return true;
            if (dict[aRow].ContainsKey(aCol))
                return false;
            return true;
        }

        public bool TryAddPoint(int aRow, int aCol)
        {
            if (!dict.ContainsKey(aRow))
            {
                dict[aRow] = new SortedList<int, int> {{aCol, aCol}};
                row = aRow;
                col = aCol;
                return true;
            }

            if (dict[aRow].ContainsKey(aCol))
                return false;
            dict[aRow].Add(aCol, aCol);
            row = aRow;
            col = aCol;
            return true;
        }
    }
    public override void Run()
    {
        char[][] board = [['A', 'B', 'C', 'E'], ['S', 'F', 'E', 'S'], ['A', 'D', 'E', 'E']];
        string word = "ABCEFSADEESE";
        Console.WriteLine(Exist(board, word));
    }
}
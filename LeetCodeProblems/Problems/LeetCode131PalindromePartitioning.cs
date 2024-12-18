namespace LeetCodeProblems.Problems;

public class LeetCode131PalindromePartitioning
{
    public IList<IList<string>> Partition(string s)
    {
        int length = s.Length;
        if (length == 1)
            return [[s]];
        IList<Permutation> permutaions = [];
        IList<IList<string>> result = [];
        var currentString = string.Empty;
        permutaions.Add(new(0, [s[..1]]));
        for (int i = 1; i < length; i++)
        {
            currentString = s[..(i + 1)];
            if (!IsPalindrome(currentString))
                continue;
            if (i == length - 1)
            {
                result.Add([currentString]);
                continue;
            }

            permutaions.Add(new(i, [currentString]));
        }

        while (permutaions.Count > 0)
        {
            for (int i = permutaions.Count - 1; i >= 0; i--)
            {
                bool found = false;
                var temp = new Permutation(permutaions[i]);
                for (int j = temp.lastIndex + 1; j < length; j++)
                {
                    string current = s.Substring(temp.lastIndex + 1, j - temp.lastIndex);
                    if (!IsPalindrome(current))
                        continue;
                    if (j == length - 1)
                    {
                        if (!found)
                        {
                            permutaions.RemoveAt(i);
                            found = true;
                        }


                        temp.items.Add(current);
                        result.Add([..temp.items]);
                        continue;
                    }

                    if (!found)
                    {
                        found = true;
                        permutaions[i].lastIndex = j;
                        permutaions[i].items.Add(current);
                        continue;
                    }

                    var newTemp = new Permutation(temp);
                    newTemp.lastIndex = j;
                    newTemp.items.Add(current);
                    permutaions.Add(newTemp);
                }

                if (!found)
                    permutaions.RemoveAt(i);
            }
        }

        return result;
    }

    private bool IsPalindrome(string input)
    {
        int length = input.Length;
        for (int i = 0; i < length; i++)
        {
            if (input[i] != input[length - i - 1])
                return false;
        }

        return true;
    }

    public class Permutation
    {
        public Permutation(Permutation permutation)
        {
            lastIndex = permutation.lastIndex;
            items = [..permutation.items];
        }

        public Permutation(int lastIndex, IList<string> items)
        {
            this.lastIndex = lastIndex;
            this.items = [..items];
        }

        public Permutation()
        {
        }

        public int lastIndex;
        public IList<string> items = [];
    }
}
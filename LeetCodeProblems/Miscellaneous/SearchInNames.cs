namespace LeetCodeProblems.Miscellaneous;

public class SearchInNames : BaseProblemClass
{
    

    #region using quick sort

    private void RecurseQuickSort(List<string> names, int begin, int end)
    {
        if (begin >= end)
            return;
        int pivotIndex = begin;
        for (int i = pivotIndex + 1; i <= end; i++)
        {
            if (!IsLexicographicallyBefore(names[i], names[begin]))
                continue;
            pivotIndex++;
            (names[i], names[pivotIndex]) = (names[pivotIndex], names[i]);
        }

        (names[begin], names[pivotIndex]) = (names[pivotIndex], names[begin]);
        RecurseQuickSort(names, begin, pivotIndex - 1);
        RecurseQuickSort(names, pivotIndex + 1, end);
    }

    public void QuickSort(List<string> names)
    {
        RecurseQuickSort(names, 0, names.Count - 1);
    }
    public string GetSecondNameFromEnd(string names)
    {
        var namesPart = names.Split(' ').Where(i=>i.Length>0).ToList();
        QuickSort(namesPart);
        return namesPart[^2];
    }
    #endregion
# region  using max heap
    // public string GetSecondNameFromEnd(string names)
    // {
    //     var namesPart = names.Split(' ').Where(i=>i.Length>0).ToList();
    //     var queue = new PriorityQueue<string, string>(Comparer<string>.Create((a,b)=>-string.Compare(a, b, StringComparison.Ordinal)));
    //     namesPart.ForEach(i=>queue.Enqueue(i,i));
    //     queue.Dequeue();
    //     return queue.Dequeue();
    // }
#endregion
    bool IsLexicographicallyBefore(string first, string second)
    {
        int firstLength = first.Length;
        int secondLength = second.Length;
        int minLength = Math.Min(firstLength, secondLength);
        for (int i = 0; i < minLength; i++)
        {
            if (first[i] < second[i])
                return true;
            if (second[i] < first[i])
                return false;
        }

        return firstLength < secondLength;
    }

    public override void Run()
    {
        string plainNames = " nastaran shayan ahmad niloofar";
        Console.WriteLine(GetSecondNameFromEnd(plainNames));
    }
}
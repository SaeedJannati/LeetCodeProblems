namespace LeetCodeProblems.Problems;

public class LeetCode502IPO : BaseProblemClass
{
    public int FindMaximizedCapital(int k, int w, int[] profits, int[] capital)
    {
        List<(int prof, int cap)> dict = profits.Select((value, index) => (value, capital[index])).ToList();
        dict.Sort((i, j) => i.cap.CompareTo(j.cap));
        var length = capital.Length;
        PriorityQueue<int, int> list = new(length);
        int index = 0;
        for (int i = 0; i < k; i++)
        {
            var values = new List<(int prof, int cap)>();
            while (index < length && dict[index].cap <= w)
            {
                values.Add(dict[index]);
                index++;
            }

            foreach (var value in values)
            {
                list.Enqueue(value.prof, -value.prof);
            }

            if (list.Count == 0)
                break;
            w += list.Dequeue();
        }

        return w;
    }

    public override void Run()
    {
        int k = 2;
        int w = 0;
        int[] profits =
        [
            1, 3, 2
        ];
        int[] capital =
        [
            5,7, 2
        ];
        Console.WriteLine(FindMaximizedCapital(k, w, profits, capital));
    }
}
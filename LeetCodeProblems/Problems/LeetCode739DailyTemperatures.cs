namespace LeetCodeProblems.Problems;

public class LeetCode739DailyTemperatures
{
    public int[] DailyTemperatures(int[] temperatures) {
        int length = temperatures.Length;
        Stack<int> temperaturesStack = new Stack<int>(length);
        Dictionary<int,int> temperaturesDictionary = new Dictionary<int,int>(length);
        int temperature = 0;
        for (int i = length - 1; i >= 0; i--)
        {
            while (temperaturesStack.Count != 0 && temperaturesStack.Peek()<=temperatures[i])
            {
                temperaturesStack.Pop();
            }

            temperature = temperatures[i];
            if (temperaturesStack.Count == 0)
                temperatures[i] = 0;
            else
            {
                temperatures[i]=temperaturesDictionary[temperaturesStack.Peek()]-i;
            }
            temperaturesStack.Push(temperature);
            
            temperaturesDictionary[temperature]=i;
        }

        return temperatures;
    }
}
namespace LeetCodeProblems.Problems;

public class LeetCode649Dota2Senate
{
    public string PredictPartyVictory(string senate)
    {
        int direCount = 0;
        int radiantCount = 0;
        int direVoteCount = 0;
        int radiantVoteCount = 0;
        Queue<char> queue = new Queue<char>();
        foreach (var c in senate)
        {
            if (c == 'R')
            {
                radiantCount++;
            }
            else
            {
                direCount++;
            }
            queue.Enqueue(c);
            
        }

        char current;
        while (direCount>0 && radiantCount>0)
        {
            current=queue.Dequeue();
            if (current == 'R')
            {
                if (direVoteCount > 0)
                {
                    direVoteCount--;
                    radiantCount--;
                    if (radiantCount == 0)
                        return "Dire";
                    continue;
                }
                radiantVoteCount++;
            }
            else
            {
                if (radiantVoteCount > 0)
                {
                    radiantVoteCount--;
                    direCount --;
                    if (direCount == 0)
                        return "Radiant";
                    continue;
                }
                direVoteCount ++;
            }

            queue.Enqueue(current);
        }
        return direCount>0? "Dire" : "Radiant";
    }
}
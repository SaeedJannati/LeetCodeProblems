namespace LeetCodeProblems;

public class LeetCode433Minimum_Genetic_Mutation : BaseProblemClass
{
    public override void Run()
    {
    }

    public int MinMutation(string startGene, string endGene, string[] bank)
    {
        int mutationCount = 0;
        Queue<string> mutationsToCheck = new();
        Queue<string> nextLayerMutations = new();
        HashSet<string> checkedMutations = new();
        mutationsToCheck.Enqueue(startGene);
        while (mutationsToCheck.Count > 0)
        {
            while (mutationsToCheck.Count > 0)
            {
                var currentMutation = mutationsToCheck.Dequeue();
                checkedMutations.Add(currentMutation);
                if (currentMutation == endGene)
                    return mutationCount;
                foreach (var mutation in bank)
                {
                    if (checkedMutations.Contains(mutation))
                        continue;
                    if (!AreMutations(currentMutation, mutation))
                        continue;
                    nextLayerMutations.Enqueue(mutation);
                }
            }

            mutationCount++;
            while (nextLayerMutations.Count > 0)
            {
                mutationsToCheck.Enqueue(nextLayerMutations.Dequeue());
            }
        }

        return -1;
    }

    private bool AreMutations(string first, string second)
    {
        int diffCount = 0;
        for (int i = 0; i < 8; i++)
        {
            if (first[i] != second[i])
                diffCount++;
            if (diffCount > 1)
                return false;
        }

        return true;
    }
}
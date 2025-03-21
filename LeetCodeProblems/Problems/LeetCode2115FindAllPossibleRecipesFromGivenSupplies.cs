using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode2115FindAllPossibleRecipesFromGivenSupplies: BaseProblemClass
{
    public IList<string> FindAllRecipes(string[] recipes, IList<IList<string>> ingredients, string[] supplies)
    {
        Dictionary<string, HashSet<string>> adjPlus = [];
        Dictionary<string, HashSet<string>> adjMinus = [];
        HashSet<string> recipesSet = [];
        for (int i = 0, e = recipes.Length; i < e; i++)
        {
            adjMinus[recipes[i]] = [];
            recipesSet.Add(recipes[i]);
            foreach (var item in ingredients[i])
            {
                if (!adjPlus.ContainsKey(item))
                    adjPlus[item] = [];
                adjPlus[item].Add(recipes[i]);
                adjMinus[recipes[i]].Add(item);
            }
        }

        Queue<string> queue = [];
        foreach (var supply in supplies)
        {
            queue.Enqueue(supply);
        }

        IList<string> result = [];
        while (queue.Count > 0)
        {
            var node = queue.Dequeue();
            if (!adjPlus.ContainsKey(node))
                continue;
            foreach (var item in adjPlus[node])
            {
                adjMinus[item].Remove(node);
                if (adjMinus[item].Count != 0) 
                    continue;
                if(recipesSet.Contains(item))
                    result.Add(item);
                adjMinus.Remove(item);
                queue.Enqueue(item);

            }
        }
        return result;
    }

    public override void Run()
    {
        string[] recipes = ["ju", "fzjnm", "x", "e", "zpmcz", "h", "q"];
        IList<IList<string>> ingredients =
        [
            ["d"], ["hveml", "f", "cpivl"], 
            ["cpivl", "zpmcz", "h", "e", "fzjnm", "ju"],
            ["cpivl", "hveml", "zpmcz", "ju", "h"], 
            ["h", "fzjnm", "e", "q", "x"],
            ["d", "hveml", "cpivl", "q", "zpmcz", "ju", "e", "x"], 
            ["f", "hveml", "cpivl"]
        ];
        string[] supplies = ["f", "hveml", "cpivl", "d"];
        var results=FindAllRecipes(recipes, ingredients, supplies);
        Console.WriteLine(JsonSerializer.Serialize(results));
    }
}
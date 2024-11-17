using System.Text.Json;

namespace LeetCodeProblems.Problems;

public class LeetCode399EvaluateDivision: BaseProblemClass
{
    public double[] CalcEquation(IList<IList<string>> equations, double[] values, IList<IList<string>> queries)
    {
        var graph = new Graph();
        graph.AddAdjacencies(equations, values);
        int length=queries.Count;
        var outPut = new double[length];
        for (int i = 0; i < length; i++)
        {
            if (!graph.symbols.Contains(queries[i][0]))
                outPut[i] = -1;
            if (!graph.symbols.Contains(queries[i][1]))
                outPut[i] = -1;
            var result = CalcQuery(queries[i][0],queries[i][1], graph,1,[]);
            if (!result.found)
            {
                outPut[i] = -1;
                continue;
            }
            outPut[i] = result.value;
        }

        return outPut;
    }

    private (bool found, double value) CalcQuery(string current,string dest, Graph graph,double result,HashSet<string> visited)
    {
        if(!visited.Add(current))
            return (false, result);
        if(!graph.adjacencies.TryGetValue(current, out var children))
            return (false, result);
        foreach (var child in children)
        {
            double answer=result*child.Value;
            if (child.Key == dest)
            {
                return (true, answer);
            }
            var product= CalcQuery(child.Key,dest,graph,answer,visited);
            if(product.found)
                return (true, product.value);
        }
        return (false, result);
    }

    public class Graph
    {
        public Dictionary<string, Dictionary<string, double>> adjacencies = [];
        public HashSet<string> symbols = [];

        public void AddAdjacencies(IList<IList<string>> equations, double[] values)
        {
            for (int i = 0, e = values.Length; i < e; i++)
            {
                symbols.Add(equations[i][0]);
                symbols.Add(equations[i][1]);
                if (adjacencies.TryGetValue(equations[i][0], out var value))
                    value.Add(equations[i][1], values[i]);
                else
                {
                    adjacencies.Add(equations[i][0], new Dictionary<string, double>());
                    adjacencies[equations[i][0]].Add(equations[i][1], values[i]);
                }
                if (adjacencies.TryGetValue(equations[i][1], out  value))
                    value.Add(equations[i][0], 1/values[i]);
                else
                {
                    adjacencies.Add(equations[i][1], new Dictionary<string, double>());
                    adjacencies[equations[i][1]].Add(equations[i][0], 1/values[i]);
                }
            }
        }
    }

    public override void Run()
    {
        IList<IList<string>> equations = [["a","b"],["b","c"]];
        double[] values = [2.0,3.0];
        IList<IList<string>> queries = [["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"]];
        Console.WriteLine(JsonSerializer.Serialize(CalcEquation(equations, values, queries)));
    }
}
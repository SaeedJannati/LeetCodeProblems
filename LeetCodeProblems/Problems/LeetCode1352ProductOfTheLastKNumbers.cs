namespace LeetCodeProblems.Problems;

public class LeetCode1352ProductOfTheLastKNumbers : BaseProblemClass
{
    public class ProductOfNumbers
    {
        private List<long> prefixProducts = [];


        public void Add(int num)
        {
            if (num == 0)
            {
                prefixProducts = [];
                return;
            }

            int count = prefixProducts.Count;
            if (count == 0)
            {
                prefixProducts.Add(num);
                return;
            }
            prefixProducts.Add(num*prefixProducts[count - 1]);
        }

        public int GetProduct(int k)
        {
            int count = prefixProducts.Count;
            if (k > count)
                return 0;
            if(k==count)
                return (int)prefixProducts[count - 1];
            return (int)(prefixProducts[count-1]/prefixProducts[count-k-1]);
        }
    }

    public override void Run()
    {
        var productOfNumbers = new ProductOfNumbers();
        productOfNumbers.Add(3);
        productOfNumbers.Add(0);
        productOfNumbers.Add(2);
        productOfNumbers.Add(5);
        productOfNumbers.Add(4);
        var product = productOfNumbers.GetProduct(2);
        Console.WriteLine(product);
    }
}
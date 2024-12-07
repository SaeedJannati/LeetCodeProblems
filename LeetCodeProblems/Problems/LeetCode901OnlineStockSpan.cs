namespace LeetCodeProblems.Problems;

public class LeetCode901OnlineStockSpan
{
    #region Monotonique stack

    public class StockSpanner
    {
        private Stack<(int price, int span)> _stack = [];
        private int _span = 0;
        public StockSpanner()
        {
        }

        public int Next(int price)
        {
            _span = 1;
            while (_stack.Count > 0 && price >= _stack.Peek().price)
            {
                _span+= _stack.Pop().span;
            }
            _stack.Push((price, _span));
            return _span;
        }
    }

    #endregion

    #region List

    // public class StockSpanner
    // {
    //     List<int> _stocks = [];
    //     private int _days = 0;
    //     public StockSpanner()
    //     {
    //     }
    //
    //     public int Next(int price)
    //     {
    //         _days = 1;
    //         for (int i = _stocks.Count - 1; i >= 0; i--)
    //         {
    //             if(_stocks[i] > price)
    //                 break;
    //             _days++;
    //         }
    //         _stocks.Add(price);
    //         return _days;
    //     }
    // }

    #endregion
}
package Problems;

public class LeetCode3789MinimumCostToAcquireRequiredItems {
    public long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long result;
        if(costBoth<=cost1&&costBoth<=cost2){
            result = costBoth;
            result*=Math.max(need2,need1);
            return result;
        }
        long delta;
        if(costBoth> cost1+cost2){
            result=cost1;
            result*=need1;
            delta=cost2;
            delta*=need2;
            result+=delta;
            return result;
        }
        if(costBoth>cost1 && costBoth>cost2 && costBoth<=cost1+cost2){
            result=costBoth;
            result*= Math.min(need2,need1);
            if(need1>need2){
                delta=need1-need2;
                delta*=cost1;
            }else{
                delta=need2-need1;
                delta*=cost2;
            }
            result+=delta;
            return result;
        }
        result=costBoth;
        if(cost1>cost2){

            result*=need1;
            delta=need2-need1;
            if(delta>0){
                delta*=cost2;
                result+=delta;
            }
            return  result;
        }
        result=costBoth;
        result*=need2;
        delta=need1-need2;
        if(delta>0){
            delta*=cost1;
            result+=delta;
        }
        return  result;
    }
}

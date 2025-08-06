#include "LeetCode3479FruitsIntoBasketsIII.h"

#include <iostream>
using  namespace std;
void buildTree(vector<int>& segmentTree,vector<int>& baskets,int index,int start,int end)
{
    if (start==end)
    {
        segmentTree[index]=baskets[start];
        return;
    }
    int mid=(start+end)>>1;
    buildTree(segmentTree,baskets,index*2+1,start,mid);
    buildTree(segmentTree,baskets,index*2+2,mid+1,end);
    segmentTree[index]= max (segmentTree[index*2+1],segmentTree[index*2+2]) ;
}
void UpdateElement(vector<int>& segmentTree,int index)
{
    if (index==0)
        return;
    int parentIndex=(index-1)>>1;
    segmentTree[parentIndex]=max(segmentTree[parentIndex*2+1],segmentTree[parentIndex*2+2]) ;
    UpdateElement(segmentTree,parentIndex);
}
void FillBasket(vector<int>& segmentTree,int index)
{
    segmentTree[index]=-1;
    UpdateElement(segmentTree,index);
}
void queryFruit(vector<int> & segmentTree,int index,int start,int end,int fruit)
{
    if (fruit>segmentTree[index])
        return;
    if (start==end)
    {
        FillBasket(segmentTree,index);
        return;
    }
    int mid=(start+end)>>1;
    if (fruit<=segmentTree[(index<<1)+1])
    {
        queryFruit(segmentTree,(index<<1)+1,start,mid,fruit);
        return;
    }
    if (fruit<=segmentTree[(index<<1)+2])
    {
        queryFruit(segmentTree,(index<<1)+2,mid+1,end,fruit);
        return;
    }
}
int LeetCode3479FruitsIntoBasketsIII::numOfUnplacedFruits( vector<int>& fruits,  vector<int>& baskets)
{
    int length=static_cast<int> (baskets.size());
    vector<int> segmentTree(length * 4,-1);
    buildTree(segmentTree,baskets,0,0,length-1);
    int unplacedFruits=0;
    for (int i=0;i<length;i++)
    {
        if (fruits[i]>segmentTree[0])
        {
            unplacedFruits++;
            continue;
        }
        queryFruit(segmentTree,0,0,length-1,fruits[i]);
    }
    return unplacedFruits;
}

void LeetCode3479FruitsIntoBasketsIII::Run()
{
    vector<int> fruits{59,59};
    vector<int> baskets{27,46};
    cout<<numOfUnplacedFruits(fruits,baskets)<<"\n";
}

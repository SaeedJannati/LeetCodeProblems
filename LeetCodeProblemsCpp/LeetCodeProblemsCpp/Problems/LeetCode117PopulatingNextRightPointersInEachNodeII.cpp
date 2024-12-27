#include "LeetCode117PopulatingNextRightPointersInEachNodeII.h"

#include <vector>

void LeetCode117PopulatingNextRightPointersInEachNodeII::Run()
{
    BaseProblem::Run();
}

Node* LeetCode117PopulatingNextRightPointersInEachNodeII::connect(Node* root)
{
    if(root == nullptr)
        return nullptr;
    std::vector<Node*> layeredStack;
    std::vector<Node*> tempStack;
    layeredStack.push_back(root);
    tempStack.push_back(root);
    layeredStack.reserve(1000);
    tempStack.reserve(1000);
    while (!layeredStack.empty())
    {
        for (int i=0,e= static_cast<int>(layeredStack.size()-1) ; i<e; i++)
        {
            layeredStack[i]->next = layeredStack[i+1];
        }
        layeredStack.clear();
        for (auto i: tempStack)
        {
            if(i->left != nullptr)
                layeredStack.push_back(i->left);
            if(i->right != nullptr)
                layeredStack.push_back(i->right);
        }
        tempStack.clear();
        for (auto i: layeredStack)
            tempStack.push_back(i);
    }
    return root;
}




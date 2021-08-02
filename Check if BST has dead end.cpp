void storeNodes(Node * root, unordered_set<int> &all_nodes,
                          unordered_set<int> &leaf_nodes)
{
    if (root == NULL)
        return ;
 
    // store all node of binary search tree
    all_nodes.insert(root->data);
 
    // store leaf node in leaf_hash
    if (root->left==NULL && root->right==NULL)
    {
        leaf_nodes.insert(root->data);
        return ;
    }
 
    // recur call rest tree
    storeNodes(root-> left, all_nodes, leaf_nodes);
    storeNodes(root->right, all_nodes, leaf_nodes);
}
bool isDeadEnd(Node *root)
{
    //Your code here
  unordered_set<int> all_nodes;
  unordered_set<int> leaf_nodes;
  storeNodes(root,all_nodes,leaf_nodes);
  for (auto i = leaf_nodes.begin() ; i != leaf_nodes.end(); i++)
    {
        int x = (*i);
 
        // Here we check first and last element of
        // continuous sequence that are x-1 & x+1
        if(x!=1)
        if (all_nodes.find(x+1) != all_nodes.end() &&
            all_nodes.find(x-1) != all_nodes.end())
            return true;
            if(x==1)
              if (all_nodes.find(x+1) != all_nodes.end())
            return true;
    }
 
    return false;
}

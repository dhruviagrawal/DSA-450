class Solution{
  public:
    // root : the root Node of the given BST
    // target : the target sum
    void trav(Node*root,vector<int>&v)
    {
        if(!root)return;
        trav(root->left,v);
        v.push_back(root->data);
        trav(root->right,v);
    }
    int isPairPresent(struct Node *root, int target)
    {
    //add code here.
    vector<int>v;
    trav(root,v);
    int n=v.size();
    int i=0,j=n-1;
    while(j>i)
    {
        if(v[i]+v[j]>target)
        j--;
        else if(v[i]+v[j]<target)
        i++;
        else if(v[i]+v[j]==target)
        return 1;
    }
    return 0;
    }
};

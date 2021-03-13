typedef struct store
{
    int size;
    int min;
    int max;
    int ans;
    bool isBST;
} store;
store getans(Node*root)
{
    if(!root)
    return {0,INT_MAX,INT_MIN,0,true};
    if(!root->left and !root->right)
    return {1,root->data,root->data,1,true};
    store l = getans(root->left);
    store r = getans(root->right);
    store res;
    res.size = 1 + l.size + r.size;
    if(l.max<root->data and r.min>root->data and l.isBST and r.isBST)
    {
        res.isBST = true;
        res.min = min(root->data,min(l.min,r.min));
        res.max = max(root->data,max(l.max,r.max));
        res.ans = res.size;
        return res;
    }
    res.isBST = false;
    res.ans = max(l.ans,r.ans);
    return res;
}
int largestBst(Node *root)
{
	//Your code here
	if(!root)
	return 0;
	store res = getans(root);
	return res.ans;
}

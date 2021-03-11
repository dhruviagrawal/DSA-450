int ans = 1;
void temp(Node*root,int h, int &ma)
{
    if(root==NULL)
    return;
    if(ans==0)return;
    if(root->left==NULL and root->right==NULL)
    {
        if(ma==-1)
        ma = h;
        else
        {
            if(h!=ma)
            ans = 0;
        }
        return;
    }
    temp(root->left,h+1,ma);
    temp(root->right,h+1,ma);
}
/*You are required to complete this method*/
bool check(Node *root)
{
    //Your code here
    int a = 0, b = -1;
    ans = 1;
    temp(root,a,b);
    return ans;
}

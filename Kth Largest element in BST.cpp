int v = -1;
void dd(Node*root,int K,int &c)
{
    if(!root||K<=c)return;
    dd(root->right,K,c);
    c++;
    if(c==K)
    v = root->data;
   
    dd(root->left,K,c);
    
    
}
int kthLargest(Node *root, int K)
{
    //Your code here
    v = -1;
    int c = 0;
    dd(root,K,c);
    return v;
}

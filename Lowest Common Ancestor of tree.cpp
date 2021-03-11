Node* lca(Node* root ,int n1 ,int n2 )
{
   //Your code here 
   if(!root)return NULL;
   if(root->data==n1||root->data==n2)
   return root;
   Node*l1 = lca(root->left,n1,n2);
   Node*r1 = lca(root->right,n1,n2);
   if(l1&&r1)return root;
   else return l1?l1:r1;
   
}

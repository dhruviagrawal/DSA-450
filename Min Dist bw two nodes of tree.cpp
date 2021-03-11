// Find LCA of two values, then go left from one side and right from another, add up the distance from left to LCA and right to LCA, -2 to nullify self addition
 
Node*lca(Node*root,int a,int b)
 {
     if(!root)return NULL;
     if(root->data==a or root->data==b)
     return root;
     Node*l = lca(root->left,a,b);
     Node*r = lca(root->right,a,b);
     if(l and r)
     return root;
     if(l) return l;
     if(r) return r;
 }
 int distance(Node*root, int x)
 {
     if(!root)return 0;
     if(root->data==x)
     return 1;
     int l = distance(root->left,x);
     int r  = distance(root->right,x);
     if(!l and !r)
     return 0;
     return l + r + 1;
 }
int findDist(Node* root, int a, int b) {
    // Your code here
    Node*p = lca(root,a,b);
    return distance(p,a) + distance(p,b) -2;
}

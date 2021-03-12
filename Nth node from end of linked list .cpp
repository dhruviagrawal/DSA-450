int lz(Node*head)
{
    if(!head)
    return 0;
    return 1+lz(head->next);
}
int getNthFromLast(Node *head, int n)
{
       // Your code here
       if(n>lz(head))
       return -1;
       n*=-1;
       n+=lz(head);
       while(n--)
       head=head->next;
       return head->data;
       
}

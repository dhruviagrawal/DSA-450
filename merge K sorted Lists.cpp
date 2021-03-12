Node * mergeKLists(Node *arr[], int N)
{
       // Your code here
       priority_queue<int,vector<int>,greater<int>>q;
       for(int i=0;i<N;i++)
       {
           while(arr[i]){
           q.push(arr[i]->data);
           arr[i] = arr[i]->next;
           }
       }
       if(q.empty()) return NULL;
       Node*head = (Node*)malloc(sizeof(Node));
       head->data = q.top();
       head->next = NULL;
       Node*p = head;
       q.pop();
       while(!q.empty())
       {
           Node*temp = (Node*)malloc(sizeof(Node));
           temp->next = NULL;
           temp->data =  q.top();
           p->next = temp;
           p = temp;
           q.pop();
       }
       return head;
}

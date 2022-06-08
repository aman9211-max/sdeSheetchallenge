
int findIntersection(Node *f, Node *s)
{
    //Write your code here
    
    map<Node*, bool> vis;
    while(f) {
        vis[f] = true;
        f = f->next;
    }
      while(s) {
          if(vis[s]) {
              return s->data;
          }
          
          s = s->next;
      }
    return -1;
    
}



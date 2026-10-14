struct A{char p[16];int id;};struct N{A*a;int pad;N*next;};struct S{N*n;};A*func_005038F0(S*s,int n){N*p=s->n;while(p){A*a=p->a;if(a->id==n)return a;p=p->next;}return 0;}

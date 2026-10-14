struct N { N *next; }; struct S { int a,b; N *head; }; N *func_003C26A8(S *s) { N *n=s->head; if(n==0) return 0; s->head=n->next; return n; }

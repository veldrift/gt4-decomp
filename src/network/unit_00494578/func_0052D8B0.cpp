struct Node { int size; Node *next; };
struct Queue { int a; Node *cursor; Node *end; int count; int ready; Node *head; };
extern "C" int func_0052E120(Queue *);
extern "C" int func_0052E300(Queue *,Node *,Node **);
extern "C" int func_0052E3B8(Queue *);
extern "C" int func_0052E428(Queue *);
extern "C" int func_0052D8B0(Queue *q,Node *n) {
 Node *prev=0;
 if (!q || !q->ready || !q->head || !q->end) return 2;
 if (!n) return 2;
 if (n != q->head) {
  int r=func_0052E300(q,n,&prev);
  if(r) return r;
  Node *p=prev;
  p->next=n->next;
  q->count=(q->count-((n->size+3)&~3)-8);
 } else {
  Node *next=n->next;
  if (!next) {
   q->a=0; q->cursor=0; q->count=0;
   int r=func_0052E120(q);
   if(r) return r;
  } else {
   q->head=next;
   q->count=q->count-((n->size+3)&~3)-8;
  }
 }
 int r=func_0052E3B8(q);
 if(r) return r;
 return func_0052E428(q);
}

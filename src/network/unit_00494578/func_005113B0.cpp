struct Node { int value; Node *prev,*next; unsigned key; };
struct Bucket { int count; Node *head; };
struct Tbl {
 char pad[0x3c]; void *context; int pad40; int x44; Bucket *buckets;
 int (*hash)(void *,int,int); int pad50; void (*update)(int,int,int);
 int count; Node *cache; int x60; void *pool; int pad68; Tbl *parent;
};
extern "C" Node *func_005122A8(void *,int);
extern "C" int func_00512350(void *,void *);
extern "C" int func_005112D0(Tbl *,int) throw();
extern "C" int func_005113B0(Tbl *t,int value,unsigned key) {
 if(!t || !value) return 1;
 t->update(value,t->x44,t->x60);
 int idx=t->hash(t->context,t->x60,t->x44);
 Node *n=func_005122A8(t->pool,value);
 if(!n) return 2;
 Bucket *base=t->buckets;
 n->key=key;
 Node *prev=0;
 Node *cur=((Bucket *)(idx*8+(int)base))->head;
 while(cur && cur->key<key) { prev=cur;cur=prev->next; }
 if(cur) {
  if(cur->key==key) {func_00512350(t->pool,n);return 9;}
  if(!prev) {((Bucket *)(idx*8+(int)base))->head=n;n->prev=0;}
  else {prev->next=n;n->prev=prev;}
  cur->prev=n;n->next=cur;
 } else {
  if(prev) {prev->next=n;n->next=0;n->prev=prev;}
  else {((Bucket *)(idx*8+(int)base))->head=n;n->prev=0;n->next=0;}
 }
 t->count++;
 ((Bucket *)(idx*8+(int)base))->count++;
 if(t->parent) func_005112D0(t->parent,value);
 return 0;
}

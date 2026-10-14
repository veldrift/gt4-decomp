/* compiler: ee-gcc2.96-no-strict-aliasing */
struct N { char pad[0x54]; int owner; int prev,next; };
struct S { char pad[0xa0]; int count; N *head,*tail; };
extern char D_0082AA00[];
extern "C" void func_005769F0(void *);
extern "C" void func_00576A28(void *);
extern "C" unsigned char *func_00305548(unsigned char *);
extern "C" int func_00306130(S *,int);
extern "C" void func_003285F8(N *);
extern "C" void func_00206C28(S *self,int first,N *last) {
 if (first) {
  func_005769F0(D_0082AA00);
  N *p=(N *)((N *)first)->prev;
  N *q=(N *)last->next;
  if (p) p->next=(int)q; else self->head=q;
  if (q) q->prev=(int)p; else self->tail=p;
  last->next=0;
  N *n=(N *)first;
  while (n) {
   n->owner=0;
   --self->count;
   n=(N *)n->next;
  }
  last=(N *)first;
  func_00576A28(D_0082AA00);
  while (last) {
   N *next=(N *)last->next;
   last->prev=0;
   last->next=0;
   func_00306130(self,(int)func_00305548((unsigned char *)last));
   func_003285F8(last);
   last=next;
  }
 }
}

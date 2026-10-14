/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Range { void *ptr; unsigned int size; };
struct Item { char pad0[0xC]; void *handle; int busy; int done; int active; char data[0x1C]; int lock; int pad3C; Range range; };
struct Node { Item *item; int pad; Node *next; };
struct Obj { char pad[0x48]; Node *head; };
extern "C" void func_00576788(Obj *);
extern "C" void func_005767C0(Obj *);
extern "C" int func_00538B08(void **, unsigned long);
extern "C" int func_00538C68(Range *);
extern "C" void func_00576100(int *);
extern "C" void func_00576140(int *);
extern "C" void func_0057B348(void *, void *, int, int);
extern "C" void func_0057B368(void *);
extern "C" int func_0052A270(void *, int);
extern "C" Item *func_00503ED0(Obj *, int) throw();
extern "C" void func_00503F18(Obj *, int) throw();
struct ObjGuard { Obj *p; ObjGuard(Obj *q):p(q) {func_00576788(p);} ~ObjGuard(){func_005767C0(p);} };
struct Guard { int *p; void lock(int *q){p=q;func_00576100(q);} void unlock(int *q){func_00576140(q);} };
static inline void fill(Guard *guard, int *lock, void *data, void *ptr, int size) {
 guard->lock(lock);
 func_0057B348(data,ptr,1,size);
 guard->unlock(lock);
}
extern "C" void func_00503FD0(int enabled, int value, unsigned int kind, int unused, Obj *obj) {
 if (!enabled) return;
 ObjGuard outer(obj);
 Guard guard;
 Item *it; Range *range; int *lock; void *data; int one;
 switch(kind) {
 case 0: {
  Node *n=obj->head;
  if(n) do {
   it=n->item;
   if(it->busy==0) {
    range=&it->range;
    if(func_00538B08(&range->ptr,it->range.size)) break;
    lock=&it->lock;
    void *ptr=range->ptr;
    int size=range->size;
    data=it->data;
    one=1;
    fill(&guard,lock,data,ptr,size);
    void *handle=it->handle;
    it->busy=value;
    if(func_0052A270(handle,value)!=0) goto fail;
    it->done=one;
    break;
   }
   n=n->next;
  } while(n);
  break;
 }
 case 1: {
  Item *r=func_00503ED0(obj,value);
  if(r) r->active=1;
  break;
 }
 case 2: func_00503F18(obj,value); break;
 case 3: func_00503F18(obj,value); break;
 case 4: func_00503F18(obj,value); break;
 fail:
  func_00538C68(range);
  guard.lock(lock);
  func_0057B368(data);
  guard.unlock(lock);
  break;
 case 5: func_00503F18(obj,value); break;
 }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
extern char D_00842490[];
extern "C" void func_00576788(void*);
extern "C" void func_005767C0(void*);
extern "C" char *func_00329050(void*,unsigned);
extern "C" void *func_003294C0();
struct Guard{void *p;Guard(void*x):p(x){func_00576788(p);}~Guard(){func_005767C0(p);}};
struct Obj{char *vt;};
extern Obj *D_0084248C;
struct CountEntry{short delta,index;unsigned (*fn)(void*);};
struct ItemEntry{short delta,index;void *(*fn)(void*,unsigned);};
static inline unsigned count(Obj*p){CountEntry *e=(CountEntry*)(p->vt+0x18);return e->fn((char*)p+e->delta);}
static inline void *item(Obj*p,unsigned i){ItemEntry*e=(ItemEntry*)(p->vt+0x10);return e->fn((char*)p+e->delta,i);}
extern "C" char *func_00326588(unsigned size){
Guard lock(D_00842490);
unsigned rounded=(size+3)&~3U;
unsigned index=(rounded>>2)-1;
void *p;
if(index<count(D_0084248C)) {
p=item(D_0084248C,index);
return func_00329050(p,rounded);
}
p=func_003294C0();
return func_00329050(p,rounded);
}

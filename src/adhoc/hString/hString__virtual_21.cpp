/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
struct Heap { const char *name; };
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *, int, int, const char *);
extern "C" void func_003285A8(void *);
extern "C" void func_003285F8(void *);
extern "C" void func_00312370(void *, void *) throw();
extern "C" void func_00312318(void *, int) throw();
extern "C" void func_00314B20(void *, void *);
struct Rep { u32 len, cap, ref, selfish;
 static void operator delete(void *p,u32 n) { func_00326798(p,n,4,func_005C11A8()->name); }
 void release() { if(--ref==0) operator delete(this,sizeof(Rep)+cap); }
};
struct Str { char *p; char pad[12]; };
struct H { void *p; char pad[12]; };
extern Rep D_00659FA8;
extern "C" char *func_005C2560(Rep *);
extern "C" Str *func_005CE388(Str *, u32, u32, const Str *, u32, u32);
struct Entry { short delta, idx; void *fn; };
static inline void strcall(Str *r, void *o) {
 Entry *e=(Entry *)(*(char **)((char *)o+4)+0x18);
 ((void (*)(Str *,void *))e->fn)(r,(char *)o+e->delta);
}
static inline int intcall(void *o) {
 Entry *e=(Entry *)(*(char **)((char *)o+4)+0x58);
 return ((int (*)(void *))e->fn)((char *)o+e->delta);
}
static inline void assign(H *d, H *s) {
 if (d != s) { void *v=s->p; if(v)func_003285A8(v); if(d->p)func_003285F8(d->p); d->p=v; }
}
static inline void release(Str *s) {
 Rep *r=(Rep *)s->p-1; r->release();
}
static inline void init(Str *s) {
 char *v;
 if(D_00659FA8.selfish) v=func_005C2560(&D_00659FA8);
 else { ++D_00659FA8.ref; v=(char *)(&D_00659FA8+1); }
 s->p=v;
}
static inline void copystr(Str *d,const Str *s) {
 char *v=s->p; Rep *r=(Rep *)v-1;
 if(r->selfish) v=func_005C2560(r); else ++r->ref;
 d->p=v;
}
extern "C" void hString__virtual_21(void *self,H *out,H *a,void *unused,H *b) {
 H result;
 Str str;
 int spare[12];
 Str sa;
 Str sb;
 Str sc;
 Str *pa=&sa;
 strcall(pa,a->p);
 Str *pb=&sb;
 strcall(pb,b->p);
 Str *pc=&sc;
 copystr(pc,pa);
 func_005CE388(pc,((Rep *)pc->p-1)->len,0,pb,0,-1);
 Str *ps=&str;
 copystr(ps,pc);
 release(pc);
 func_00314B20(&result,ps);
 assign(out,&result);
 func_00312318(&result,2);
 release(ps);
 release(pb);
 release(pa);
}

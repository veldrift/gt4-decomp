/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { unsigned int len,cap,ref,sel; };
struct String { char *p; };
struct Heap { const char *name; };
struct E { short delta,index; void (*fn)(void *,int); };
struct E0 { short delta,index; void (*fn)(void *); };
struct Context { int a0; char *vt; };
struct Face { char pad[0x54]; float x,y; char pad5c[8]; };
struct Widget { char pad[0xa0]; Face face; int a104,a108,a10c,a110,a114; float x,y; };
extern "C" void mWidget__virtual_70(Widget *,Context *,int);
extern "C" void func_002472B8(Face *,Context *);
extern "C" String *func_002457E8(String *,Widget *,int,int) throw();
extern "C" int func_00245568(Widget *) throw();
extern "C" void func_00245C90(Widget *,Context *) throw();
extern "C" String *func_002B74B0(String *,int);
extern "C" void func_00231170(Context *,const String *);
extern "C" void func_00247428(Face *);
extern "C" Heap *func_005C11A8();
extern "C" void func_00326798(void *,unsigned int,unsigned int,const char *);
static inline void deallocate(void *p,unsigned int n) {
 func_00326798(p,n,4,func_005C11A8()->name);
}
static inline void destroy(String *s) {
 Rep *r=(Rep *)(s->p-16);
 if(--r->ref==0) {
 deallocate(r,r->cap+16);
 }
}
extern "C" void mTextFace__virtual_70(Widget *w,Context *c,int enabled) {
 String str;
 mWidget__virtual_70(w,c,0);
 if(enabled) {
 Face *f=&w->face;
 E *e=(E *)(c->vt+0x1c0); e->fn((char *)c+e->delta,w->a108);
 func_002472B8(f,c);
 int a=w->a10c;
 if(a>=0 && w->a110>=0) {
 func_002457E8(&str,w,a,w->a110);
 func_00231170(c,&str);
 destroy(&str);
 } else if(func_00245568(w)) {
 func_00245C90(w,c);
 } else {
 func_002B74B0(&str,w->a104);
 func_00231170(c,&str);
 destroy(&str);
 }
 func_00247428(f);
 w->x=f->x; w->y=f->y;
 E0 *e0=(E0 *)(c->vt+0x1c8); e0->fn((char *)c+e0->delta);
 }
}

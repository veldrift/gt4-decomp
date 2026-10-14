/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { int len,cap,ref,sel; };
struct Obj { int head; void *vt; int a,b,c; char storage[0xb0]; char *str; };
extern char mGamePort__vtable[];
extern char *D_00836448;
extern "C" void *hObject__structor_0(void *);
extern "C" char *func_005C2560(Rep *);
extern "C" void func_0055F250(void *,int,void *,void *,void *);
extern "C" void mGamePort__structor_0(Obj *o) {
    char **dst = &o->str;
    hObject__structor_0(o);
    o->vt = mGamePort__vtable;
    o->c = 0;
    char *p = D_00836448;
    Rep *r = (Rep *)(p-16);
    char *out = p;
    if (r->sel) out = func_005C2560(r);
    else r->ref++;
    *dst = out;
    return func_0055F250(o->storage,0,0,0,0);
}

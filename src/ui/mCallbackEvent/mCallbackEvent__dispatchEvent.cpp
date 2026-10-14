/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { int pad; char *vt; char pad8[8]; int f10,f14; char pad18[8]; void (*cb)(int,int); };
struct E { short delta,index; void *(*fn)(void *); };
extern char D_0069AAB8[],D_0069AAC0[],D_0069AAD8[];
extern "C" void func_005D4AD8(const char *,...);
extern "C" const char *hModule__getName(void *);
extern "C" int func_0028EA08(void *);
extern "C" int func_0028EA18(void *);
extern "C" int mEvent__propagateEvent(void *,int,int);
static inline void *vcall(O *o) {
    E *e = (E *)(o->vt+0x50);
    return e->fn((char *)o+e->delta);
}
extern "C" int mCallbackEvent__dispatchEvent(O *o) {
    func_005D4AD8(D_0069AAB8);
    const char *name = hModule__getName(vcall(o));
    func_005D4AD8(D_0069AAC0,name,o->f14,o->f10);
    if (func_0028EA18(o) != 0 && o->cb != 0) {
        int t = func_0028EA08(o);
        o->cb(t,func_0028EA18(o));
    }
    func_005D4AD8(D_0069AAD8);
    return 1;
}

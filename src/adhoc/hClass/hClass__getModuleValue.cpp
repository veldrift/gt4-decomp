/* compiler: ee-gcc2.96-no-strict-aliasing */
extern int D_0083CE50;
struct VEntry { short delta, index; void (*fn)(void *, int *, int *); };
struct Obj { int unk0; char *vt; };
extern "C" void hModule__findModuleValue(void *,int *,int *);
extern "C" Obj *func_002F3A28(void *);
extern "C" void func_00305F80(void *,int *,int *);
extern "C" void hClass__getModuleValue(void *self,int *a,int *b) {
    hModule__findModuleValue(self,a,b);
    if (*a) return;
    if (*b==D_0083CE50) return;
    Obj *p=func_002F3A28(self);
    if(p) {
        VEntry *e=(VEntry *)(p->vt+0x198);
        e->fn((char *)p+e->delta,a,b);
        func_00305F80(self,b,a);
    }
}

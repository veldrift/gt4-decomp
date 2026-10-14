extern "C" void hModule__getModuleValue();
extern "C" int func_003284E8(void *);
extern "C" void func_00305F80(void *, int, int *);
struct Obj { char pad0[4]; char *vt; };
struct Ent { short delta, index; void (*fn)(void *, int *, int); };
static inline Obj *get(Obj **p) {
    int empty = 0;
    if (*p == 0 || func_003284E8(*p) == 0) empty = 1;
    Obj *r = 0;
    if (empty == 0) r = *p;
    return r;
}
extern "C" void mSceneViewFace__virtual_50(void *self, int *arg1, int arg2) {
    hModule__getModuleValue();
    if (*arg1 == 0) {
        Obj **p = (Obj **)((char *)self + 0x2c);
        if (get(p)) {
            Obj *obj = get(p);
            Ent *e = (Ent *)(obj->vt + 0x198);
            e->fn((char *)obj + e->delta, arg1, arg2);
            func_00305F80(self, arg2, arg1);
        }
    }
}

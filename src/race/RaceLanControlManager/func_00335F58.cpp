/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Target { char pad[0xF8]; int value; };
struct Child { char pad[0x64]; char *vt; };
struct VEntry { short delta, index; int (*fn)(void *); };
static inline int query(Child *child) {
    VEntry *e = (VEntry *)(child->vt + 0x318);
    return e->fn((char *)child + e->delta);
}
struct Obj {
    char pad[0x60]; Target *target; Child *child;
    int f68, f6c, f70, f74, f78, f7c, f80;
};
extern "C" void RaceLanControlManager__virtual_03(Obj *);
extern "C" void func_00335F58(Obj *o, Target *t) {
    o->target = t;
    int r = query(o->child) != 0;
    o->f68 = r;
    o->f6c = 0;
    o->f70 = 0;
    o->f74 = 0;
    o->f78 = ~o->target->value == 0;
    o->f7c = 1;
    o->f80 = 0;
    RaceLanControlManager__virtual_03(o);
}

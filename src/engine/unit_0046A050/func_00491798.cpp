/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj {
    int pad0;
    Obj *self;
    int *f8;
    int pad[1];
    unsigned short count;
    short pad12;
    int *f14;
    int *f18;
};
extern "C" void func_00491E80(int);
extern "C" void func_00491990(int, int, int);
static inline void fix(int *p, int d) { if (*p) *p = *p + d; }
extern "C" void func_00491798(Obj *o) {
    int d = (char *)o - (char *)o->self;
    if (d != 0) {
        o->self = o;
        fix((int *)&o->f8, d);
        fix((int *)&o->f18, d);
        fix((int *)&o->f14, d);
        for (int i = 0; i < o->count; ) {
            int off = i * 4;
            i++;
            if (*(int *)(off + (int)o->f14) != 0) {
                int *p = (int *)((int)o->f18 + off);
                fix(p, d);
                func_00491E80(*(int *)(off + (int)o->f18));
                fix((int *)((int)o->f14 + off), d);
                func_00491990(*(int *)(off + (int)o->f14), d, *(int *)(off + (int)o->f18));
            }
        }
    }
}

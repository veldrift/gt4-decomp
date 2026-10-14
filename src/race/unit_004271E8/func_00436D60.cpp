struct T { int x[11]; };
struct Obj { char pad0[0x14]; int f14; char pad1[0xC]; T t; };
extern "C" int func_0057F238(const char *, const char *);
extern T D_006A6188;
extern T D_006A61B8;
extern T D_006A61E8;
extern char D_006A5958[];

extern "C" void func_00436D60(Obj *o, const char *name) {
    T *p = &D_006A6188;
    if (func_0057F238(name, D_006A5958) == 0) {
        p = &D_006A61E8;
    } else if (o->f14 != 0) {
        p = &D_006A61B8;
    }
    o->t = *p;
}

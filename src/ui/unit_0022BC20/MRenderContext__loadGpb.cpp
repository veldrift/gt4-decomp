struct Slot { short delta; short pad; void (*fn)(void *, unsigned char *, unsigned char *); };
struct Obj { int pad; Slot *vt; };
struct Owner { char pad[0x10]; Obj *target; };
extern "C" void func_0022ACC8(void *, int) throw();
extern "C" int func_0022AD20(void *, void *) throw();
extern "C" void func_00312318(void *, int);
extern "C" void func_00312370(void *, void *);
extern "C" unsigned char *func_00314920(unsigned char *);
extern "C" void MRenderContext__loadGpb(void *arg0, void *arg1, int n, char *args) {
    unsigned char *a[4];
    unsigned char *b[4];
    Owner *c[4];
    if (n >= 2) {
        func_00312370(a, args);
        unsigned char **pb = b;
        func_00312370(pb, args + 4);
        Owner **pc = c;
        func_0022AD20(pc, arg1);
        Obj *target = pc[0]->target;
        func_0022ACC8(pc, 2);
        unsigned char *x = func_00314920(a[0]);
        unsigned char *y = func_00314920(pb[0]);
        Slot *slot = target->vt + 54;
        slot->fn((char *)target + slot->delta, x, y);
        func_00312318(pb, 2);
        func_00312318(a, 2);
    }
}

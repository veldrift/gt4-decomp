/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VObj { int data; char *vtbl; };
struct VEntryI { short delta; short index; int (*fn)(void *); };
struct VEntryF { short delta; short index; float (*fn)(void *); };
static inline int vi(VObj *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}
static inline float vf(VObj *o) {
    VEntryF *e = (VEntryF *)(o->vtbl + 0x60);
    return e->fn((char *)o + e->delta);
}
extern "C" void func_00204D30(void *, int) throw();
extern "C" void func_00204D88(void *, void *) throw();
extern "C" void func_00207B70(void *, int, int, float, float);
extern "C" void MComposite__arrangeColAuto(void *arg0, void *arg1, int arg2, VObj **arg3) {
    void *buf[4];
    if (arg2 >= 3) {
        int count = vi(arg3[0]);
        float border = vf(arg3[1]);
        float gap = vf(arg3[2]);
        func_00204D88(buf, arg1);
        func_00207B70(buf[0], 1, count, border, gap);
        func_00204D30(buf, 2);
    }
}

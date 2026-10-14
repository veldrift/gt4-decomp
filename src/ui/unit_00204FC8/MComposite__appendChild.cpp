/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VObj { int data; char *vtbl; };
struct VEntryV { short delta; short index; void (*fn)(void *, int, int); };
extern "C" void func_00204D30(void *, int) throw();
extern "C" void func_00204D88(void *, void *) throw();
extern "C" void func_0022ACC8(void *, int);
extern "C" void func_0022AD20(void *, void *);
extern "C" void func_002550B8(void *, int);
extern "C" void func_00255110(void *, void *);
extern "C" void MComposite__appendChild(void *arg0, void *arg1, int arg2, void *arg3) {
    VObj *buf[4];
    int c[4];
    int a[4];
    int b[4];
    int small = arg2 < 2;
    if (arg2 == 1) {
        func_00204D88(buf, arg1);
        int *pc = c;
        func_00255110(pc, arg3);
        VObj *o = buf[0];
        VEntryV *e = (VEntryV *)(o->vtbl + 0x320);
        e->fn((char *)o + e->delta, 0, *pc);
        func_002550B8(pc, 2);
        func_00204D30(buf, 2);
    } else if (!small) {
        func_00204D88(buf, arg1);
        int *pa = a;
        func_0022AD20(pa, arg3);
        int *pb = b;
        func_00255110(pb, (char *)arg3 + 4);
        VObj *o = buf[0];
        VEntryV *e = (VEntryV *)(o->vtbl + 0x320);
        e->fn((char *)o + e->delta, *pa, *pb);
        func_002550B8(pb, 2);
        func_0022ACC8(pa, 2);
        func_00204D30(buf, 2);
    }
}

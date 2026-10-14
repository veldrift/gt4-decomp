/* compiler: ee-gcc2.96-no-strict-aliasing */
struct VObj { int data; char *vtbl; };
struct VEntryI { short delta; short index; int (*fn)(void *); };
static inline int vi(VObj *o) {
    VEntryI *e = (VEntryI *)(o->vtbl + 0x58);
    return e->fn((char *)o + e->delta);
}
extern "C" void func_00204D30(void *, int) throw();
extern "C" void func_00204D88(void *, void *) throw();
extern "C" int func_00208470(int, int);
extern "C" void func_00255088(void *, void *);
extern "C" void func_002550B8(void *, int);
extern "C" void func_003285A8(int);
extern "C" void func_003285F8(int);
extern "C" void MComposite__getChild(int *arg0, void *arg1, int arg2, VObj **arg3) {
    int buf0[4];
    int buf1[4];
    int temp;
    if (arg2 > 0) {
        func_00204D88(buf0, arg1);
        int self = buf0[0];
        int *ptemp = &temp;
        temp = func_00208470(self, vi(arg3[0]));
        int *p1 = buf1;
        func_00255088(p1, ptemp);
        if (arg0 != p1) {
            int newVal = *p1;
            if (newVal != 0) func_003285A8(newVal);
            int oldVal = *arg0;
            if (oldVal != 0) func_003285F8(oldVal);
            *arg0 = newVal;
        }
        func_002550B8(p1, 2);
        func_00204D30(buf0, 2);
    }
}

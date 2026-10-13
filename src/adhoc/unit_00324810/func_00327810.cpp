typedef int s32;

extern "C" void func_00576788(void *a0);
extern "C" void func_005767C0(void *a0);
extern "C" void func_005F2020(void *, void *);
extern "C" void *func_005F2690(void);
extern "C" void func_00326798(void *, s32, s32, const void *);
extern "C" void func_00574DA8(void *, s32);
extern "C" void func_005C1628(void *);

static inline void member_clear(char *m) {
    if (*(void **)(m + 0x8) != 0) {
        func_005F2020(m, *(void **)((char *)*(void **)(m + 0x4) + 0x4));
        *(void **)((char *)*(void **)(m + 0x4) + 0x8) = *(void **)(m + 0x4);
        *(void **)((char *)*(void **)(m + 0x4) + 0x4) = 0x0;
        *(void **)((char *)*(void **)(m + 0x4) + 0xc) = *(void **)(m + 0x4);
        *(void **)(m + 0x8) = 0x0;
    }
}

extern "C" void func_00327810(void *arg0, s32 arg1) {
    char *m = (char *)arg0 + 0x30;
    func_00576788(arg0);
    member_clear(m);
    func_005767C0(arg0);
    member_clear(m);
    void *p0 = *(void **)(m + 0x4);
    void *r = func_005F2690();
    func_00326798(p0, 0x18, 0x4, *(void **)r);
    func_00574DA8(arg0, 0x2);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}

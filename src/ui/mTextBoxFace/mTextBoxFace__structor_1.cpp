typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

extern char mTextBoxFace__vtable[];
extern char D_0069D188[];

extern "C" void func_002270F8(void *, s32 *);
extern "C" void func_00227128(void *, s32);
extern "C" void func_00203118(void *, s32);
extern "C" void mScrollable__structor_1(void *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" void func_003285A8(s32);
extern "C" void func_003285F8(s32);
extern "C" struct S00659988 *func_005C11A8(void);

static inline void str_rel(char *p) {
    Rep *q = (Rep *)(p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void mTextBoxFace__structor_1(char *arg0, s32 arg1) {
    s32 buf0[4];
    s32 v;
    s32 newVal;
    s32 oldVal;
    s32 *dst;
    s32 *s2;
    s32 *s4;

    dst = (s32 *)(arg0 + 0xBC);
    *(char **)(arg0 + 4) = mTextBoxFace__vtable;
    v = 0;
    func_002270F8(buf0, &v);
    if (dst != buf0) {
        newVal = buf0[0];
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = dst[0];
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        dst[0] = newVal;
    }
    func_00227128(buf0, 2);
    if (arg0 != (char *)-0x12C) {
        s2 = (s32 *)(arg0 + 0x32C);
        s4 = (s32 *)(arg0 + 0x12C);
        if (s4 != s2) {
            do {
                s2 -= 1;
                str_rel((char *)*s2);
            } while (s4 != s2);
        }
    }
    func_00203118(arg0 + 0x100, 2);
    s2 = (s32 *)(arg0 + 0xC0);
    str_rel(*(char **)(arg0 + 0xD0));
    func_00203118(s2, 2);
    func_00227128(dst, 2);
    mScrollable__structor_1(arg0, 0);
    if (arg1 & 1) {
        func_00326798(arg0, 0x3C8, 4, D_0069D188);
    }
}

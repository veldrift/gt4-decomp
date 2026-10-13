typedef int s32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct Str {
    char *p;
    char pad[0xC];
};

struct S00659988 {
    const char *name;
};

extern Rep D_00659FA8;

extern "C" void func_0015AA68(void *arg0, int arg1);
extern "C" void func_0015AAC0(void *arg0, void *arg1);
extern "C" void func_002FC870(void *arg0, int arg1);
extern "C" void func_002FC8C8(void *arg0, void *arg1);
extern "C" s32 func_002FE250(void *arg0);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00314B20(void *arg0, void *arg1);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_003285A8(s32 p);
extern "C" void func_003285F8(s32 p);
extern "C" void func_0042E660(void *date, char *buf, s32 size);
extern "C" void *func_00433598(s32 arg0, s32 arg1);
extern "C" s32 func_0057F260(void *s);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *r);
extern "C" void *func_005C2630(void *s, s32 pos, s32 n1, void *s2, s32 n2);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" void func_0015B1B0(s32 *arg0, void *arg1, s32 arg2, void *arg3) {
    s32 buf0[4];
    char buf1[0x80];
    s32 buf2[4];
    Str s3;
    Str *p_s3;
    s32 *p_s1;
    s32 v_s0;
    s32 newVal;
    s32 oldVal;

    v_s0 = 0;
    if (arg2 > 0) {
        func_002FC8C8(buf0, arg3);
        v_s0 = func_002FE250((void *)buf0[0]);
        func_002FC870(buf0, 2);
    }
    func_0015AAC0(buf0, arg1);
    func_0042E660(func_00433598(*(s32 *)((char *)buf0[0] + 0x10), v_s0), buf1, 0x80);
    p_s3 = &s3;
    {
        Rep *r = &D_00659FA8;
        char *d;
        if (r->sel != 0) {
            d = func_005C2560(r);
        } else {
            d = (char *)(r + 1);
            r->ref++;
        }
        p_s3->p = d;
    }
    func_005C2630(p_s3, 0, -0x1, buf1, func_0057F260(buf1));
    p_s1 = buf2;
    func_00314B20(p_s1, p_s3);
    if (arg0 != p_s1) {
        newVal = *p_s1;
        if (newVal != 0) {
            func_003285A8(newVal);
        }
        oldVal = *arg0;
        if (oldVal != 0) {
            func_003285F8(oldVal);
        }
        *arg0 = newVal;
    }
    func_00312318(p_s1, 0x2);
    str_release(p_s3);
    func_0015AA68(buf0, 2);
}

typedef int s32;
typedef unsigned char u8;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct SS {
    char *p;
    s32 pad[3];
};

extern "C" void func_001FEF50(void *arg0, int arg1);
extern "C" void *func_001FEFA8(void *arg0, void *arg1);
extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" u8 *func_00314920(u8 *arg0);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *src);

extern "C" void MActor__set_name(void *arg0, void *arg1, s32 arg2, void *arg3) {
    SS tmp;
    SS ss;
    if (arg2 > 0) {
        SS *ps;
        func_00312370(&tmp, arg3);
        ps = &ss;
        func_001FEFA8(ps, arg1);
        s32 *fld = (s32 *)((char *)ps->p + 0x10);
        u8 *s3 = func_00314920((u8 *)tmp.p);
        if ((void *)s3 != (void *)fld) {
            {
                Rep *q = (Rep *)(*fld - 0x10);
                if (--q->ref == 0) {
                    s32 cap = q->cap + 0x10;
                    func_00326798(q, cap, 4, func_005C11A8()->name);
                }
            }
            {
                s32 p = *(s32 *)s3;
                Rep *r = (Rep *)(p - 0x10);
                s32 d = p;
                if (r->sel != 0) {
                    d = (s32)func_005C2560(r);
                } else {
                    r->ref++;
                }
                *fld = d;
            }
        }
        func_001FEF50(ps, 2);
        func_00312318(&tmp, 2);
    }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
struct Self {
    char pad0[0x104];
    Str s;
};

extern Rep D_00659FA8;

extern "C" void func_00249FF0(Self *, s32) throw();
extern "C" void mTextFace__virtual_68(Self *, s32);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);

extern "C" void mToolTipFace__virtual_68(Self *self, s32 arg1) {
    Str tmp;
    Str *dst = &self->s;
    func_00249FF0(self, arg1);
    {
        Rep *r = &D_00659FA8;
        char *p;
        if (r->sel != 0) {
            p = func_005C2560(r);
        } else {
            p = (char *)(r + 1);
            r->ref++;
        }
        tmp.p = p;
    }
    if (&tmp != dst) {
        {
            Rep *q = (Rep *)(*(s32 *)&dst->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        {
            s32 p = *(s32 *)&tmp.p;
            Rep *r = (Rep *)(p - 0x10);
            s32 d = p;
            if (r->sel != 0) {
                d = (s32)func_005C2560(r);
            } else {
                r->ref++;
            }
            *(s32 *)&dst->p = d;
        }
    }
    {
        Rep *q = (Rep *)(tmp.p - 0x10);
        if (--q->ref == 0) {
            s32 cap = q->cap + 0x10;
            func_00326798(q, cap, 4, func_005C11A8()->name);
        }
    }
    mTextFace__virtual_68(self, arg1);
}

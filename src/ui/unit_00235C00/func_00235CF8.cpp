/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Rep { s32 len; s32 cap; s32 ref; s32 sel; };
struct S00659988 { const char *name; };
struct Str { char *p; };
struct Obj {
    char pad0[0xEC];
    void *ec;
};

extern Rep D_00659FA8;

extern "C" char *func_00235C00(Obj *) throw();
extern "C" void mToolTipFace__setKey(void *, void *);
extern "C" void func_00249EE8(void *, Str *);
extern "C" s32 func_00266268(void *);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" S00659988 *func_005C11A8(void);
extern "C" char *func_005C2560(Rep *);

extern "C" void func_00235CF8(Obj *self) {
    Str tmp;
    if (func_00235C00(self) != 0) {
        if (self->ec != 0) {
            if (func_00266268(func_00235C00(self)) != 0) {
                mToolTipFace__setKey(self->ec, func_00235C00(self) + 0x8C);
                return;
            }
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
            func_00249EE8(self->ec, &tmp);
            {
                Rep *q = (Rep *)(tmp.p - 0x10);
                if (--q->ref == 0) {
                    s32 cap = q->cap + 0x10;
                    func_00326798(q, cap, 4, func_005C11A8()->name);
                }
            }

        }
    } else if (self->ec != 0) {
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
        func_00249EE8(self->ec, &tmp);
        {
            Rep *q = (Rep *)(tmp.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }

    }
}

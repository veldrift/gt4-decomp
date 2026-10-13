typedef int s32;
typedef unsigned int u32;

struct Rep {
    s32 len;
    s32 cap;
    s32 ref;
    s32 sel;
};

struct S00659988 {
    const char *name;
};

struct Str {
    char *p;
};

struct Self {
    char pad0[0x2C8];
    Str s;
    s32 f2CC;
    char pad1[0x308 - 0x2CC - 4];
    u32 f308;
};

extern "C" char *func_005C2560(Rep *r);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" void func_002BE9E8(Self *self, Str *src) {
    Str *dst = &self->s;
    if (src != dst) {
        {
            Rep *q = (Rep *)(*(s32 *)&dst->p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        {
            s32 p = *(s32 *)&src->p;
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
    u32 fl = self->f308;
    self->f2CC = 0;
    self->f308 = (fl & ~0x200u) | ((~(fl >> 9) & 1u) << 9);
}

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
    char pad0[0x2B8];
    Str s;
    s32 n2BC;
    char pad1[0x308 - 0x2BC - 4];
    u32 flags;
};

extern "C" char *func_005C2560(Rep *r);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_00265F48(Self *self, s32 arg1);

extern "C" void func_002BE800(Self *self, Str *src) {
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
    u32 f = self->flags;
    self->n2BC = 0;
    u32 bit = (~(f >> 5)) & 1u;
    self->flags = (f & ~0x20u) | (bit << 5);
    func_00265F48(self, 0);
}

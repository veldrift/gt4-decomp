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

struct Str {
    char *p;
};

struct Self {
    Str s;
    s32 f4;
    s32 f8;
    s32 fC;
    s32 f10;
    s32 f14;
    s32 f18;
    s32 f1C;
    s32 f20;
};

extern "C" char *func_005C2560(Rep *r);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);

extern "C" Self *func_002212C8(Self *self, Self *src) {
    Self *dst = self;
    if (src != dst) {
        {
            Rep *q = (Rep *)(*(s32 *)&dst->s.p - 0x10);
            if (--q->ref == 0) {
                s32 cap = q->cap + 0x10;
                func_00326798(q, cap, 4, func_005C11A8()->name);
            }
        }
        {
            s32 p = *(s32 *)&src->s.p;
            Rep *r = (Rep *)(p - 0x10);
            s32 d = p;
            if (r->sel != 0) {
                d = (s32)func_005C2560(r);
            } else {
                r->ref++;
            }
            *(s32 *)&dst->s.p = d;
        }
    }
    dst->f4 = src->f4;
    dst->f8 = src->f8;
    dst->fC = src->fC;
    dst->f10 = src->f10;
    dst->f14 = src->f14;
    dst->f20 = src->f20;
    dst->f18 = src->f18;
    dst->f1C = src->f1C;
    return self;
}

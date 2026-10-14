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

struct Obj {
    char pad0[0xA0];
    Str s;
    s32 bc;
    char pad1[0xC];
    u32 c8;
};

extern "C" char *func_005C2560(Rep *r);
extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_00265F48(Obj *arg0, s32 arg1);

extern "C" void func_002939D8(Obj *self, Str *src) {
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
    u32 v = self->c8;
    self->bc = 0;
    self->c8 = (v & 0xFFFFFFF7u) | ((~(v >> 3) & 1u) << 3);
    func_00265F48(self, 0);
}

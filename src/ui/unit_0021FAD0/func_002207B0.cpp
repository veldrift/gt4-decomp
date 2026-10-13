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

struct HStr {
    char *p;
};

extern "C" struct S00659988 *func_005C11A8(void);
extern "C" void func_00326798(void *p, s32 size, s32 align, const char *name);
extern "C" void func_005C1628(void *self);

extern "C" void func_002207B0(struct HStr *self, s32 flags) {
    {
        Rep *q = (Rep *)(self->p - 0x10);
        if (--q->ref == 0) {
            s32 size = q->cap + 0x10;
            func_00326798(q, size, 4, func_005C11A8()->name);
        }
    }
    if (flags & 1) {
        return func_005C1628(self);
    }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
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
extern char D_0069D598[];

extern "C" char *func_005C2560(Rep *);
extern "C" s32 hArray__size(s32 arg0) throw();
extern "C" s32 func_002EFFD0(s32 arg0, char *arg1, s32 arg2, s32 arg3);
extern "C" void func_002FE278(s32 arg0, void *arg1);
extern "C" void func_00326798(void *, s32, s32, const char *);
extern "C" struct S00659988 *func_005C11A8(void);

static inline void str_release(Str *s) {
    Rep *q = (Rep *)(s->p - 0x10);
    if (--q->ref == 0) {
        s32 size = q->cap + 0x10;
        func_00326798(q, size, 4, func_005C11A8()->name);
    }
}

extern "C" s32 func_002EFED8(s32 arg0, s32 arg1, char **arg2) {
    Str sp;
    char *var_a1;
    char *var_a1_2;
    char *obj;
    s32 temp_a3;
    s32 temp_v1;

    {
        Rep *r = &D_00659FA8;
        var_a1 = (char *)(r + 1);
        if (r->sel != 0) {
            var_a1 = func_005C2560(r);
        } else {
            r->ref++;
        }
    }
    sp.p = var_a1;
    temp_a3 = hArray__size(arg1);
    var_a1_2 = D_0069D598;
    temp_v1 = *(s32 *)(*arg2 - 0x10);
    if (temp_v1 != 0) {
        *(*arg2 + temp_v1) = 0;
        var_a1_2 = *arg2;
    }
    func_002FE278(arg0, (void *)(func_002EFFD0(arg1, var_a1_2, 0, temp_a3)));
    str_release(&sp);
    return arg0;
}

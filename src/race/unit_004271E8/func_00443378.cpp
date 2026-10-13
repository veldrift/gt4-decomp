typedef int s32;

extern char D_006882C0[];
extern "C" void func_005C1628(void *);

struct VEntry_vcall_8 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_8(char *o, s32 a0) {
    VEntry_vcall_8 *e = (VEntry_vcall_8 *)(*(char **)(o + 0x8) + 0x8);
    e->fn(o + e->delta, a0);
}

struct VEntry_vcall_68 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_68(char *o, s32 a0) {
    VEntry_vcall_68 *e = (VEntry_vcall_68 *)(*(char **)(o + 0x68) + 0x8);
    e->fn(o + e->delta, a0);
}

struct VEntry_vcall_4 { short delta; short index; void (*fn)(void *, s32); };
static inline void vcall_4(char *o, s32 a0) {
    VEntry_vcall_4 *e = (VEntry_vcall_4 *)(*(char **)(o + 0x4) + 0x8);
    e->fn(o + e->delta, a0);
}

extern "C" void func_00443378(void *arg0, s32 arg1) {
    char *self = (char *)arg0;
    void **var_s1 = (void **)(self + 0x134);
    void **var_s0 = (void **)(self + 0x88);
    s32 i;

    *(void **)(self + 0x1EC) = (void *)D_006882C0;
    i = 0x2A;
    do {
        void *a = *var_s0;
        var_s0 += 1;
        if (a != 0) {
            vcall_8((char *)a, 3);
        }
        void *b = *var_s1;
        var_s1 += 1;
        if (b != 0) {
            vcall_68((char *)b, 3);
        }
        i -= 1;
    } while (i >= 0);

    if (*(void **)(self + 0x1E0) != 0) {
        vcall_8((char *)*(void **)(self + 0x1E0), 3);
    }
    if (*(void **)(self + 0x1E4) != 0) {
        vcall_8((char *)*(void **)(self + 0x1E4), 3);
    }
    if (*(void **)(self + 0x1E8) != 0) {
        vcall_4((char *)*(void **)(self + 0x1E8), 3);
    }
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}

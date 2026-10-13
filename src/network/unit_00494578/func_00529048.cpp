typedef int s32;
typedef unsigned int u32;

struct Obj {
    s32 k;          /* 0x00 */
    char pad0[0x18];
    s32 f1C;        /* 0x1C */
    s32 f20;        /* 0x20 */
    char pad1[0x10];
    s32 f34;        /* 0x34 */
    s32 f38;        /* 0x38 */
};

extern "C" s32 func_00529048(s32 a0, Obj *a1, s32 a2, s32 *a3, s32 *a4, s32 *a5) {
    if (a0 == 0) {
        return 0xD2F2;
    }
    if (a1 == 0) {
        return 0xD2F3;
    }
    if (a1->k != 0xD) {
        return 0xD2F3;
    }
    if (a2 == 0) {
        if (a3 != 0) {
            *a3 = a1->f1C;
        }
        if (a4 != 0) {
            *a4 = a1->f20;
        }
        if (a5 != 0) {
            u32 t = ((u32)a1->f20 * 100u) / (u32)a1->f1C;
            *a5 = (s32)t;
            if (t >= 0x65u) {
                *a5 = 0x64;
            }
        }
        return 0;
    }
    if (a2 != 1) {
        return 2;
    }
    if (a3 != 0) {
        *a3 = a1->f34;
    }
    if (a4 != 0) {
        *a4 = a1->f38;
    }
    if (a5 != 0) {
        u32 t = ((u32)a1->f38 * 100u) / (u32)a1->f34;
        *a5 = (s32)t;
        if (t >= 0x65u) {
            *a5 = 0x64;
        }
    }
    return 0;
}

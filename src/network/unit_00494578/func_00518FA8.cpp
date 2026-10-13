typedef int s32;
typedef unsigned int u32;
typedef signed char s8;

extern "C" {

extern s8 D_00854038[];
s8 *func_00515EC8(u32 arg0);                        /* extern */

struct func_00518FA8_arg0 {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

void func_00518FA8(struct func_00518FA8_arg0 *arg0) {
    s32 i;
    s32 n;
    s32 v;
    s32 k;
    u32 j;
    s8 *p;
    s8 *r;

    if (arg0 != 0) {
        if (arg0->unk8 < 0x1000) {
            n = arg0->unkC;
            i = 0;
            if (n > 0) {
                do {
                    v = i + arg0->unk8;
                    v += (s32)D_00854038;
                    k = 0xE638;
                    p = (s8 *)(k + v);
                    i += 1;
                    if (*p == 0) {
                        *p = 1;
                        n = arg0->unkC;
                    }
                } while (i < n);
            }
        }
        if ((u32)arg0->unk10 < 0x200) {
            j = 0;
            if (arg0->unk14 != 0) {
                do {
                    r = func_00515EC8(j + arg0->unk10);
                    j += 1;
                    if (r != 0) {
                        *r = 1;
                    }
                } while (j < (u32)arg0->unk14);
            }
        }
    }
}

}

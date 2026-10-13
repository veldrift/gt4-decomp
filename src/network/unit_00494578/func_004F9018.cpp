typedef int s32;

struct func_004F9018_arg1 {
    char pad0[8];
    s32 unk8;
};

extern "C" void func_004F9018(char *arg0, struct func_004F9018_arg1 *arg1, s32 arg2) {
    s32 v3 = arg1->unk8;
    s32 off = arg2 * 0x2C + 0x1040;
    char *a1p = arg0 + 8;
    s32 *p = (s32 *)(a1p + off);
    char *a0p = arg0 + off;
    *(s32 *)(a0p + 4) = v3;
    s32 cur = *p;
    if (cur == 0x7FFFFFFF) {
        *p = arg1->unk8;
        return;
    }
    *p = cur + arg1->unk8;
}

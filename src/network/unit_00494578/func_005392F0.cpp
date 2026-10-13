typedef int s32;

extern char D_0064B720[];

extern "C" void func_005392F0(s32 arg0) {
    s32 *p = (s32 *)D_0064B720;
    s32 a = arg0 | 1;
    s32 v = 0x26F;
    s32 k = 0x10DCD;
    p[0x271] = v;
    p[0] = a;
    p++;
    do {
        a *= k;
        v -= 1;
        *p = a;
        p++;
    } while (v != 0);
}

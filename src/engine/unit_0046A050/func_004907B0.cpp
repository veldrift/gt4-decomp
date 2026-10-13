typedef int s32;

extern "C" void func_00491EA8(char *arg0);
extern char D_006AE4C8[];

extern "C" void func_004907B0(char *arg0) {
    s32 one = 1;
    s32 idx = *(s32 *)(arg0 + 0x2C);
    s32 sel = idx >= 2 ? one : idx;
    func_00491EA8(D_006AE4C8 + (sel << 6));
}

typedef int s32;
typedef unsigned int u32;

extern "C" char D_00645570[];

extern "C" s32 func_004FA1A8(void *arg0, s32 arg1);
extern "C" void func_005A48D8(void *dst, s32 c, u32 n);

struct Blob36 {
    char data[0x24];
};

extern "C" s32 func_00336C70(s32 arg0, void *arg1) {
    s32 p = func_004FA1A8(D_00645570, arg0);
    if (p == 0) {
        func_005A48D8(arg1, 0, 0x24);
        return 0;
    }
    *(Blob36 *)arg1 = *(Blob36 *)(p + 0xBA);
    return 1;
}

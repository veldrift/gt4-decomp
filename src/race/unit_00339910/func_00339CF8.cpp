typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void func_0045B620(void *, void *);
extern "C" s32 GT4Model__BinStreamReader__read8u(void *);
extern "C" void func_00339A78(void *, void *);
extern "C" void GT4Model__BinStreamReader__readArray(void *, void *, s32);
extern "C" s32 func_0045B1E0(void *);
extern "C" void func_0045B740(void *, void *);

extern "C" void func_00339CF8(void *arg0, char *arg1, char *arg2) {
    s32 buf[4];
    s32 n;
    char *p0 = arg2;
    char *p8 = arg2 + 0x8;
    char *p54 = arg2 + 0x54;

    func_0045B620(buf, arg0);
    n = GT4Model__BinStreamReader__read8u(arg0);
    func_00339A78(arg0, arg1);
    GT4Model__BinStreamReader__readArray(arg0, arg1 + 0x680, 4);
    GT4Model__BinStreamReader__readArray(arg0, arg1 + 0x684, 4);
    GT4Model__BinStreamReader__readArray(arg0, arg1 + 0x688, 4);
    GT4Model__BinStreamReader__readArray(arg0, arg1 + 0x68C, 4);
    *(s32 *)(arg1 + 0x690) = 0;
    if (n > 0) {
        *(s32 *)(p0 + 0x0) = func_0045B1E0(arg0);
        GT4Model__BinStreamReader__readArray(arg0, p0 + 0x4, 4);
        *(s32 *)(p8 + 0x0) = func_0045B1E0(arg0);
        GT4Model__BinStreamReader__readArray(arg0, p0 + 0xC, 4);
        GT4Model__BinStreamReader__readArray(arg0, p0 + 0x10, 4);
        GT4Model__BinStreamReader__readArray(arg0, p0 + 0x14, 0x40);
        *(s32 *)(p54 + 0x0) = func_0045B1E0(arg0);
        GT4Model__BinStreamReader__readArray(arg0, p0 + 0x58, 8);
    }
    func_0045B740(buf, arg0);
}

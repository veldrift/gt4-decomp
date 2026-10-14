typedef int s32;
typedef unsigned char u8;

extern char D_0069F2E0[];
extern char D_0069F2E8[];
extern "C" void func_0045B4D8(void *, void *, void *);
extern "C" void GT4Model__BinStreamWriter__write8u(void *, s32);
extern "C" void func_00339970(void *, void *) throw();
extern "C" void GT4Model__BinStreamWriter__writeArray(void *, void *, s32);
extern "C" void func_0045AF58(void *, s32);
extern "C" void func_0045B548(void *, void *);

extern "C" void func_00339AD0(void *arg0, char *arg1, char *arg2, s32 arg3) {
    s32 buf0[4];
    func_0045B4D8(buf0, arg0, arg3 ? D_0069F2E0 : D_0069F2E8);
    GT4Model__BinStreamWriter__write8u(arg0, 1);
    func_00339970(arg0, arg1);
    GT4Model__BinStreamWriter__writeArray(arg0, arg1 + 0x680, 4);
    GT4Model__BinStreamWriter__writeArray(arg0, arg1 + 0x684, 4);
    GT4Model__BinStreamWriter__writeArray(arg0, arg1 + 0x688, 4);
    GT4Model__BinStreamWriter__writeArray(arg0, arg1 + 0x68C, 4);
    func_0045AF58(arg0, *(s32 *)(arg2 + 0));
    GT4Model__BinStreamWriter__writeArray(arg0, arg2 + 4, 4);
    func_0045AF58(arg0, *(s32 *)(arg2 + 8));
    GT4Model__BinStreamWriter__writeArray(arg0, arg2 + 0xC, 4);
    GT4Model__BinStreamWriter__writeArray(arg0, arg2 + 0x10, 4);
    GT4Model__BinStreamWriter__writeArray(arg0, arg2 + 0x14, 0x40);
    func_0045AF58(arg0, *(s32 *)(arg2 + 0x54));
    GT4Model__BinStreamWriter__writeArray(arg0, arg2 + 0x58, 8);
    func_0045B548(buf0, arg0);
}

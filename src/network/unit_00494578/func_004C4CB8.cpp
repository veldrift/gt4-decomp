typedef int s32;
typedef unsigned short u16;

extern "C" s32 func_004C4CB8(s32 arg0) {
    u16 t = (u16)arg0;
    if (t == 0) {
        return 0;
    }
    if (t == 0xA1BC) {
        return 1;
    }
    u16 k = (u16)(t + 0x5B5F);
    if (k < 0x53) {
        return (s32)t + (s32)0xFFFF5B61;
    }
    return (s32)0x80001151;
}

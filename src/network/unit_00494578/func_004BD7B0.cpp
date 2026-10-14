/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned short u16;
extern "C" int func_004C4CB8(unsigned short c);
extern "C" s32 func_004C8ED0(u16 *arg0);
extern "C" void func_004C8F68(u16 *a, u16 *b, s32 n);
extern "C" s32 func_004BD7B0(s32 arg0, char *out, u16 *in, s32 mode) {
    u16 buf[64];
    s32 i;
    s32 bad = 0;
    s32 len = func_004C8ED0(in);
    char *p;
    if (len >= 0x40) len = 0x3F;
    if (mode == 1) {
        func_004C8F68(buf, in, len);
        in = buf;
    }
    i = 0;
    if (len > 0) {
        s32 invalid = -1;
        p = out;
        for (i = 0; i < len; i++) {
            s32 c = func_004C4CB8(in[i]);
            if (c < 0) {
                *p = invalid;
                bad = 1;
            } else {
                *p = c;
            }
            p++;
        }
    }
    out[i] = 0;
    return bad;
}

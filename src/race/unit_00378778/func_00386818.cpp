typedef int s32;
typedef float f32;

extern "C" f32 *func_00407208(f32 *dst, const f32 *src);
extern "C" void func_00403BD8(char *obj, f32 *src, f32 t);
extern "C" f32 *func_00407238(f32 *dst, const f32 *a, const f32 *b, f32 t);

extern "C" void *func_00386818(void *arg0, char *arg1, s32 arg2, f32 fparg0) {
    f32 buf[0x40];

    if (fparg0 == 0.0f) {
        func_00407208((f32 *)arg0, (f32 *)(arg1 + 0x160));
    } else if (fparg0 == 1.0f) {
        func_00407208((f32 *)arg0, (f32 *)(arg1 + 0x260));
    } else if (arg2 != 0) {
        func_00407238(buf, (f32 *)(arg1 + 0x160), (f32 *)(arg1 + 0x260), fparg0);
        func_00403BD8(arg1, buf, fparg0);
        func_00407208((f32 *)arg0, buf);
    } else {
        func_00407238((f32 *)arg0, (f32 *)(arg1 + 0x160), (f32 *)(arg1 + 0x260), fparg0);
    }
    return arg0;
}

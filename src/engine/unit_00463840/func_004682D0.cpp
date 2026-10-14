/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
extern "C" void func_004682A0(u16 *, s32, s32, s32) throw();
extern "C" void func_004682D0(u16 *arg0, s32 arg1, s32 n) {
    n -= 4;
    s32 index = n / 8;
    n -= index * 8;
    u32 next = 8;
    s32 first = 64;
    s32 second = 0;
    if (n + 8 >= 9) {
        next = index + 1;
        first = (8 - n) * 8;
        second = n * 8;
    }
    if ((u32)index < 8U) {
        func_004682A0(arg0, arg1, index, first);
    }
    if ((u32)next < 8U) {
        return func_004682A0(arg0, arg1, next, second);
    }
}

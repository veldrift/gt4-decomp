typedef float f32;
typedef int s32;

extern "C" f32 func_0043BAC8(s32 arg0) {
    s32 k = (arg0 < 0x80) ? 0x7F : 0x80;
    return (f32)(arg0 - k) / 127.0f;
}

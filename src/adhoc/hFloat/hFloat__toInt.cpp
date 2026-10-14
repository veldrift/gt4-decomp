typedef int s32;
typedef float f32;

extern "C" s32 hFloat__toInt(void *arg0) {
    return (s32)*(f32 *)((char *)arg0 + 0x10);
}

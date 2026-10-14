typedef int s32;
typedef float f32;
typedef unsigned char u8;

extern "C" f32 func_003F24A0(char *arg0, s32 arg1);
extern "C" void func_00345A20(void *arg0);

extern "C" void func_003F2560(char *arg0) {
    char *q = *(char **)(arg0 + 0x10);
    if (*(u8 *)(q + 0x1076) != 0) {
        s32 i = 0;
        f32 acc = 0.0f;
        s32 one = 1;
        char *p = arg0 + 0x164;
        do {
            f32 r = func_003F24A0(arg0, i);
            f32 v = *(f32 *)(p + 0x94);
            s32 t = i >> 1;
            i += 1;
            v = v - r;
            *(f32 *)(p + 0x94) = v;
            p += 0xEC;
            acc = acc - r * ((f32 *)(q + 0x20))[one - t];
        } while (i < 4);
        char *w = arg0 + 0x104;
        *(f32 *)(w + 8) = *(f32 *)(w + 8) + acc * 0.5f;
        return func_00345A20(arg0);
    }
}

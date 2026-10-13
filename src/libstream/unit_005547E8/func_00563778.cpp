typedef int s32;

extern "C" int D_00654D70;
extern "C" int D_00654D74;
extern "C" int D_00654D78;
extern "C" char D_00874380[];

extern "C" void func_00563778(void) {
    s32 *src = (s32 *)&D_00874380[0x4380 - 0x4380];
    D_00654D78 = src[0];
    D_00654D74 = src[1];
    D_00654D70 = src[2];
}

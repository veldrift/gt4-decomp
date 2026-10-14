/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef float f32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern char RaceBase__vtable[], D_00621340[];
extern "C" void func_00387B70();
extern "C" void *func_00101030(void *);
extern "C" void *func_003721D8(void *);
extern "C" void func_00574D78(void *);
extern "C" void RaceBase__enableInputIdle(void *);
extern "C" void RaceBase__structor_0(char *arg0) {
    func_00101030(arg0);
    M2C_FIELD(arg0, void **, 0x64) = RaceBase__vtable;
    func_003721D8(arg0 + 0x80);
    func_00574D78(arg0 + 0xCE4);
    M2C_FIELD(arg0, s32 *, 0xD48) = 0;
    M2C_FIELD(arg0, void **, 0x74) = D_00621340;
    M2C_FIELD(arg0, void **, 0x78) = (void *)func_00387B70;
    M2C_FIELD(arg0, s32 *, 0xCD4) = 1;
    M2C_FIELD(arg0, s32 *, 0x6C) = 0;
    M2C_FIELD(arg0, s32 *, 0x70) = 0;
    M2C_FIELD(arg0, s32 *, 0xCC0) = 0;
    M2C_FIELD(arg0, s32 *, 0xCC4) = 0;
    M2C_FIELD(arg0, s32 *, 0xCC8) = 0;
    M2C_FIELD(arg0, s32 *, 0xCCC) = 0;
    M2C_FIELD(arg0, s32 *, 0xCD0) = 0;
    M2C_FIELD(arg0, s32 *, 0xCD8) = 0;
    M2C_FIELD(arg0, s32 *, 0xCDC) = 0;
    M2C_FIELD(arg0, s32 *, 0xCE0) = 0;
    M2C_FIELD(arg0, s32 *, 0xD20) = 0;
    M2C_FIELD(arg0, s32 *, 0xD24) = 0;
    M2C_FIELD(arg0, s32 *, 0xD1C) = 0;
    M2C_FIELD(arg0, s32 *, 0xD30) = 0;
    RaceBase__enableInputIdle(arg0);
    M2C_FIELD(arg0, s32 *, 0xD38) = 0;
    M2C_FIELD(arg0, s32 *, 0xD60) = 0xA;
    M2C_FIELD(arg0, f32 *, 0xD3C) = 0x1.0000000000000p+0f;
    M2C_FIELD(arg0, s32 *, 0xD64) = 0xB;
    M2C_FIELD(arg0, s32 *, 0xD40) = 0;
    M2C_FIELD(arg0, s32 *, 0xD44) = 0;
    M2C_FIELD(arg0, s32 *, 0xD4C) = 0;
    M2C_FIELD(arg0, s32 *, 0xD68) = 0;
    M2C_FIELD(arg0, s32 *, 0xD6C) = 0;
}

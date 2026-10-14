typedef int s32;

extern "C" void func_004A5BF8(s32 arg0, s32 arg1, const char *arg2);
extern "C" void func_004AB040(s32 arg0);
extern "C" void func_004A1638(s32 arg0);

extern "C" char D_00621480[];
extern "C" char D_00621490[];
extern "C" char D_006214A0[];
extern "C" char D_00621470[];

extern "C" void func_00394A10(void) {
    func_004A5BF8(0x66, 0, D_00621480);
    func_004A5BF8(0x66, 1, D_00621490);
    func_004A5BF8(0x66, 4, D_006214A0);
    func_004A5BF8(0x66, 0xD, D_00621470);
    func_004AB040(0x65);
    func_004A1638(0x66);
    func_004AB040(0x67);
    func_004AB040(0x68);
}

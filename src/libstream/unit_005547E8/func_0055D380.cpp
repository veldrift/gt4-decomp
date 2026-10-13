/* compiler: ee-gcc2.96-nsa-nosib */
typedef int s32;

extern "C" void func_00568060(s32 arg0, s32 arg1, s32 arg2);

extern char D_0055DDB8[];
extern char SDDRV__VoiceSystem__master_[];

extern "C" void func_0055D380(void) {
    s32 third = (s32)SDDRV__VoiceSystem__master_;
    s32 second = (s32)D_0055DDB8;
    func_00568060(3, second, third);
}

typedef int s32;
typedef unsigned char u8;

extern char RaceDisplayLapDiffEvent__vtable[];

extern "C" s32 func_0034C190(s32 arg0, s32 arg1);
extern "C" void *RaceDisplayDiffEvent__structor_0(void *arg0);
extern "C" void RaceDisplayEventBase__put(void *o, void *t);

extern "C" void RaceDisplayLapDiffEvent__structor_0(void **arg0, s32 arg1, s32 arg2) {
    s32 sp[4];
    if (*((u8 *)func_0034C190((s32)arg0, arg1) + 0x736) == 0) {
        char *t = (char *)*arg0;
        if (*(s32 *)(t + 0xDC) == 0) {
            RaceDisplayDiffEvent__structor_0(sp);
            sp[1] = (s32)RaceDisplayLapDiffEvent__vtable;
            sp[0] = arg1;
            sp[2] = arg2;
            RaceDisplayEventBase__put(sp, t);
        }
    }
}

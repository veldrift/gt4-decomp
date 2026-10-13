typedef int s32;
typedef unsigned char u8;

struct DynamicsConductorMission {
    s32 unk0;
    char pad4[0xCBE3 - 4];
    u8 unkCBE3;
    char padCBE4[0xF81A - 0xCBE4];
    u8 unkF81A;
    char padF81B[0xF8A0 - 0xF81B];
    s32 unkF8A0;
};

extern "C" s32 func_0034C190(s32 arg0, s32 arg1);
extern "C" void func_0035DF80(char *arg0, s32 arg1, s32 arg2, s32 arg3);

extern "C" void func_003F6EE8(DynamicsConductorMission *arg0) {
    s32 var_s2 = 0;
    s32 base = arg0->unk0;
    if (arg0->unkF8A0 > 0) {
        s32 one = 1;
        do {
            u8 mask = (u8)(one << var_s2);
            if (*(u8 *)((char *)func_0034C190((s32)arg0, var_s2) + 0x5B6) != 0 &&
                !(arg0->unkCBE3 & mask)) {
                func_0035DF80((char *)base, 5, var_s2, 2);
                arg0->unkCBE3 = (u8)(mask | arg0->unkCBE3);
            }
            var_s2 += 1;
        } while (var_s2 < arg0->unkF8A0);
    }
    if (arg0->unkF81A != 5) {
        return;
    }
    if (arg0->unkF8A0 != 2) {
        return;
    }
    {
        u8 flag = *(u8 *)((char *)func_0034C190((s32)arg0, 0) + 0x5B6);
        if (__builtin_expect(flag, 0)) {
            func_0034C190((s32)arg0, 1);
        }
    }
}

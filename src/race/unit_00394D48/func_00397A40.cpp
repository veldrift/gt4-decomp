typedef int s32;
extern "C" void func_00397A98(s32 arg0, s32 arg1);
struct ObjA; 
struct ObjA { char pad0[0x4]; ObjA *unk4; char pad8[0x8]; s32 unk10; s32 unk14; };
extern "C" void func_00397A40(ObjA *arg0) {
    if (arg0->unk10 == 0) {
        arg0->unk14 = 0;
    } else {
        s32 d = (s32)arg0 - (s32)arg0->unk4;
        arg0->unk4 = arg0;
        if (d != 0) {
            if (arg0->unk14 != 0) { s32 *p = &arg0->unk14; *p = *p + d; func_00397A98(*p, d); }
        }
    }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef signed char s8;
typedef float f32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern "C" void mBox__virtual_91(void *,void *);
extern "C" void func_00230EC0(void *,float *,float *);
extern "C" void func_00230ED8(void *,float,float);
extern "C" void mWidget__setWindowX(void *,float);
extern "C" void mWidget__setWindowY(void *,float);
extern "C" void func_0025B430(void *,float *,float *);
extern "C" void mWidget__setWindowPosition(void *,float,float);
extern "C" void func_0025B500(void *,float *,float *,float *,float *);
extern "C" void func_0025BAA0(void *,float *,float *,float *,float *);
extern "C" int func_002D3610(void *,float *,float *) throw();
extern "C" void mScrollWindow__virtual_91(void *arg0, void *arg1) {
    struct StackFrame_002D36A0 { f32 sp0; f32 sp4; f32 sp8; f32 spC; f32 sp10; f32 sp14; f32 sp18; f32 sp1C; f32 sp20; f32 sp24; s8 pad0[0x8]; } sp_;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f12_2;
    f32 temp_f20;
    f32 temp_f21;
    f32 width;
    f32 height;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f3;
    f32 temp_f3_2;
    f32 temp_f4;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f24;
    f32 var_f5;

    mBox__virtual_91(arg0, arg1);
    if ((M2C_FIELD(arg0, void **, 0xBC) != 0) && (M2C_FIELD(arg0, void **, 0xC0) != 0)) {
        if (M2C_FIELD(arg0, s32 *, 0xB8) != 0) {
            var_f24 = 0x0.0p+0f;
            func_00230EC0(arg1, &sp_.sp0, &sp_.sp4);
            func_0025BAA0(M2C_FIELD(arg0, void **, 0xBC), &sp_.sp8, &sp_.spC, &sp_.sp10, &sp_.sp14);
            f32 rectWidth = sp_.sp10;
            f32 rectHeight = sp_.sp14;
            f32 marginX = rectWidth * 0.375f;
            f32 marginY = rectHeight * 0.375f;
            temp_f20 = sp_.sp8 + marginX;
            width = rectWidth * 0.25f;
            height = rectHeight * 0.25f;
            temp_f21 = sp_.spC + marginY;
            func_0025B500(M2C_FIELD(arg0, void **, 0xC0), &sp_.sp18, &sp_.sp1C, &sp_.sp20, &sp_.sp24);
            var_f5 = 0x0.0p+0f;
            if (sp_.sp0 < temp_f20) {
                var_f5 = sp_.sp0 - temp_f20;
            }
            temp_f3 = temp_f20 + width;
            if (temp_f3 < sp_.sp0) {
                var_f5 = sp_.sp0 - temp_f3;
            }
            if (sp_.sp4 < temp_f21) {
                var_f24 = sp_.sp4 - temp_f21;
            }
            temp_f2 = temp_f21 + height;
            if (temp_f2 < sp_.sp4) {
                var_f24 = sp_.sp4 - temp_f2;
            }
            if (sp_.sp18 < 0x0.0p+0f) {
                if ((sp_.sp10 - sp_.sp20) < sp_.sp18) {
                    sp_.sp0 -= var_f5;
                }
            }
            temp_f12 = sp_.sp18 - var_f5;
            sp_.sp18 = temp_f12;
            if (temp_f12 > 0x0.0p+0f) {
                sp_.sp18 = 0x0.0p+0f;
            }
            temp_f0 = sp_.sp10 - sp_.sp20;
            var_f12 = sp_.sp18;
            if (var_f12 < temp_f0) {
                var_f12 = temp_f0;
                sp_.sp18 = temp_f0;
            }
            mWidget__setWindowX(M2C_FIELD(arg0, void **, 0xC0), var_f12);
            if (sp_.sp1C < 0x0.0p+0f) {
                if ((sp_.sp14 - sp_.sp24) < sp_.sp1C) {
                    sp_.sp4 -= var_f24;
                }
            }
            temp_f12_2 = sp_.sp1C - var_f24;
            sp_.sp1C = temp_f12_2;
            if (temp_f12_2 > 0x0.0p+0f) {
                sp_.sp1C = 0x0.0p+0f;
            }
            temp_f0_2 = sp_.sp14 - sp_.sp24;
            var_f12_2 = sp_.sp1C;
            if (var_f12_2 < temp_f0_2) {
                var_f12_2 = temp_f0_2;
                sp_.sp1C = temp_f0_2;
            }
            mWidget__setWindowY(M2C_FIELD(arg0, void **, 0xC0), var_f12_2);
            func_00230ED8(arg1, sp_.sp0, sp_.sp4);
            return;
        }
        if (func_002D3610(arg0, &sp_.sp24, &sp_.sp20) != 0) {
            func_0025B430(M2C_FIELD(arg0, void **, 0xC0), &sp_.sp1C, &sp_.sp18);
            temp_f4 = M2C_FIELD(arg0, f32 *, 0xB4);
            temp_f2_2 = sp_.sp1C + ((sp_.sp24 - sp_.sp1C) * temp_f4);
            temp_f3_2 = sp_.sp18 + ((sp_.sp20 - sp_.sp18) * temp_f4);
            sp_.sp1C = temp_f2_2;
            sp_.sp18 = temp_f3_2;
            mWidget__setWindowPosition(M2C_FIELD(arg0, void **, 0xC0), temp_f2_2, temp_f3_2);
            M2C_FIELD(arg0, f32 *, 0xD8) = (f32) -sp_.sp1C;
            M2C_FIELD(arg0, f32 *, 0x110) = (f32) -sp_.sp18;
        }
    }
}

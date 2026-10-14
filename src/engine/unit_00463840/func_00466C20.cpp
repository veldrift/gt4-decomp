/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef float f32;typedef int s32;typedef signed char s8;typedef unsigned char u8;
#define M2C_FIELD(p, t, o) (*(t)((char *)(p)+(o)))
extern float D_00623F44;
extern u8 D_00623FD8[];
extern "C" char *func_00463BB8(void *) throw();                        /* extern */
extern "C" char *func_00466C08(void *,s32,s32) throw();                   /* extern */

extern "C" void func_00466C20(void *arg0, s32 arg1, s32 arg2) {
    f32 *var_v1_3;
    f32 temp_f2;
    f32 temp_f3;
    f32 var_f0;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a1_2;
    s8 var_a1;
    s8 var_a5;
    s8 var_v1;
    s8 var_v1_2;
    u8 *var_a0;
    u8 temp_a1;
    u8 temp_a2;
    s32 temp_v0_2;
    u8 temp_v0_3;
    u8 temp_v0_4;
    char *temp_a3;
    char *temp_s0;
    char *temp_v0;

    temp_s0 = func_00466C08(arg0, arg2, arg1);
    temp_v0 = func_00463BB8(arg0);
    temp_a3 = temp_v0 + 0x24;
    M2C_FIELD(temp_v0, f32 *, 0xC) = (f32) ((f32) (M2C_FIELD(temp_s0, u8 *, 3) * 5) * 0x1.47ae140000000p-7f);
    M2C_FIELD(temp_v0, f32 *, 0x1C) = (f32) M2C_FIELD(temp_s0, u8 *, 7);
    M2C_FIELD(temp_v0, f32 *, 0x20) = (f32) M2C_FIELD(temp_s0, u8 *, 8);
    M2C_FIELD(temp_v0, f32 *, 0x18) = (f32) (0x1.0000000000000p+0f / ((f32) (M2C_FIELD(temp_s0, u8 *, 6) * 2) * 0x1.1c71c60000000p-2f));
    M2C_FIELD(temp_v0, f32 *, 0x6C) = 1.0f;
    M2C_FIELD(temp_v0, f32 *, 0) = (f32) M2C_FIELD(temp_s0, u8 *, 0) * 0x1.47ae14p-7f;
    M2C_FIELD(temp_v0, f32 *, 4) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 1) * 0x1.47ae140000000p-7f);
    M2C_FIELD(temp_v0, f32 *, 8) = (f32) ((f32) (M2C_FIELD(temp_s0, u8 *, 2) - 0x64) * 0x1.1c71c60000000p-2f);
    M2C_FIELD(temp_v0, f32 *, 0x10) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 4) * 0x1.47ae140000000p-7f);
    M2C_FIELD(temp_v0, f32 *, 0x14) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 5) * 0x1.47ae140000000p-7f);
    M2C_FIELD(temp_v0, f32 *, 0x58) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 0xE) * 0x1.47ae140000000p-7f);
    M2C_FIELD(temp_v0, f32 *, 0x5C) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 0xF) * 0x1.1c71c60000000p-2f);
    M2C_FIELD(temp_v0, f32 *, 0x60) = (f32) ((f32) (M2C_FIELD(temp_s0, u8 *, 0x10) * 0xA) * 0x1.1df4680000000p-6f);
    M2C_FIELD(temp_v0, s32 *, 0x68) = (s32) (M2C_FIELD(temp_s0, u8 *, 0x11) * 0xA);
    temp_v0_2 = M2C_FIELD(temp_s0, u8 *, 0x12);
    if(temp_v0_2==0)temp_v0_2=80;
    M2C_FIELD(temp_v0, f32 *, 0x64) = (f32) ((f32) temp_v0_2 * 0x1.1c71c60000000p-2f);
    M2C_FIELD(temp_v0, f32 *, 0) = (f32) (M2C_FIELD(temp_v0, f32 *, 0) * D_00623F44);
    temp_a2 = M2C_FIELD(temp_s0, u8 *, 0x13);
    M2C_FIELD(temp_a3, f32 *, 0) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 9) * 0x1.47ae140000000p-7f);
    M2C_FIELD(temp_a3, f32 *, 4) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 0xA) * 0x1.47ae140000000p-7f);
    M2C_FIELD(temp_a3, f32 *, 8) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 0x14) * 0x1.47ae140000000p-7f);
    if ((u8)(temp_a2 & 1)) {
        M2C_FIELD(temp_a3, s8 *, 0xC) = 1;
    } else {
        M2C_FIELD(temp_a3, s8 *, 0xC) = 0;
    }
    M2C_FIELD(temp_a3, s8 *, 0xD) = (s8) ((temp_a2 >> 1) & 1);
    M2C_FIELD(temp_a3, s8 *, 0xE) = (s8) ((temp_a2 >> 2) & 1);
    M2C_FIELD(temp_a3, s8 *, 0xF) = (s8) ((temp_a2 >> 3) & 1);
    temp_v1 = M2C_FIELD(temp_a3, s32 *, 0xC);
    var_a1 = 0;
    if ((temp_v1 & 0xFFFF) && (M2C_FIELD(temp_a3, f32 *, 0) != 0x0.0p+0f)) {
        var_a1 = 1;
    }
    M2C_FIELD(temp_a3, s8 *, 0x30) = var_a1;
    var_v1 = 0;
    if ((temp_v1 & 0xFFFF0000) && (M2C_FIELD(temp_a3, f32 *, 8) != 0x0.0p+0f)) {
        var_v1 = 1;
    }
    M2C_FIELD(temp_a3, s8 *, 0x31) = var_v1;
    var_a5 = 0;
    temp_f2 = (f32) M2C_FIELD(temp_s0, u8 *, 0x15) * 0x1.47ae140000000p-7f;
    M2C_FIELD(temp_a3, f32 *, 0x10) = temp_f2;
    M2C_FIELD(temp_a3, f32 *, 0x14) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 0x16) * 0x1.47ae140000000p-7f);
    M2C_FIELD(temp_a3, f32 *, 0x18) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 0x17) * 0x1.47ae140000000p-7f);
    M2C_FIELD(temp_a3, s8 *, 0x1C) = (s8) ((temp_a2 >> 4) & 1);
    M2C_FIELD(temp_a3, s8 *, 0x1D) = (s8) ((temp_a2 >> 5) & 1);
    M2C_FIELD(temp_a3, s8 *, 0x1E) = (s8) ((temp_a2 >> 6) & 1);
    M2C_FIELD(temp_a3, s8 *, 0x1F) = (s8) (temp_a2 >> 7);
    temp_v1_2 = M2C_FIELD(temp_a3, s32 *, 0x1C);
    if ((temp_v1_2 & 0xFFFF) && (temp_f2 != 0x0.0p+0f)) {
        var_a5 = 1;
    }
    M2C_FIELD(temp_a3, s8 *, 0x32) = var_a5;
    var_v1_2 = 0;
    if ((temp_v1_2 & 0xFFFF0000) && (M2C_FIELD(temp_a3, f32 *, 0x18) != 0x0.0p+0f)) {
        var_v1_2 = 1;
    }
    M2C_FIELD(temp_a3, s8 *, 0x33) = var_v1_2;
    M2C_FIELD(temp_a3, f32 *, 0x24) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 0xB) * 0x1.9999980000000p-4f);
    M2C_FIELD(temp_a3, f32 *, 0x28) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 0xC) * 0x1.47ae140000000p-7f);
    M2C_FIELD(temp_a3, f32 *, 0x20) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 0xD) * 0x1.9999980000000p-4f);
    temp_v0_3 = M2C_FIELD(temp_s0, u8 *, 0x18);
    if ((temp_v0_3 == 0x64) || (temp_v0_3 == 0)) {
        var_f0 = 0x1.0000000000000p+0f;
    } else {
        var_f0 = (f32) temp_v0_3 * 0x1.47ae140000000p-7f;
    }
    M2C_FIELD(temp_a3, f32 *, 0x2C) = var_f0;
    M2C_FIELD(temp_v0, s8 *, 0x78) = 0;
    M2C_FIELD(temp_v0, f32 *, 0x7C) = 0x0.0p+0f;
    M2C_FIELD(temp_v0, f32 *, 0x80) = 0x0.0p+0f;
    if ((M2C_FIELD(temp_s0, u8 *, 0x1D) != 0) && (M2C_FIELD(temp_s0, u8 *, 0x1C) != 0)) {
        M2C_FIELD(temp_v0, s8 *, 0x78) = 1;
        M2C_FIELD(temp_v0, f32 *, 0x7C) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 0x1C) * 0x1.1df4680000000p-6f);
        M2C_FIELD(temp_v0, f32 *, 0x80) = (f32) ((f32) M2C_FIELD(temp_s0, u8 *, 0x1D) * 0x1.1c71c60000000p-2f);
    }
    temp_a1 = D_00623FD8[arg1];
    if ((temp_a1 != 0) && (temp_a1 != 0x64)) {
        M2C_FIELD(temp_v0, f32 *, 0x80) = (f32) (M2C_FIELD(temp_v0, f32 *, 0x80) * ((f32) temp_a1 / 0x1.9000000000000p+6f));
    }
    var_v1_3 = (f32 *)(temp_v0 + 0xA8);
    for(int i=0;i<3;i++,var_v1_3++) {
        *var_v1_3=1.0f;
        if(M2C_FIELD(temp_s0,u8*,0x1B)==0x20) {
            int val=M2C_FIELD(temp_s0,u8*,0x20+i);
            if(val!=0 && val!=100)*var_v1_3=(float)val/100.0f;
        }
    }
    M2C_FIELD(arg0, f32 *, 0xB8)=1.0f;
    M2C_FIELD(arg0, f32 *, 0xBC)=1.0f;
    M2C_FIELD(arg0, f32 *, 0xC0)=1.0f;
}

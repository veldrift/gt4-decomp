/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef float f32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern "C" void func_00105280(void *, int);          /* extern */
extern "C" int func_001052E0(void *, int, s32, s32); /* extern */
extern "C" void func_001056A0(void *);                   /* extern */
extern "C" void func_00105728(void *);                   /* extern */
extern "C" s32 func_00105818(void *);                       /* extern */
extern "C" void func_004A1638(int);                     /* extern */
extern "C" void func_004A2808(int, f32);                /* extern */
extern "C" void func_004A3078(int);                     /* extern */
extern "C" void func_004A3230(int);                     /* extern */
extern "C" void func_004A4550(int, int);            /* extern */
extern "C" void func_004A6290(int, int, s32, s32);  /* extern */
extern "C" void func_004A6788(f32, f32, f32, f32, f32, f32, f32, f32); /* extern */
extern "C" void func_004AA168(int);                     /* extern */
extern "C" void func_004AB040(int);                     /* extern */

extern "C" void func_003BADF8(void *arg0, void *arg1, void *arg2) {
    int buf[16], tmp[16];
    float srcH, dstH, strength, y;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f21;
    f32 temp_f24;
    f32 temp_f25;
    f32 temp_f26;
    f32 temp_f27;
    f32 temp_f28;
    f32 temp_f31;
    f32 var_f23;
    s32 var_s1;
    s32 var_s6;
    s32 var_v1;

    if (!(M2C_FIELD(arg0, f32 *, 0) < 0.0f) && !(M2C_FIELD(arg0, f32 *, 0xC) <= 0.0f) && (M2C_FIELD(arg0, s32 *, 0x10) > 0)) {
        y = 0.0f;
        func_004AB040(6);
        func_004AB040(5);
        func_004AB040(8);
        var_s6 = 0;
        func_004A4550(2, 1);
        func_004A4550(3, 1);
        func_001052E0(buf, 1, M2C_FIELD(arg0, s32 *, 0x14), M2C_FIELD(arg0, s32 *, 0x18));
        func_001056A0(buf);
        func_004A3078(0);
        func_004A3230(1);
        temp_f26 = (f32) M2C_FIELD(arg2, s32 *, 8);
        temp_f1 = (f32) func_00105818(arg2);
        srcH = (f32) M2C_FIELD(arg2, s32 *, 0xC);
        temp_f0 = M2C_FIELD(arg0, f32 *, 0xC);
        temp_f24 = temp_f1 / temp_f0;
        temp_f25 = temp_f26 / temp_f0;
        func_001052E0(tmp, 1, (s32) temp_f25, (s32) temp_f24);
        func_001056A0(tmp);
        func_004A3230(1);
        temp_f27 = (f32) buf[2];
        dstH = (f32) func_00105818(buf);
        float scale = M2C_FIELD(arg0, f32 *, 0xC);
        temp_f31 = scale / (f32) M2C_FIELD(arg0, s32 *, 0x10);
        strength = M2C_FIELD(arg0, f32 *, 8) / ((1.0f - M2C_FIELD(arg0, f32 *, 0)) * (f32) (M2C_FIELD(arg0, s32 *, 0x10) * M2C_FIELD(arg0, s32 *, 0x10)));
        for (; var_s6 < M2C_FIELD(arg0, s32 *, 0x10); var_s6++, y += temp_f31) {
                var_s1 = 0;
                var_f23 = 0.0f;
                temp_f28 = y + 0.5f;
                for (; var_s1 < M2C_FIELD(arg0, s32 *, 0x10); var_s1++, var_f23 += temp_f31) {
                        temp_f20 = var_f23 + 0.5f;
                        func_001056A0(tmp);
                        func_00105728(arg2);
                        func_004A4550(4, 2);
                        func_004A4550(5, 2);
                        func_004AB040(6);
                        func_004AA168(0xFFFFFF);
                        func_004A6788(0.0f, 0.0f, temp_f25, temp_f24, temp_f20, temp_f28, temp_f20 + temp_f26, temp_f28 + srcH);
                        if (M2C_FIELD(arg0, f32 *, 0) > 0.0f) {
                            func_004A1638(6);
                            func_004A2808(0x62, M2C_FIELD(arg0, f32 *, 0));
                            func_004A6290(0, 0, (s32) temp_f25, (s32) temp_f24);
                        }
                        temp_f20_2 = var_f23 * temp_f27;
                        temp_f21 = (y * dstH) / srcH;
                        func_001056A0(buf);
                        func_00105728(tmp);
                        func_004A4550(4, 2);
                        func_004A4550(5, 2);
                        temp_f20_3 = temp_f20_2 / temp_f26;
                        func_004A1638(6);
                        func_004A2808(0x68, strength);
                        func_004AA168(0x80FFFFFF);
                        func_004A6788(temp_f20_3, temp_f21, temp_f20_3 + temp_f27, temp_f21 + dstH, 0.0f, 0.0f, temp_f25, temp_f24);
                }
        }
        func_001056A0(arg1);
        func_00105728(buf);
        func_004A4550(4, 2);
        func_004A4550(5, 2);
        func_004A1638(6);
        func_004A2808(0x68, (1.0f - M2C_FIELD(arg0, f32 *, 0)) * M2C_FIELD(arg0, f32 *, 4));
        func_004AA168(0x80FFFFFF);
        temp_f20_4 = (f32) M2C_FIELD(arg1, s32 *, 8);
        func_004A6788(0.0f, 0.0f, temp_f20_4, (f32) func_00105818(arg1), 0.0f, 0.0f, temp_f27, dstH);
        func_00105280(tmp, 2);
        func_00105280(buf, 2);
    }
}

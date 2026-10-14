/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef unsigned int u32; typedef short s16; typedef unsigned short u16; typedef signed char s8; typedef unsigned char u8;
#define NULL 0
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
void func_004C3F90(s32,s32);
void *func_004C4070(void *,const void *,u32);
s32 func_004C6C90(s32,s32,s32,s32 *,s32,s32,s16 *,s32 *,char **,s32);
void func_004C8AA8(s32,s32,s32);
s32 func_004C8C20(s32,s32); s32 func_004C8ED0(s32);
void func_004C9428(s32 *,s32,s32);
s32 func_004C6838(s32 arg0, s32 arg1, s32 arg2, char *arg3, s32 arg4, s32 arg5) {
    s32 sp10[12];
    s16 x; char *p; s32 y;
    s32 var_s2;
    s32 temp_a0;
    s32 temp_s0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_s6;
    u32 temp_fp;
    u32 var_s3;
    u8 temp_v0_4;
    u8 temp_v0_5;
    s32 temp_v1;
    u8 temp_v1_2;
    char *temp_s0_2;
    char *temp_s0_3;
    char *temp_v0_3;
    char *copy;

    p = NULL;
    temp_s6 = func_004C8ED0(arg1) & 0xFF;
    M2C_FIELD(arg3, u8 *, 0x498) = 0U;
    M2C_FIELD(arg3, s32 *, 0x49C) = 0;
    temp_s0 = temp_s6 * 4;
    M2C_FIELD(arg3, u8 *, 0x499) = temp_s6;
    temp_v0_2 = func_004C8C20(arg0, temp_s0);
    if (!temp_v0_2) return 0x8000030C;
    temp_fp = (u16)temp_s6;
    func_004C3F90(temp_v0_2, temp_s0);
    for (var_s3 = 0; var_s3 < temp_fp;) {
            if (var_s3 == 0) {
                func_004C9428(sp10, arg4, arg2);
            } else {
                func_004C9428(sp10, arg5, arg2);
            }
            x = 0;
            y = 0;
            temp_v0 = func_004C6C90(arg0, arg1 + (var_s3 * 2), arg2, sp10, 1, temp_v0_2 + (var_s3 * 4), &x, &y, &p, 0);
            if (temp_v0 < 0) {
                func_004C8AA8(arg0, temp_v0_2, temp_s6);
                return temp_v0;
            }
            if (!p) {
                func_004C8AA8(arg0, temp_v0_2, temp_s6);
                return 0x80000A0C;
            }
                    temp_a0 = M2C_FIELD(p, s32 *, 0);
                    if (temp_a0 & 0x400000) {
                        temp_s0_2 = p + 4;
                        var_s3 = (var_s3 + M2C_FIELD(p, u8 *, 0x11)) & 0xFFFF;
                        if (temp_a0 & 0xC00000) {
                            var_s2 = M2C_FIELD(p, u16 *, 0xA) & 0x1FF;
                        } else {
                            temp_v0_3 = M2C_FIELD(p, char **, 4);
                            { u32 high = (M2C_FIELD(temp_v0_3, u8 *, 4) & 0x3F) << 3;
                              u32 low = M2C_FIELD(temp_v0_3, u8 *, 5) >> 5;
                              var_s2 = low | high; }
                        }
                        M2C_FIELD(temp_s0_2, s16 *, 6) = (s16) (var_s2 | 0x4000);
                        M2C_FIELD(p, u8 *, 0x11) = (u8) (M2C_FIELD(p, u8 *, 0x11) - M2C_FIELD(temp_s0_2, u8 *, 4));
                        temp_v1 = M2C_FIELD(temp_s0_2, u8 *, 2) - M2C_FIELD(temp_s0_2, u8 *, 4);
                        M2C_FIELD(temp_s0_2, u8 *, 2) = temp_v1;
                        M2C_FIELD(p, u8 *, 0x10) = (u8) (M2C_FIELD(p, u8 *, 0x11) - temp_v1);
                        M2C_FIELD(temp_s0_2, u8 *, 3) = (u8) (M2C_FIELD(temp_s0_2, u8 *, 3) - M2C_FIELD(temp_s0_2, u8 *, 5));
                        temp_v0_4 = M2C_FIELD(arg3, u8 *, 0x498)++;
                        func_004C4070(arg3 + (temp_v0_4 * 0x1C), p, 0x1C);
                        M2C_FIELD(temp_s0_2, s16 *, 6) = var_s2;
                        M2C_FIELD(p, u8 *, 0x11) = (u8) M2C_FIELD(temp_s0_2, u8 *, 4);
                        M2C_FIELD(temp_s0_2, u8 *, 2) = (u8) M2C_FIELD(temp_s0_2, u8 *, 4);
                        M2C_FIELD(p, u8 *, 0x10) = 0U;
                        M2C_FIELD(temp_s0_2, u8 *, 3) = (u8) M2C_FIELD(temp_s0_2, u8 *, 5);
                        temp_v0_5 = M2C_FIELD(arg3, u8 *, 0x498)++;
                        func_004C4070(arg3 + (temp_v0_5 * 0x1C), p, 0x1C);
                    } else {
                        temp_s0_3 = arg3 + 8;
                        func_004C4070(arg3 + (M2C_FIELD(arg3, u8 *, 0x498) * 0x1C), p, 0x1C);
                        temp_v1_2 = M2C_FIELD(arg3, u8 *, 0x498)++;
                        copy = p;
                        M2C_FIELD(((temp_v1_2 * 0x1C) + temp_s0_3), s32 *, 0x10) = 0;
                        if (M2C_FIELD(copy, char **, 0x18) != NULL) {
                            func_004C4070(arg3 + (M2C_FIELD(arg3, u8 *, 0x498) * 0x1C), p, 0x1C);
                            copy = p;
                            M2C_FIELD(((M2C_FIELD(arg3, u8 *, 0x498) * 0x1C) + temp_s0_3), s32 *, 0x10) = 0;
                            func_004C4070(arg3 + (M2C_FIELD(arg3, u8 *, 0x498) * 0x1C), M2C_FIELD(copy, char **, 0x18), 0x10);
                            M2C_FIELD(((M2C_FIELD(arg3, u8 *, 0x498) * 0x1C) + arg3), s8 *, -0xB) = (s8) (M2C_FIELD(p, u8 *, 0x16) + M2C_FIELD(p, u8 *, 0x10));
                            M2C_FIELD(((M2C_FIELD(arg3, u8 *, 0x498) * 0x1C) + arg3), s8 *, 0x10) = 0;
                            M2C_FIELD(((M2C_FIELD(arg3, u8 *, 0x498) * 0x1C) + arg3), u8 *, 0x11) = (u8) M2C_FIELD(p, u8 *, 0x17);
                            M2C_FIELD(arg3, u8 *, 0x498) = (u8) (M2C_FIELD(arg3, u8 *, 0x498) + 1);
                        }
                        var_s3 = (var_s3 + M2C_FIELD(p, u8 *, 0x11)) & 0xFFFF;
                    }
    }
    func_004C8AA8(arg0, temp_v0_2, temp_s6);
    return 1;
}

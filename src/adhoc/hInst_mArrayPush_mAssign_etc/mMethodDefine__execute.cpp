typedef int s32;
typedef short s16;

s32 func_002F47F0(s32);
void func_002F4848(s32, s32);
s32 func_002F36A0(s32, char *, s32);
void *func_00322060(s32);
s32 func_005C0FC8(s32, s32, s32, s32, s32, s32);

extern char D_005EDCA0[];
extern char D_005EFE50[];

s32 func_0031D928(char *arg0, s32 arg1) {
    char *temp_v0;
    char *temp_t;
    char *p2;
    char *p1;
    s32 var_s0;

    p2 = arg0;
    p1 = p2 + 0xC;
    if (func_002F47F0(*(s32 *)p1) == 0) {
        var_s0 = 0;
        temp_v0 = (char *)func_00322060(arg1);
        if (temp_v0 != 0) {
            temp_t = *(char **)(temp_v0 + 4);
            var_s0 = func_005C0FC8(*(s32 *)(temp_t + 4), (s32)D_005EDCA0, 0,
                                   (s32)(temp_v0 + *(s16 *)temp_t), (s32)D_005EFE50,
                                   (s32)temp_v0);
        }
        if (var_s0 != 0) {
            func_002F4848(*(s32 *)p1, var_s0);
            return func_002F36A0(var_s0, p2 + 8, (s32)p1);
        }
    }
}

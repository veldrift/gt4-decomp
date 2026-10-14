/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern char D_0065B7E0[];
struct Local { void *vt; char rest[0x58-4]; ~Local() { vt=D_0065B7E0; } };
extern "C" s32 func_001564D8(void *);
extern "C" void func_00156728(void *,s32);
extern "C" void func_00450AB0(void *,s32 *);
extern "C" s32 func_00450AD0(void *);
extern "C" void func_00450CB8(void *,void *);
extern "C" void func_00459780(void *,void *);
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_005ADF20(s32);
extern "C" void func_00155A50(char *arg0, char *arg1) {
    s32 *temp_v1;
    s32 temp_a1;
    char *temp_s2;
    char *temp_s0;

    temp_s2 = arg0 + 0xEC;
    func_00576788(temp_s2);
    M2C_FIELD(arg0, s32 *, 0x150) = 0;
    if (M2C_FIELD(arg1, s32 *, 0x84) == 0) {
        temp_v1 = M2C_FIELD(M2C_FIELD(arg1, void **, 0x4C), s32 **, 0x30);
        if (*temp_v1 == 0x34524143) {
            Local local;
            temp_s0 = arg0 + 0x2A4;
            func_00450AB0(temp_s0, temp_v1);
            func_00459780(&local, arg0 + 0x864);
            func_00450CB8(temp_s0, &local);
            temp_a1 = M2C_FIELD(arg0, s32 *, 0x54);
            func_00156728(arg0, (temp_a1 < 0) ? 0 : temp_a1);
        } else {
            func_00450AD0(arg0 + 0x2A4);
        }
        func_005ADF20(0);
        if (M2C_FIELD(arg0, s32 *, 0x98) != 0) {
            M2C_FIELD(arg0, s32 *, 0x1D8) = 0;
            M2C_FIELD(arg0, s32 *, 0x174) = 1;
            M2C_FIELD(arg0, s32 *, 0x188) = 1;
            M2C_FIELD(arg0, s32 *, 0x19C) = 1;
            M2C_FIELD(arg0, s32 *, 0x1B0) = 1;
        } else {
            M2C_FIELD(arg0, s32 *, 0x1D8) = 1;
            func_001564D8(arg0);
        }
    }
    func_005767C0(temp_s2);
}

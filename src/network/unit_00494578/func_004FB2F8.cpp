/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32; typedef signed char s8;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern "C" void func_005A6AB0(void *, void *, int) throw();
extern "C" void func_004FB2F8(char *arg0, char *arg1, s32 arg2) {
    char *temp_s0;

    func_005A6AB0(arg0 + 0x8A1, arg1 + 0x134, 0x40);
    temp_s0 = arg0 + 0x88C;
    func_005A6AB0(arg0 + 0x8E1, arg1 + 0x34, 0x100);
    M2C_FIELD(temp_s0, s8 *, 0x155) = 0;
    M2C_FIELD(temp_s0, s32 *, 0x178) = (s32) M2C_FIELD(arg0, s32 *, 0x40);
    M2C_FIELD(temp_s0, s32 *, 0x180) = (s32) M2C_FIELD(arg1, s32 *, 0x20);
    M2C_FIELD(temp_s0, s32 *, 0x17C) = (s32) M2C_FIELD(arg1, s32 *, 0x24);
    M2C_FIELD(temp_s0, s32 *, 0x184) = (s32) M2C_FIELD(arg1, s32 *, 0x30);
    M2C_FIELD(temp_s0, s32 *, 0x188) = (s32) M2C_FIELD(arg1, s32 *, 0x28);
    M2C_FIELD(temp_s0, s32 *, 0x18C) = (s32) M2C_FIELD(arg1, s32 *, 0x2C);
    M2C_FIELD(temp_s0, s32 *, 0x190) = (s32) M2C_FIELD(arg1, s32 *, 0x174);
    M2C_FIELD(temp_s0, s32 *, 0x194) = (s32) M2C_FIELD(arg1, s32 *, 0x178);
    M2C_FIELD(temp_s0, s32 *, 0x198) = (s32) M2C_FIELD(arg1, s32 *, 0x17C);
    M2C_FIELD(temp_s0, s32 *, 0x19C) = (s32) M2C_FIELD(arg1, s32 *, 0x180);
    M2C_FIELD(temp_s0, s32 *, 0x1A0) = arg2;
    M2C_FIELD(temp_s0, s32 *, 0x1A4) = 2;
}

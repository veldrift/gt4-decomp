/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
#define M2C_FIELD(p,t,o) (*(t)((char *)(p)+(o)))
extern char mCarModelPS2__vtable[],D_006885F0[],D_00688628[],D_0068FD70[];
extern "C" void mCarModel__structor_1(void *,s32);
extern "C" void func_00154B78(void *,s32) throw();
extern "C" void func_00154BB8(void *) throw();
extern "C" void func_00154CD0(void *) throw();
extern "C" void func_001574E8(void *);
extern "C" void func_001D5020(void *,s32);
extern "C" void func_00326798(void *,s32,s32,const char *);
extern "C" void ShowRoomCar__structor_1(void *,s32);
extern "C" s32 func_00450AD0(void *);
extern "C" void func_004574A0(void *,s32);
extern "C" void func_004AFCE8(void *,s32);
extern "C" void func_00574DA8(void *,s32);
extern "C" void free(s32) throw();
extern "C" void func_00576788(void *);
extern "C" void func_005767C0(void *);
extern "C" void func_005768D8(void *);
extern "C" void func_00578908(s32);
extern "C" void func_00578AF0(s32);
extern "C" void mCarModelPS2__structor_1(char *arg0, s32 arg1) {
    char *temp_s1;
    char *temp_s2;
    char *temp_s4;

    temp_s2 = arg0 + 0x11C;
    temp_s4 = arg0 + 0x164;
    *(void **)(arg0+4) = mCarModelPS2__vtable;
    temp_s1 = arg0 + 0x1B4;
    M2C_FIELD(arg0, s32 *, 0x160) = 1;
    M2C_FIELD(arg0, s32 *, 0x1C8) = 1;
    M2C_FIELD(arg0, s32 *, 0x1CC) = 1;
    M2C_FIELD(arg0, s32 *, 0x1D0) = 1;
    M2C_FIELD(arg0, s32 *, 0x1D4) = 1;
    func_00154CD0(temp_s4);
    func_00576788(temp_s2);
    M2C_FIELD(arg0, s32 *, 0x158) = 0;
    M2C_FIELD(arg0, s32 *, 0x15C) = 1;
    M2C_FIELD(arg0, s32 *, 0x1DC) = 1;
    func_005768D8(temp_s2);
    func_005767C0(temp_s2);
    func_001574E8(arg0);
    func_001574E8(arg0);
    func_00154BB8(temp_s1);
    func_00154BB8(temp_s1);
    func_00578908(M2C_FIELD(arg0, s32 *, 0x14C));
    func_00578AF0(M2C_FIELD(arg0, s32 *, 0x14C));
    M2C_FIELD(arg0, s32 *, 0x174) = 0;
    func_00450AD0(arg0 + 0x2A4);
    free(M2C_FIELD(arg0, s32 *, 0x8A4));
    free(M2C_FIELD(arg0, s32 *, 0x8A0));
    free(M2C_FIELD(arg0, s32 *, 0x89C));
    free(M2C_FIELD(arg0, s32 *, 0x9C));
    func_001D5020(arg0 + 0x8AC, 2);
    ShowRoomCar__structor_1(arg0 + 0x864, 2);
    char *p0=arg0+0x2B0;
    *(void **)p0=D_006885F0;
    func_004574A0(p0,0);
    char *p1=arg0+0x2A8;
    *(void **)p1=D_00688628;
    func_004574A0(p1,0);
    func_00154B78(temp_s1, 2);
    func_00154B78(arg0 + 0x1A0, 2);
    func_00154B78(arg0 + 0x18C, 2);
    func_00154B78(arg0 + 0x178, 2);
    func_00154B78(temp_s4, 2);
    func_00574DA8(temp_s2, 2);
    func_00574DA8(arg0 + 0xEC, 2);
    func_004AFCE8(arg0 + 0xA8, 2);
    mCarModel__structor_1(arg0, 0);
    if (arg1 & 1) {
        return func_00326798(arg0, 0xA60, 4, D_0068FD70);
    }
}

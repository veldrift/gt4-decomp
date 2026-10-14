typedef int s32;
extern "C" void func_005BC588(void *a);
extern "C" void func_00107E88(void *a, void *b);
extern "C" void func_00107ED8(void);
extern "C" void func_00108040(void);
extern "C" void *D_006186E8;
extern "C" void *D_006186EC;
extern "C" s32 func_00107F08(void *arg0, void *arg1) {
    void *loc = arg0;
    func_005BC588(arg0);
    D_006186E8 = loc;
    D_006186EC = arg1;
    func_00107E88(&loc, arg1);
    func_00108040();
    func_00107ED8();
    return 0;
}

typedef int s32;

extern "C" void func_003AECB0(void *arg0, const char *arg1);

extern "C" s32 D_006244D8[];
extern "C" char D_006A1578[];
extern "C" char D_006A1590[];
extern "C" char D_006A15A8[];
extern "C" char D_006A15B8[];
extern "C" char D_006A15C8[];

extern "C" void func_003A8290(char *arg0) {
    const char *name;
    s32 v = *(s32 *)D_006244D8;

    if (v == 0) {
        name = D_006A1590;
    } else if (v == 1) {
        name = D_006A1578;
    } else {
        name = D_006A1590;
    }
    func_003AECB0(arg0 + 0x2C, name);
    func_003AECB0(arg0 + 0x344, D_006A15A8);
    func_003AECB0(arg0 + 0x2BC, D_006A15B8);
    func_003AECB0(arg0 + 0x300, D_006A15C8);
}

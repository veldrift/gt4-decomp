typedef int s32;
typedef long long s64;

extern "C" char *func_004541C0(s64 arg0);
extern "C" void func_005A5DC8(char *arg0, char *arg1);
extern "C" void func_005A609C(char *arg0, const char *arg1);
extern char D_006AA9D8[];
extern char D_006AA9E8[];
extern char D_006AA9F8[];

extern "C" char *GT4Model__CarModel__getModelFileName(s64 arg0, char *arg1, s32 arg2, s32 arg3)
{
    const char *s;
    char *t;

    if (arg2 != 0) {
        s = D_006AA9D8;
    } else if (arg3 != 0) {
        s = D_006AA9E8;
    } else {
        s = D_006AA9F8;
    }
    func_005A609C(arg1, s);
    t = func_004541C0(arg0);
    if (t == 0) {
        *arg1 = 0;
        return t;
    }
    func_005A5DC8(arg1, t);
    return arg1;
}

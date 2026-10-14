typedef int s32;

extern "C" int func_005A5A30(void *arg0, s32 arg1, const char *arg2, void *arg3, void *arg4);
extern "C" char *hModule__getName(void);
extern "C" void func_00486028(void *arg0, void *arg1, char *arg2);
extern char D_00698450[];
extern char D_00698458[];

struct S2 {
    char *p;
    char *c_str() {
        s32 n = *(s32 *)(p - 0x10);
        if (n != 0) {
            p[n] = 0;
            return p;
        }
        return D_00698458;
    }
};

extern "C" void func_00229D40(void *arg0, void *arg1, S2 *arg2) {
    char buf[0x80];
    func_005A5A30(buf, 0x80, D_00698450, hModule__getName(), arg1);
    func_00486028((char *)arg0 + 0xB0, buf, arg2->c_str());
}

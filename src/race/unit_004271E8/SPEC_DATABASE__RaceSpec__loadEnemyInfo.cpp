extern char D_006235A8[];
extern char D_006A6EE0[];

extern "C" void func_00447378(char *a0, int a1);
extern "C" int func_0057F260(char *s);
extern "C" int func_005A5A30(char *str, unsigned int size, const char *fmt, ...);
extern "C" void *func_004AE230(void *self, const char *path, int mode);

static inline char *step8(char *p) {
    return p + 8;
}

extern "C" int SPEC_DATABASE__RaceSpec__loadEnemyInfo(char *arg0, int arg1) {
    char obj[0x20];
    char *s0 = step8(D_006235A8);
    func_00447378(arg0, arg1);
    int n = func_0057F260(s0);
    char *buf = (char *)__builtin_alloca((((unsigned int)n + 0x26) >> 4) << 4);
    func_005A5A30(buf, n + 0x17, D_006A6EE0, s0, arg1);
    func_004AE230(obj, buf, 1);
    if (*(int *)obj == 9) {
        return 0;
    }
    *(int *)(arg0 + 0xA8) = *(int *)(obj + 0x10);
    return 1;
}

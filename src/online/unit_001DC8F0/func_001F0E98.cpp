extern char D_00645440[], D_00696B98[], D_00696BA0[], D_00696BC0[], D_00696BE0[], D_00696BE8[];
extern "C" int func_001F11C8();
extern "C" int func_001F0E48(void *) throw();
extern "C" int func_004EE7C8(void *);
extern "C" void func_004EE848(void *, int);
extern "C" void func_004EE8A0(void *, int, const char *, const char *, int);
extern "C" void func_004EE908(void *, int, int);
extern "C" void func_004EE950(void *, void *);
extern "C" void func_004EE970(void *, void *);
extern "C" void func_004EE9E0(void *, void *);
extern "C" void func_004EE990(void *, int, void *);
extern "C" int func_004EEE70(void *, const char *);
extern "C" int func_004EEF48(void *);
extern "C" void func_005D4AD8(const char *, ...);
extern "C" int func_001F0E98(void *ctx, char *cfg) {
    if (func_001F11C8()) return 1;
    void *obj[4];
    func_001F0E48(ctx);
    func_004EE7C8(obj);
    func_004EE8A0(obj, 3, D_00696B98, D_00696BA0, 1);
    func_004EE908(obj, *(int *)(cfg + 0x40), 0);
    if (*(int *)(cfg + 0x40) == 0) {
        func_004EE950(obj, cfg + 0x44);
        func_004EE970(obj, cfg + 0x84);
        func_004EE9E0(obj, cfg + 0xC4);
    }
    if (*(int *)(cfg + 0x104) == 0) {
        func_004EE990(obj, 0, cfg + 0x108);
        func_004EE990(obj, 1, cfg + 0x148);
    }
    char *base = D_00645440;
    func_004EEE70(base, (const char *)obj[0]);
    int ok = func_004EEF48(base);
    const char *fmt = D_00696BC0;
    const char *msg;
    if (ok) msg = D_00696BE0;
    else msg = D_00696BE8;
    func_005D4AD8(fmt, msg);
    func_004EE848(obj, 2);
    return 1;
}

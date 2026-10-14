/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Req { char pad[0x14]; void *cb; char pad2[8]; };
extern int D_00851478;
extern "C" void func_004FF0E8(void);
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" int func_00530388(void *);
extern "C" int func_00530338(void *);
extern "C" void func_004F8820(int, int) throw();
extern "C" void func_0053A860(void *);
extern "C" int func_0052FA88(void);
extern "C" void func_0053A890(void *, int *);
extern "C" void func_00578B10(int);
extern "C" int func_004FEFF8(int a0, int a1, int a2) {
    char tm[16];
    int sp10 = 0;
    Req req;
    int r, t;
    D_00851478 = 0;
    func_005A48D8(&req, 0, 0x1C);
    func_00530388(&req);
    req.cb = (void *)func_004FF0E8;
    r = func_00530338(&req);
    if (r != 0) {
        func_004F8820(a0, r);
        return 0;
    }
    func_0053A860(tm);
    do {
        func_0052FA88();
        func_0053A890(tm, &sp10);
        func_00578B10(0x2710);
        t = D_00851478 < a1;
        if (t == 0) break;
    } while (sp10 < a2);
    if (t != 0) return 0;
    return 1;
}

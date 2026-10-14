/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" int func_0052E8A0(int, int, int);
extern "C" int func_0052EF10(void *, void *);
extern "C" int func_0052FA88(void);
extern "C" int func_00534170(void *);
extern "C" void func_0053A860(void *);
extern "C" void func_0053A890(void *, unsigned int *);
extern "C" void func_00578B10(int);
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" void func_004FFA30(void);
extern "C" void func_004FFAC8(void);
extern "C" void func_004FFB00(void);
struct Request {
    int x0;
    void (*cb4)(void);
    void *p8;
    int xc, x10;
    void (*cb14)(void);
    int x18;
    void (*cb1c)(void);
    int x20, x24;
    char pad[0x98-0x28];
};
struct Frame {
    Request req;
    char pad98[8];
    int out[4];
    int state[4];
    char time[16];
    unsigned int elapsed;
    char pad[12];
};
extern "C" int func_004FF8E8(char *self, int arg1, int arg2, int arg3) {
    Frame sp;
    *(int *)(self + 0x3f40) = 1;
    func_005A48D8(&sp.req, 0, 0x98);
    func_005A48D8(sp.out, 0, 12);
    func_00534170(&sp.req);
    sp.req.cb4 = func_004FFA30;
    sp.req.cb14 = func_004FFAC8;
    sp.req.cb1c = func_004FFB00;
    sp.req.x24 = arg3;
    sp.req.p8 = sp.state;
    sp.state[0] = 0;
    sp.state[1] = 1;
    sp.elapsed = 0;
    func_0053A860(sp.time);
    do {
    if (sp.state[1]) {
        int r = func_0052EF10(&sp.req, sp.out);
        int flag = sp.state[1];
        if (r == 0) flag = 1;
        sp.state[1] = flag;
    }
    func_0052FA88();
    func_0053A890(sp.time, &sp.elapsed);
    func_00578B10(10000);
        if (sp.state[0]) break;
    } while (sp.elapsed < 10000U);
    if (sp.state[0]) {
        *(int *)(self + 0x3f3c) = sp.out[2];
        func_0052E8A0(sp.out[2], 0, 0);
        return 1;
    }
    return 0;
}

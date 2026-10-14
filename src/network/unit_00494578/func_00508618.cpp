struct Cfg {
    signed char b0;
    char b1;
    short h2;
    unsigned short h4;
    unsigned short h6;
};
struct Blob {
    int d[5];
};
struct Msg {
    int w0;
    Blob blob;
    int w28;
    int w2C;
    short h30;
    unsigned short h32;
    int w34;
};
extern int D_00853538;
extern char D_00853548[];
extern int D_0064A260;
extern int D_0064A2E4;
extern void *D_0064A2FC;
extern void *D_0064A300;
extern void *D_0064A2F4;
extern int D_0064A258;
extern int D_0064A214;
extern Blob D_0064A200;
extern "C" void func_005087D0(void);
extern "C" void func_00507A68(void);
extern "C" void func_00506A98(void);
extern "C" int func_0050A338(int);
extern "C" int func_0050A958(void);
extern "C" int func_0050A968(void);
extern "C" int func_0050B460(int, int, int, Msg *);
extern "C" void func_0053B310(char *, unsigned *);

extern "C" int func_00508618(int arg0, Cfg cfg, int arg2, int arg3) {
    Msg m;
    unsigned sp40;
    if (D_00853538 == 0 || func_0050A968() != 1) return -5;
    if (func_0050A958() == 0) return -6;
    if (D_0064A260 == 5) {
        func_0053B310(D_00853548, &sp40);
        if (sp40 < 0x1F) return -10;
        D_0064A260 = 3;
    }
    arg0 &= 0x40;
    if (arg0 != 0) func_0050A338(0x100);
    D_0064A2E4 = arg2;
    D_0064A2FC = (void *)func_005087D0;
    D_0064A300 = (void *)func_00507A68;
    D_0064A2F4 = (void *)func_00506A98;
    D_0064A258 = cfg.h2;
    if (cfg.b0 != 0) D_0064A260 = 1;
    m.w0 = arg3;
    m.blob = D_0064A200;
    m.w28 = D_0064A214;
    m.w2C = 6;
    m.h32 = cfg.h6;
    m.w34 = arg0 | 1;
    m.h30 = cfg.h4 * cfg.h6;
    return func_0050B460(1, 0xE0, 0x28, &m) == 0 ? 0 : -7;
}

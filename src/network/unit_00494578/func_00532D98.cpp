struct Settings { char pad[0x6C]; int a, b; };
struct Config { int a, size, max, c, d, timeout, b, e; void *buffer; void (*cb1)(); void (*cb2)(); void (*cb3)(); int spare; };
struct Api { char pad[0x68]; int (*init)(Config *, int *); };
extern Settings *D_0064B47C;
extern Api *D_0064B4BC;
extern int D_0064B4E4, D_0064B4E8, D_0064B4F0, D_0064B4F4, D_0064B4F8, D_0064B4FC;
extern char D_0086A848[];
extern "C" void func_00536B70();
extern "C" void func_00536BE0();
extern "C" void func_00536C10();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_00532D98() {
    if (D_0064B4F0 == 0) {
        Config cfg;
        func_005A48D8(&cfg, 0, 0x34);
        cfg.a = D_0064B47C->a;
        cfg.size = 0x40;
        cfg.max = 0x200;
        cfg.c = D_0064B4E4;
        cfg.d = D_0064B4E8;
        cfg.timeout = 30;
        cfg.b = D_0064B47C->b;
        cfg.e = D_0064B4F8;
        cfg.cb1 = func_00536B70;
        cfg.cb2 = func_00536BE0;
        cfg.cb3 = func_00536C10;
        if (D_0064B4FC) cfg.buffer = D_0086A848;
        else cfg.buffer = 0;
        if (D_0064B4BC->init(&cfg, &D_0064B4F4) != 0) return 0x25;
        D_0064B4F0 = 1;
    }
    return 0;
}

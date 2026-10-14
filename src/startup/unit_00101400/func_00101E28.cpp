struct V { char b[8]; };
struct Fn { int f, v; };
extern "C" Fn *func_00577170(Fn *t, const int &f, int v);
extern "C" Fn *func_00577188(Fn *t, const int &f, int v);
struct Mod { char data[0x28]; };

extern "C" Mod *func_00577198(Mod *m);
extern "C" Mod *func_00577240(Mod *m, const char *name, const Fn *f);
extern "C" Mod *func_00577290(Mod *m, const Fn *f);
extern "C" Mod *func_005772E8(Mod *m, const char *name, const Fn *f);
extern "C" Mod *func_00577340(Mod *m, const char *name, const char *args, const V *a, const V *b);

extern "C" void func_00101A70(void);
extern "C" void func_00101858(void);
extern "C" void func_00101970(void);
extern "C" void func_00102788(void);
extern "C" void func_00101930(void);
extern "C" void func_00101A10(void);
extern "C" void func_001026D0(void);
extern "C" void func_00102738(void);
extern "C" void func_00101AF0(void);
extern "C" void func_001027B0(void);
extern "C" void func_00101B18(void);

extern V D_00655880;
extern char *D_00617D90;
extern int D_006182A0;
extern char *D_006182BC;
extern char *D_006182C0;
extern Mod D_00617D98[18];
extern Mod D_00618068[9];
extern Mod D_006181D0[3];
extern Mod D_00618248[2];

extern "C" void func_00101E28(int init, int prio) {
    Fn t;
    if (prio == 0xFFFF && init == 1) {
        Mod *q;
        Mod *m = D_00617D98;
        {
            func_00577188(&t, (int)func_00101A70, 0);
            func_00577290(&m[0], &t);
        }
        {
            q = &m[1];
            func_00577188(&t, (int)func_00101858, 0);
            func_00577290(q, &t);
        }
        func_00577340(&m[2], "sio2man.irx", 0, &D_00655880, &D_00655880);
        func_00577340(&m[3], "mcman.irx", 0, &D_00655880, &D_00655880);
        func_00577340(&m[4], "mcserv.irx", 0, &D_00655880, &D_00655880);
        func_00577340(&m[5], "sio2d.irx", 0, &D_00655880, &D_00655880);
        func_00577340(&m[6], "dbcman.irx", 0, &D_00655880, &D_00655880);
        func_00577340(&m[7], D_006182A0 ? D_00617D90 + 5 : D_00617D90, 0, &D_00655880, &D_00655880);
        {
            q = &m[8];
            func_00577188(&t, (int)func_00101970, 0);
            func_00577290(q, &t);
        }
        func_00577340(&m[9], "libsd.irx", 0, &D_00655880, &D_00655880);
        func_00577340(&m[10], "usbd.irx", 0, &D_00655880, &D_00655880);
        func_00577340(&m[11], "inet.irx", 0, &D_00655880, &D_00655880);
        func_00577340(&m[12], "netcnf.irx", "icon=cdrom0:\\NET\\SYS_NET.ICO;1", &D_00655880, &D_00655880);
        func_00577340(&m[13], "inetctl.irx", "-no_decode", &D_00655880, &D_00655880);
        func_00577340(&m[14], "dev9.irx", 0, &D_00655880, &D_00655880);
        {
            q = &m[15];
            func_00577170(&t, (int)func_00102788, 0);
            func_00577240(q, "smap.irx", &t);
        }
        func_00577340(&m[16], "msifrpc.irx", 0, &D_00655880, &D_00655880);
        func_00577198(&m[17]);
    }
    if (prio == 0xFFFF && init == 1) {
        Mod *q;
        Mod *m = D_00618068;
        func_00577340(&m[0], "libpdi.irx", 0, &D_00655880, &D_00655880);
        {
            q = &m[1];
            func_00577188(&t, (int)func_00101930, 0);
            func_005772E8(q, "pdicdvd.irx", &t);
        }
        func_00577340(&m[2], "pdispu2.irx", 0, &D_00655880, &D_00655880);
        {
            q = &m[3];
            func_00577188(&t, (int)func_00101A10, 0);
            func_005772E8(q, "pdistr.irx", &t);
        }
        {
            q = &m[4];
            func_00577188(&t, (int)func_001026D0, 0);
            func_005772E8(q, "pdiusb.irx", &t);
        }
        {
            q = &m[5];
            func_00577188(&t, (int)func_00102738, 0);
            func_005772E8(q, "ustorage.irx", &t);
        }
        {
            q = &m[6];
            func_00577188(&t, (int)func_00101AF0, 0);
            func_005772E8(q, "lgdev.irx", &t);
        }
        func_00577340(&m[7], "powoff.irx", 0, &D_00655880, &D_00655880);
        func_00577198(&m[8]);
    }
    if (prio == 0xFFFF && init == 1) {
        Mod *q;
        Mod *m = D_006181D0;
        func_00577340(&m[0], D_006182BC, D_006182C0, &D_00655880, &D_00655880);
        {
            q = &m[1];
            func_00577188(&t, (int)func_001027B0, 0);
            func_00577290(q, &t);
        }
        func_00577198(&m[2]);
    }
    if (prio == 0xFFFF && init == 1) {
        Mod *q;
        Mod *m = D_00618248;
        {
            func_00577188(&t, (int)func_00101B18, 0);
            func_00577290(&m[0], &t);
        }
        func_00577198(&m[1]);
    }
}

typedef int s32;

struct Obj {
    char pad[0x10];
};

extern "C" int func_00577878(Obj *arg0, int arg1, int arg2, int arg3);
extern "C" void func_00577948(Obj *self);
extern "C" void func_00577C98(Obj *arg0, int arg1, const char *arg2, char *arg3);
extern "C" void func_00577CE0(Obj *arg0, int arg1);

extern s32 D_006182CC;
extern s32 D_006182A4;
extern s32 D_006182A8;
extern s32 D_006182AC;
extern s32 D_006182B0;
extern char D_00617D98[];
extern char D_00618068[];
extern char D_006181D0[];
extern char D_00618248[];
extern char D_006DE7E0[];
extern char D_0068CB60[];

extern "C" void func_00102308(void) {
    Obj buf;

    if (D_006182CC == 0) {
        char *s1 = D_006DE7E0;
        func_00577878((Obj *)s1, (s32)D_00617D98, D_006182A4, D_006182A8);
        char *p1 = D_00618068;
        s32 b0 = D_006182B0;
        s32 a0v = D_006182AC;
        func_00577878((Obj *)(s1 + 0xC), (s32)p1, a0v, b0);
        func_00577878((Obj *)(s1 + 0x18), (s32)D_006181D0, D_006182A4, D_006182A8);
        func_00577878((Obj *)(s1 + 0x24), (s32)D_00618248, 0, 0);
        func_00577878((Obj *)(s1 + 0x30), 0, 0, 0);
        D_006182CC = 1;
    }
    func_00577C98(&buf, 1, D_0068CB60, D_006DE7E0);
    func_00577948(&buf);
    func_00577CE0(&buf, 2);
}

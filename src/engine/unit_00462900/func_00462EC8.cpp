/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned char u8;

extern "C" void func_00462738(void *, char *, int) throw();
extern "C" int func_00462798(int) throw();
extern "C" void func_004627B0(void *, int) throw();
extern "C" int func_00462900(void *) throw();
extern "C" void func_00462EA8(void) throw();
extern "C" int func_0057F260(const char *) throw();
extern "C" int func_00594470(const char *, const char *, u32);
extern "C" int func_005A5A30(char *, u32, const char *, ...);
extern "C" char *func_005A609C(char *, const char *);

extern char D_00847580[];
extern char D_00847180[];
extern char D_00848650[];
extern u8 D_006D0E79[];
extern char D_006AB868[];

extern "C" void func_00462EC8(const char *arg0) {
    char buf[0x100];
    char name[0x40];
    char *p;
    if (arg0 != 0) {
        if (func_00594470(D_00847580, arg0, func_0057F260(arg0)) == 0) return;
        func_005A609C(D_00847580, arg0);
    } else {
        D_00847580[0] = D_006AB868[0];
    }
    func_005A609C(name, D_00847580);
    p = name;
    if (*p != 0) {
        char *q = name + 1;
        int c, r;
        do {
            c = *q;
            r = (((unsigned char *)0x006D0E79)[c] & 1) ? c + 0x20 : c;
            *q = r;
            q++;
        } while ((char)r != 0);
    }
    func_005A5A30(buf, 0x100, "%s%s%s.ins", "/sound/", "gt4shutter", name);
    func_00462EA8();
    func_004627B0(D_00847180, 0x400);
    func_00462798(0xA7040);
    func_00462738(D_00848650, buf, 0);
    func_00462900(D_00848650);
}

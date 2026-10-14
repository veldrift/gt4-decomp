struct Response { char p0[6]; char invalid; char p7[15]; short len; char data[1]; };
extern char *D_0064A2E8;
extern int D_0064A2EC;
extern int D_0064A1E4;
extern char D_006C14C0[], D_006C14F0[], D_006C1528[], D_006C1548[], D_006C1568[];
extern "C" int func_005063A8(void) throw();
extern "C" int func_005063E8(void) throw();
extern "C" void func_0057D9C0(const char *, ...);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" void func_005072B8(int a, int b, int c, Response *r) {
    if (r->invalid) func_0057D9C0(D_006C14C0);
    else func_0057D9C0(D_006C14F0, r->len);
    if (func_005063A8()) func_0057D9C0(D_006C1528);
    if (!D_0064A2E8) func_0057D9C0(D_006C1548);
    if (D_0064A2E8) {
        if (D_0064A1E4 - D_0064A2EC < r->len)
            return func_0057D9C0(D_006C1568);
        func_005A4724(D_0064A2E8 + D_0064A2EC, r->data, r->len);
        D_0064A2EC += r->len;
    }
    if (func_005063E8()) func_0057D9C0(D_006C1528);
}

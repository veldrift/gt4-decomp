struct Str { int data[25]; };
struct Request { int result; int pad[3]; Str name; short length; };
struct Hash {
    int pad[3];
    void (*get)(Hash *, Request *);
    int pad10;
    int (*add)(Hash *, const char *);
};
extern Hash *D_0064A550;
extern Hash *D_0064A55C;
extern int D_0064A560;
extern char D_006C21C8[];
extern "C" int func_0057F260(const char *) throw();
extern "C" void func_0057D9C0(const char *, ...);
extern "C" int func_0050F808(const char *p) {
    if (D_0064A550 == 0) return -13;
    if (p == 0) return -12;
    Request r;
    r.name = *(const Str *)(p + 0x70);
    r.length = func_0057F260(p + 0x70);
    int err = D_0064A55C->add(D_0064A55C, p);
    if (err != 0) {
        func_0057D9C0(D_006C21C8, err);
        return -13;
    }
    D_0064A55C->get(D_0064A55C, &r);
    D_0064A560 = r.result;
    return 0;
}

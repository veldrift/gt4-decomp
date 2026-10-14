struct Str { int data[25]; };
struct Request { int result; int pad[3]; Str name; short length; };
struct Hash {
    int pad[3];
    void (*get)(Hash *, Request *);
    int pad10;
    int (*add)(Hash *, const char *);
};
extern Hash *D_0064A550;
extern int D_0064A554;
extern char D_006C2010[], D_006C2040[];
extern "C" int func_0057F260(const char *) throw();
extern "C" void func_0057D9C0(const char *, ...);
extern "C" int func_0050F108(const char *name) {
    if (D_0064A550 == 0) return -13;
    if (name == 0) return -12;
    Request r;
    r.name = *(const Str *)name;
    r.length = func_0057F260(name);
    int err = D_0064A550->add(D_0064A550, name);
    if (err != 0) {
        func_0057D9C0(D_006C2010, err);
        return -13;
    }
    D_0064A550->get(D_0064A550, &r);
    D_0064A554 = r.result;
    func_0057D9C0(D_006C2040, 0);
    return 0;
}

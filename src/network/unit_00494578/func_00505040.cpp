struct Obj { char pad[0x1C]; int state; char name[16]; int value30, value34; char rest[0x4C-0x38]; };
struct Request { int type; void (*callback)(char *); char data[0x18]; };
extern short D_0064A164;
extern int D_008A0158, D_008A0120, D_0064A150;
extern char D_006C10E8[];
extern "C" void func_00504798(char *);
extern "C" void func_00504630(int) throw();
extern "C" void func_005047F8(int, void *) throw();
extern "C" long func_00504AC8() throw();
extern "C" int func_00504AE8() throw();
extern "C" void func_00504B78(void *) throw();
extern "C" int func_00506278(void *, int);
extern "C" int func_0052EAF8(signed char, int, int, int, int, int, void *);
extern "C" int func_0052EFC0(void *);
extern "C" int func_0052F010(void *, void *);
extern "C" int func_0052F5C8(void *);
extern "C" void func_0057D9C0(const char *, ...);
extern "C" int func_00505040(Obj *o, int a, int b) {
    Request req;
    int result[4];
    func_00506278(o, 0x15);
    long state = D_0064A164;
    if (state != 1) return -12;
    D_008A0158 = a;
    D_008A0120 = b;
    if (func_00504AC8() == state || func_00504AC8() == 2) {
        if (func_0052EFC0(&req)) return -5;
        func_00504B78(req.data);
        req.callback = func_00504798;
        func_00504630(4);
        func_005047F8(0, o);
        int r = func_0052F010(&req, result);
        if (r) {
            func_0057D9C0(D_006C10E8, r);
            func_00504630(0);
            return -5;
        }
        return r;
    }
    if (func_00504AC8() != 0 && func_00504AC8() != 4) return -13;
    {
        o->state = 1;
        func_0052F5C8(o->name);
        o->value30 = func_00504AE8();
        o->value34 = 0;
        return func_0052EAF8(0x40, D_0064A150, 0xFFFF, 3, 1, 0x4C, o) == 0 ? 0 : -5;
    }
}

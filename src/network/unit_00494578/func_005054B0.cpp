struct Input { char pad0[8]; char name[0x10]; int port; char pad1[0x18]; int world; char pad2[0x64]; int cb; };
struct Request { int f0; int f4; char data[0x9c]; void (*callback)(); char pad[0x98]; };
struct Result { int f0; int f4; int value; int fC; };
extern short D_0064A164;
extern int D_0064A154, D_0064A150;
extern char D_006C11C8[];
extern "C" void func_005061D8();
extern "C" void func_00504A90(int, int) throw();
extern "C" int func_00533650(Request *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" int func_0052EE68(Request *, Result *);
extern "C" int func_0057D9C0(const char *, ...);
extern "C" int func_005054B0(Input *in, int *out, int arg2) {
    Request q;
    Result result;
    if (D_0064A164 != 1) return -12;
    {
        func_00533650(&q);
        func_005A4724(q.data, in, 0x9c);
        q.f4 = D_0064A154;
        if (in->cb) {
            func_00504A90(in->cb, arg2);
            q.callback = func_005061D8;
        } else {
            func_00504A90(0, arg2);
        }
        int r = func_0052EE68(&q, &result);
        if (r) {
            func_0057D9C0(D_006C11C8, in->name, in->port, in->world, r);
            *out = -2;
            return -2;
        } else if (in->cb == 0) {
            D_0064A150 = result.value;
            *out = 0;
        }
        return r;
    }
}

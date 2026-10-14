struct Input { char data[0x104]; int f104; int f108; int f10c; int f110; };
struct Output { int value; int error; };
struct Request { int f0; int f4; char data[0x9c]; void (*callback)(); char padA8[0xc]; int fB4; int fB8; int fBC; char padC0[0xc]; char tail[0x68]; };
struct Result { int f0; int f4; int value; };
extern int D_0064A308, D_0064A30C, D_0064A338;
extern short D_0064A310;
extern "C" void func_0050AEC0();
extern "C" void func_0050AF50(int, int) throw();
extern "C" void func_0050AF88() throw();
extern "C" void func_0050E828();
extern "C" int func_00533650(Request *);
extern "C" void *func_005A4724(void *, const void *, unsigned);
extern "C" int func_0052EE68(Request *, Result *);
extern "C" int func_0050B498(Input *in, Output *out, int arg2) {
    Request q;
    Result result;
    if (D_0064A308 != 1) { out->value = 0; out->error = -15; return -15; }
    if (D_0064A30C != 0) { out->value = 0; out->error = -17; return -17; }
    func_00533650(&q);
    func_005A4724(q.data, in, 0x9c);
    q.f4 = in->f104;
    if (in->f108) {
        func_0050AF50(in->f108, arg2);
        q.callback = func_0050AEC0;
    } else { func_0050AF50(0, 0); }
    q.fB4 = in->f10c;
    q.fBC = in->f110;
    func_005A4724(q.tail, (char *)in + 0x9c, 0x68);
    int r = func_0052EE68(&q, &result);
    if (r) {
        D_0064A338 = r;
        out->value = result.value;
        out->error = -2;
        func_0050AF88();
        return -2;
    }
    if (in->f108 == 0) {
        D_0064A30C = result.value;
        if (D_0064A310 == 1) func_0050E828();
    }
    out->value = result.value;
    out->error = 0;
    return 0;
}

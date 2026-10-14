/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Copy { char data[100]; };
struct Config { int words[5]; };
struct Request { int arg; Config cfg; char data[100]; int op; int value; };
extern int D_00853538;
extern int D_0064A2DC;
extern void (*D_0064A304)();
extern Config D_0064A200;
extern "C" void func_005075C0();
extern "C" int func_0050A958();
extern "C" int func_0050A968();
extern "C" int func_0050B460(int, int, int, Request *);
extern "C" int func_005A6AB0(void *, void *, int) throw();
extern "C" int func_005082B8(Copy input, int a1, int a2, int a3) {
    Request req;
    int status;
    if (D_00853538 == 0 || (status = func_0050A968()) != 1) return -5;
    if (func_0050A958() == 0) return -6;
    D_0064A2DC = a2;
    D_0064A304 = func_005075C0;
    req.arg = a3;
    req.cfg = D_0064A200;
    Request *p = &req;
    func_005A6AB0(p->data, &input, 100);
    p->op = status;
    p->value = a1;
    p->data[99] = 0;
    int r = func_0050B460(1, 0xe4, 0x84, p);
    return r == 0 ? 0 : -7;
}

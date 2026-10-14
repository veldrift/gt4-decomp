extern "C" void func_0050FAD8();
struct Request { int size; int data; void (*callback)(); int zero; };
struct Driver { char pad[0x2c]; int (*read)(Driver *, Request *); };
extern Driver *D_0064A55C;
extern int D_0064A564;
extern "C" int func_0050FD00(int data, int n, int *result) {
    Driver *d = D_0064A55C;
    Request req;
    req.size = n * 4;
    D_0064A564 = 0;
    req.data = data;
    req.callback = func_0050FAD8;
    req.zero = 0;
    d->read(d, &req);
    *result = D_0064A564;
    return 0;
}

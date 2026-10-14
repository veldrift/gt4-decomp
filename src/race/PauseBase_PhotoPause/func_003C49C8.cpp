/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Pair1 { char pad[0xD84]; int a; int b; };
struct Pair2 { char pad[0xD8C]; int a; int b; };
extern "C" void func_00372128(int, int);
extern "C" void func_00373CC8(int, int);
extern "C" int RaceBase__initMonitor(void *);
extern "C" void *func_003C3F98(void *) throw();
extern "C" int func_003C3FA0(void *) throw();
extern "C" int PhotoPause__deleteAnimInst(void *) throw();
extern "C" void func_003C49C8(void *arg0) {
    func_00372128(func_003C3FA0(arg0), 0);
    func_00373CC8(func_003C3FA0(arg0), 0);
    Pair1 *p = (Pair1 *)func_003C3F98(arg0);
    p->a = 0;
    p->b = 0;
    Pair2 *q = (Pair2 *)func_003C3F98(arg0);
    q->a = 0;
    q->b = 0;
    RaceBase__initMonitor(func_003C3F98(arg0));
    PhotoPause__deleteAnimInst(arg0);
}

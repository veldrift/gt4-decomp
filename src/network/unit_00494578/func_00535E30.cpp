/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned long long u64 __attribute__((aligned(4)));
typedef void (*F6)(int, void *, int, int, int, int);
typedef void (*F4)(int, void *, int, int);
struct Word64 { u64 value; };
struct Ent { Word64 a; int b; int mode; F6 fn; int time; int arg1; int arg2; };
struct Dst { char pad[0x60]; Word64 a; int b; };
extern Dst *D_0064B47C;
extern Ent D_008A05B0[];
extern "C" int func_0053A7B8(int *);
extern "C" int func_00531878(void *, void *);
extern "C" int func_00535E30(void) {
    int sp[8];
    unsigned i;
    Ent *e;
    func_0053A7B8(&sp[4]);
    e = D_008A05B0;
    for (i = 0; i < 0x7F; i++, e++) {
        if (e->fn != 0 && sp[4] - e->time - 30000 > 0) {
            func_00531878(sp, e);
            Dst *d = D_0064B47C;
            d->a = e->a;
            D_0064B47C->b = e->b;
            if (e->mode == 1) {
                e->fn(0xE, sp, 0, 0, e->arg1, e->arg2);
            } else {
                ((F4)e->fn)(0xE, sp, 0, 0);
            }
            e->fn = 0;
        }
    }
    return 0;
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
struct O { int f0; char pad[0x90]; int f94; };
extern "C" int func_004EFA18(O *, int, int *);
extern "C" int func_004EF1B0(O *o) {
    int sp;
    int t;
    if (o->f0 == 0) return -2;
    t = func_004EFA18(o, o->f94, &sp);
    return t >= 0 ? sp : t;
}

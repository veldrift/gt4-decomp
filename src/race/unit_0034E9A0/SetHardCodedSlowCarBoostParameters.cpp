/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x22]; signed char f22; char gap[5]; signed char f28,f29,f2a; };
extern "C" int SetHardCodedSlowCarBoostParameters(Obj *p, int mode) {
    int r = 0;
    switch (mode) {
    case 1:
        p->f22 = 0;
        p->f28 = 7;
        p->f29 = 20;
        p->f2a = 20;
        r = 1;
        break;
    case 2:
        p->f22 = 0;
        p->f28 = 20;
        p->f29 = 10;
        p->f2a = 20;
        r = 1;
        break;
    default:
        p->f22 = -1;
        p->f28 = 0;
        p->f29 = 0;
        p->f2a = 0;
        break;
    }
    return r;
}

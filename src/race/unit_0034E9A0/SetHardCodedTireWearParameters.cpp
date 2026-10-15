/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x2c]; signed char f2c,f2d,f2e,f2f,f30,f31,f32,f33,f34; };
extern "C" int SetHardCodedTireWearParameters(Obj *p, int mode) {
    switch (mode) {
    case 1:
        p->f2f = mode;
        p->f30 = 5;
        p->f31 = 4;
        p->f32 = 0;
        p->f33 = 5;
        p->f34 = 5;
        p->f2c = 8;
        p->f2d = 40;
        p->f2e = 12;
        break;
    case 2:
        p->f2f = 1;
        p->f30 = 5;
        p->f31 = 3;
        p->f32 = 0;
        p->f33 = 4;
        p->f34 = 5;
        p->f2c = 6;
        p->f2d = 40;
        p->f2e = 12;
        break;
    default:
        p->f2f = 0;
        p->f30 = 0;
        p->f31 = 0;
        p->f33 = 0;
        p->f34 = 0;
        p->f2c = 0;
        p->f2d = 0;
        p->f2e = 0;
        break;
    }
    return mode != 0;
}

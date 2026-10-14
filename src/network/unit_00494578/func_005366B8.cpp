struct Msg { void *f0; int f4; int f8; int fC; int f10; };
struct O { char pad[0x12C]; void (*f12C)(Msg *); int f130; char pad134[0x10]; int f144; char pad148[0x10]; int f158; };
extern "C" void *func_005A48D8(void *, int, unsigned);
extern "C" void func_005366B8(int code, O *o) {
    if (o != 0 && o->f158 == 2 && o->f12C != 0) {
        Msg m;
        func_005A48D8(&m, 0, 0x14);
        o->f144 = 4;
        m.f4 = 4;
        m.f8 = 1;
        m.f0 = o;
        if (code == 0xD4E9) m.fC = 0xE;
        else m.fC = 0x25;
        m.f10 = o->f130;
        o->f12C(&m);
    }
}

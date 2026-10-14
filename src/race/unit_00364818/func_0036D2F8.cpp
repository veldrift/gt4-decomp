/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef float f32;

struct State {u8 state; char pad[15]; u8 values[8];};
struct Obj {
    char pad0[0x234];
    u8 state;
    char pad235[3];
};
struct Wt { char pad0[0x10]; f32 f[8]; };
struct Pair {
    char pad0[2];
    u8 count;
    char pad3[9];
    u8 a[4];
    u8 b[0x14];
    u8 c[1];
    int get(int i) const { return i < count ? b[i] : 0; }
};
struct Slot { char pad0[0x20]; f32 f20; char pad24[0x60]; f32 f84; char pad88[0x64]; };
struct Car {
    char pad0[0x10];
    Obj *obj;
    char pad14[0x150];
    Slot slots[1];
};
struct Win { char pad0[0x468]; f32 f468; char pad46c[0xD0]; f32 f53C; };

extern "C" void func_00356418();
extern "C" Pair *func_00359510(Obj *);

extern "C" void func_0036D2F8(Car *self) {
    Obj *obj = self->obj;
    State *st = (State*)&obj->state;
    Win *win = (Win *)((char *)self + 0x104);
    if (st->state == 7)
        func_00356418();
    Pair *p = func_00359510(obj);
    for (int i = 0; i < p->count; i++) {
        int x = p->a[i];
        int y = p->c[x];
        if (y == 0x7F)
            continue;
        int m = p->get(i);
        int v = st->values[m];
        if (v < 0)
            continue;
        if (v < 6)
            continue;
        if (v >= 8)
            continue;
        f32 spd = win->f53C;
        if (spd < 0x1.638e36p+1f || spd > 0x1.8ffffep+5f)
            continue;
        f32 steer = win->f468;
        f32 t = steer < 0.0f ? -steer : steer;
        t = t * 0x1.e8ec90p+1f;
        if (t > 1.0f)
            t = 1.0f;
        Wt *wt = (Wt *)((char *)obj + 0x238);
        f32 k = t * wt->f[m];
        if (k == 0.0f)
            continue;
        Slot *s0 = &self->slots[x];
        Slot *s1 = &self->slots[y];
        f32 mid = (s0->f20 + s1->f20) * 0.5f;
        f32 d = mid * 0.125f;
        if (steer > 0.0f)
            mid += d;
        else if (steer < 0.0f)
            mid -= d;
        f32 lo = k * 0.4375f;
        f32 hi = k * 0.5625f;
        f32 cur = *(volatile f32*)&s1->f20;
        if (cur < mid) {
            s1->f84 = s1->f84 + lo;
            s0->f84 = s0->f84 - hi;
        } else if (mid < cur) {
            s1->f84 = s1->f84 - hi;
            s0->f84 = s0->f84 + lo;
        }
    }
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { char pad[0xC]; float time; };
struct Settings { char pad[0xE0]; int mode; };
struct Race { Settings *settings; };
struct Sub { char pad[0x440]; unsigned char index; char pad441[0x6B]; short lap; };
struct Arg { int unk0; Race *race; char pad8[0xFC]; Sub sub; };
struct Obj { char pad[0xD4]; char manager[0xFC]; int disabled; };
extern "C" Rec *func_00346A28(int);
extern "C" void AutomobileControlRecord__Manager__reset(int);
extern "C" int func_0034DB30(Race *, int);
extern "C" void func_0035ABA8(Race *, int, Rec *);
extern "C" void func_003F58B0(Obj *self, Arg *arg, int lap, float t) {
    Sub *s;
    if (self->disabled == 0) {
        s = &arg->sub;
        int m = (int)self + 0xD4;
        Rec *r = func_00346A28(m);
        Race *race = arg->race;
        func_0035ABA8(race, s->index, r);
        s->lap = lap + 1;
        AutomobileControlRecord__Manager__reset(m);
        t -= r->time;
        if (t < 0.0f) {
            if (race->settings->mode == 0 && s->index == 1) {
                func_0034DB30(race, 1);
            }
            t += 1.0f;
        }
        *(float *)((char *)arg + 0x554) = t;
    }
}

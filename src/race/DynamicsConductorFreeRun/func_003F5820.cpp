/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rec { char pad[2]; unsigned char flag, state; char pad4[8]; float time; };
struct Obj { char pad[0x148]; void *manager; };
struct Arg { int unk0; void *race; char pad8[0x53C]; unsigned char index; };
extern "C" Rec *func_00346A28(void *);
extern "C" int func_00358468(void *, int);
extern "C" void func_0035AB08(void *, Rec *, int);
extern "C" int func_00426C10(Obj *);
extern "C" int func_003F5820(Obj *self, Arg *arg, int flag, float t) {
    Rec *r = func_00346A28(self->manager);
    void *race = arg->race;
    func_0035AB08(race, r, arg->index);
    r->time = t;
    r->flag = flag;
    r->state = func_00358468(race, 0x32);
    return func_00426C10(self);
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Obj {
    char pad[0x18];
    s32 a;
    s32 b;
};

extern "C" void Concourse__render(Obj *) throw();

extern "C" void LicenseConcourse__render(Obj *o) {
    if (o->a != 0 && o->b != 0) {
        Concourse__render(o);
    }
}

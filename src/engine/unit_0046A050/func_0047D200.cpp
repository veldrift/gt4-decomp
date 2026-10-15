/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { int id; signed char v; char pad[0x117]; int set; };
extern unsigned char D_00624820[];
extern "C" int func_0047D170(Obj *) throw();
extern "C" int func_0047D200(Obj *o, signed char c) {
    if (c == 0 || !o->set || o->id < 0) return 0;
    if (c < 20) return o->id == D_00624820[c];
    return func_0047D170(o) == c;
}

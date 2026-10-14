/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char p[0xA0]; unsigned f; };
struct Row { int v; char pad[0x1C]; };
extern char D_006235A8[];
extern "C" int SPEC_DATABASE__DatabaseStorage__getRow_2(void *, int, int, void *);

static inline bool getRow(unsigned long k, Row *r) {
    return SPEC_DATABASE__DatabaseStorage__getRow_2(D_006235A8, (int)k, 0x22, r) != 0;
}

extern "C" int func_00447730(Obj *o) {
    Row r;
    unsigned long k = o->f;
    if (getRow(k, &r)) return r.v;
    return -1;
}

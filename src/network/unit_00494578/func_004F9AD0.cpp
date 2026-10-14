/* compiler: ee-gcc2.96-no-strict-aliasing */
struct E {
    char pad[4];
    char c4;
    char c5;
    char rest[0xE4 - 6];
};
struct O {
    char pad0[0xCC4];
    int mCC4;
    char pad1[0xFC0 - 0xCC8];
    int mFC0;
    int mFC4;
    char pad2[0x2280 - 0xFC8];
    E e[1];
};
extern "C" void func_00576100(O *);
extern "C" void func_00576140(O *);
extern "C" int func_004F9E60(O *, int);

extern "C" void func_004F9AD0(O *o) {
    func_00576100(o);
    o->mFC0 = 1;
    o->mFC4 = 1;
    int i = func_004F9E60(o, o->mCC4);
    if (i != -1) {
        int offset = i * 0xE4;
        offset = offset + 0x2280;
        E *e = (E *)((char *)o + offset);
        e->c4 = 1;
        e->c5 = 0;
    }
    func_00576140(o);
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { int words[0xB4/4]; };
struct Obj { char pad[0x5A8]; char *buffer; };
extern Obj D_00645570;
extern char D_006C0DF0[];
extern "C" int func_004F0C38(Obj *, const char *);
extern "C" int func_004F0B08(Obj *, Data *);
struct Guard {
    Obj *obj; Data *data;
    Guard(Obj *o, Data *d) : obj(o), data(d) {}
    ~Guard() { func_004F0B08(obj, data); }
};
extern "C" void func_004FFFE8(Data *data, Obj *obj) {
    if (!obj) obj = &D_00645570;
    Guard guard(obj, data);
    if (func_004F0C38(obj, D_006C0DF0)) return;
    *(Data *)(obj->buffer + 0x1D8) = *data;
}

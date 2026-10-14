/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Obj { char pad[0x3c]; void *data; };
struct Entry { void (*fn)(); int zero; char pad[0x18]; };
struct Opt { int a,b; char pad[8]; };
extern Obj *D_006318C0, *D_006318C4;
extern char D_006318D0[];
extern "C" void func_004B0210();
extern "C" void func_004B0230();
extern "C" Obj *func_00575098(Entry *, void *);
extern "C" void *func_00578610(int);
extern "C" int func_005788B8(Obj *);
extern "C" Obj *func_00578968(Entry *, Opt *, void *);
extern "C" int func_00578B50(unsigned, int);
extern "C" void func_004B0708() {
    Entry entry;
    Opt opt;
    if (!D_006318C0) {
        Opt *options = &opt;
        entry.fn = func_004B0210;
        entry.zero = 0;
        options->a = 0;
        options->b = 0x2800;
        Obj *p = func_00578968(&entry, options, func_00578610(func_00578B50(1, 1)));
        D_006318C0 = p;
        p->data = D_006318D0;
        func_005788B8(D_006318C0);
    }
    if (!D_006318C4) {
        entry.fn = func_004B0230;
        entry.zero = 0;
        Obj *p = func_00575098(&entry, func_00578610(func_00578B50(3, -1)));
        D_006318C4 = p;
        p->data = D_006318D0;
        func_005788B8(D_006318C4);
    }
}

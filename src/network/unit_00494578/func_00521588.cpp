struct Obj { char pad[8]; int id; int mode; };
extern "C" int func_005220F8(Obj *);
extern "C" int func_00523210(int, int *);
extern "C" int func_00521588(Obj *arg0, int *arg1) {
    if (func_005220F8(arg0) == 0) return 2;
    int mode = arg0->mode;
    if (!(mode == 0 || mode == 2)) {
        return 0xC355;
    }
    return func_00523210(arg0->id, arg1);
}

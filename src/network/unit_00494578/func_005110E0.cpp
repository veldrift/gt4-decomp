struct Inner { char pad[0x18]; int value; };
struct Obj { char pad0[0x20]; void (*cb)(); char pad24[0x40]; struct Inner *inner; };
extern "C" void func_00511648();
extern "C" int func_005110E0(struct Obj *arg0, int arg1) {
    if (arg0 == 0 || arg1 == 0) return 1;
    arg0->inner->value = arg1;
    arg0->cb = func_00511648;
    return 0;
}

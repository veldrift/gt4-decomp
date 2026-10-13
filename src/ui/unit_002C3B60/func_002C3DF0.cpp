typedef int s32;
struct Obj {
    char pad[0x14];
    s32 f14;
};
extern "C" void func_00548228(s32 *a, s32 *b, s32 *c);
extern "C" s32 func_002C3DF0(Obj *o) {
    s32 v[3];
    if (o->f14 == 0) return 0;
    func_00548228(&v[0], &v[1], &v[2]);
    return v[2] == 0;
}

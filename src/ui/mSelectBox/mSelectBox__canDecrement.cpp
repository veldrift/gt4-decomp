/* compiler: ee-gcc2.96-nosib */
typedef int s32;
typedef float f32;

struct Obj {
    char pad[0xEC];
    f32 unkEC;
};

extern "C" bool func_0057CE80(Obj *o);

extern "C" s32 mSelectBox__canDecrement(Obj *arg0) {
    s32 v;

    if (func_0057CE80((Obj *)((char *)arg0 + 0xBC)) != 0) {
        return 0;
    }
    v = 1;
    if (!(arg0->unkEC < 0.0f)) {
        v = 0;
    }
    return v;
}

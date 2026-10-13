typedef int s32;
typedef float f32;

struct Obj {
    char pad[0x2DC];
    s32 unk2DC;
};

struct Cell {
    char pad[0x64];
    f32 v;
};

extern "C" f32 func_0045AC60(Obj *arg0, s32 arg1) {
    s32 k = 0x16C;
    s32 p = arg0->unk2DC * k;
    s32 q = ((((arg1 * 2) + arg1) * 4) + arg1) * 4;
    s32 r = p + (s32)arg0;
    return ((Cell *)(q + r))->v;
}

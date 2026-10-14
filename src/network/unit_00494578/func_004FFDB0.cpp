typedef int s32;

struct Obj {
    char pad[0x3F20];
    s32 unk3F20;
    s32 unk3F24;
};

extern "C" s32 func_004FFDB0(Obj *arg0) {
    if (arg0->unk3F20 == 0) {
        return 0;
    }
    arg0->unk3F24 = 1;
    return 1;
}

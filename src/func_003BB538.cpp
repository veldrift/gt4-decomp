typedef int s32;

struct Obj {
    char pad[0x120];
    s32 unk120;
};

extern "C" s32 RaceInformation__virtual_73(struct Obj *arg0, s32 arg1) {
    s32 v = arg0->unk120;
    if (v < 0) {
        return 0;
    }
    return v ? v : arg1;
}

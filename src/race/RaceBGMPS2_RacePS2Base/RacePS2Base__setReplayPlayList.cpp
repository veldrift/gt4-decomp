struct Block {
    long w[0x102];
};

struct Obj {
    char pad[0xD150];
    Block block;
};

extern "C" void RacePS2Base__setReplayPlayList(Obj *o, const Block *b) {
    o->block = *b;
}

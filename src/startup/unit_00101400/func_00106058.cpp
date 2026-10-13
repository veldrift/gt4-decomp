typedef int s32;

struct Entry {
    s32 id;
    s32 a;
    s32 b;
    s32 c;
};

extern Entry D_00618648[];

extern "C" Entry *func_00106058(s32 id) {
    Entry *e = D_00618648;
    s32 i;

    for (i = 0; i < 8; i++, e++) {
        if (e->id == id) {
            return e;
        }
    }
    return D_00618648 + 8;
}

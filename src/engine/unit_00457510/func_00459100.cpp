typedef int s32;

struct Node {
    char pad0[4];
    Node *prev;
    char pad8[0x4];
    s32 unkC;
    s32 unk10;
    s32 unk14;
};

extern "C" void func_00454410(s32 arg0);
extern "C" void func_00458238(s32 arg0);

extern "C" void func_00459100(Node *arg0) {
    s32 offset = (char *)arg0 - (char *)arg0->prev;
    if (offset != 0) {
        arg0->prev = arg0;
        if (arg0->unk10 != 0) {
            s32 *p = (s32 *)((char *)arg0 + 0x10);
            *p = *p + offset;
            func_00454410(*p);
        }
        if (arg0->unk14 != 0) {
            s32 *q = (s32 *)((char *)arg0 + 0x14);
            *q = *q + offset;
            func_00458238(*q);
        }
    }
}

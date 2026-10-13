typedef int s32;
typedef short s16;

struct Node {
    char *obj;
    s32 pad4;
    Node *next;
};

struct VEntry2 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32);
};

struct VEntry4 {
    s16 delta;
    s16 index;
    s32 (*fn)(void *, s32, s32, s32);
};

extern char D_00631880[];
extern Node *D_006318B0;

extern "C" void func_00576788(s32 a0);
extern "C" void func_005767C0(s32 a0);

extern "C" s32 func_004ACF30(s32 arg0, s32 arg1, s32 arg2) {
    s32 r = -1;
    Node *n;
    char *o;

    func_00576788((s32)D_00631880);
    n = D_006318B0;
    if (n != 0) {
        do {
            o = n->obj;
            VEntry2 *e = (VEntry2 *)(*(char **)(o + 0xA4) + 0x38);
            if (e->fn(o + e->delta, arg0) != 0) {
                VEntry4 *e4 = (VEntry4 *)(*(char **)(o + 0xA4) + 0x48);
                r = e4->fn(o + e4->delta, arg0, arg1, arg2);
                break;
            }
            n = n->next;
        } while (n != 0);
    }
    func_005767C0((s32)D_00631880);
    return r;
}

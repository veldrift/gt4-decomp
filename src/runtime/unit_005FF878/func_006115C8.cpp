typedef int s32;
typedef short s16;

extern char D_00655340[];

struct VEntry {
    s16 delta;
    s16 index;
    void (*fn)(void *, s32);
};

struct Obj {
    char pad0[0x30];
    s32 type;
    char pad34[0x30];
    char *ent;
    char pad68[8];
};

extern "C" void func_00576100(Obj *arg0);
extern "C" void func_00576140(Obj *arg0);

extern "C" void func_006115C8(void *unused, Obj *base, s32 count, s32 arg3, s32 arg4) {
    Obj *o;
    s32 i;

    o = base;
    func_00576100((Obj *)D_00655340);
    if (arg4 != 0) {
        i = 0;
        if (count > 0) {
            do {
                if (o->type == arg4) {
                    VEntry *e = (VEntry *)(o->ent + 0x18);
                    e->fn((char *)o + e->delta, arg3);
                }
                i++;
                o++;
            } while (i < count);
        }
    } else if (count > 0) {
        do {
            VEntry *e = (VEntry *)(o->ent + 0x18);
            count--;
            e->fn((char *)o + e->delta, arg3);
            o++;
        } while (count != 0);
    }
    func_00576140((Obj *)D_00655340);
}

typedef int s32;
typedef unsigned int u32;

struct Sub {
    char pad0[0x20];
    s32 unk20;
};

struct Obj {
    char pad0[0x2C];
    struct Sub *unk2C;
};

struct Item {
    s32 unk0;
    s32 unk4;
    s32 unk8;
};

extern char D_0069E278[];
extern char HTryCatchFrame__vtable[];

void *func_00326750(unsigned int size, int align, const char *name);
extern "C" int func_00318E68(struct Obj *o, struct Item *item);

extern "C" int HTryCatchFrame__structor_0(struct Obj *arg0, s32 arg1) {
    struct Item *temp_v0;
    s32 temp_a2;

    temp_v0 = (struct Item *)func_00326750(0xC, 4, D_0069E278);
    temp_a2 = arg0->unk2C->unk20;
    temp_v0->unk4 = arg1;
    temp_v0->unk0 = (s32)HTryCatchFrame__vtable;
    temp_v0->unk8 = temp_a2;
    return func_00318E68(arg0, temp_v0);
}

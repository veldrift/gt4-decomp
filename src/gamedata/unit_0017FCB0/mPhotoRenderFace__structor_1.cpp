typedef int s32;

extern "C" void func_001C95B0(void *arg0, s32 arg1);
extern "C" void func_00255548(void *arg0, s32 arg1);
extern "C" void func_00326798(void *arg0, s32 arg1, s32 arg2, const char *arg3);
extern "C" void func_00575DA0(s32 arg0);

extern char D_0065D7C8[];
extern char D_006923C8[];

struct mPhotoRenderFace_layout {
    char pad0[0x4];
    void *unk4;
    char pad8[0x98];
    s32 unkA0;
    char padA4[0x4];
    s32 unkA8;
    char padAC[0x1C];
    s32 unkC8;
};

extern "C" void func_00197AD8(void *arg0, s32 arg1) {
    struct mPhotoRenderFace_layout *self = (struct mPhotoRenderFace_layout *)arg0;
    s32 slot[4];
    s32 temp_a0;
    s32 temp_a0_2;

    self->unk4 = (void *)D_0065D7C8;
    slot[0] = self->unkC8;
    if (slot[0] != 0) {
        func_00575DA0(slot[0]);
    }
    temp_a0 = self->unkA8;
    if (temp_a0 != 0) {
        func_00575DA0(temp_a0);
    }
    temp_a0_2 = self->unkA0;
    if (temp_a0_2 != 0) {
        func_001C95B0((void *)temp_a0_2, 3);
    }
    func_00255548(arg0, 0);
    if (arg1 & 1) {
        func_00326798(arg0, 0x100, 4, (const char *)D_006923C8);
    }
}

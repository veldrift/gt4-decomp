extern "C" int func_00575E60(int arg0, int arg1);
extern "C" void func_005A48D8(void *p, int c, int n);

struct func_00611150_arg0 {
    int unk0;
    int unk4;
    int unk8;
    int unkC;
    int unk10;
    int unk14;
    int unk18;
    int unk1C;
    int unk20;
};

extern "C" int func_00611150(struct func_00611150_arg0 *arg0, int arg1) {
    int var_v0 = 0;
    int temp_v1;

    if (arg1 != 0) {
        var_v0 = func_00575E60(0x10, arg1);
    }
    arg0->unk0 = var_v0;
    func_005A48D8((void *)var_v0, 0, 4);
    arg0->unk4 = arg1;
    temp_v1 = arg0->unk0;
    arg0->unkC = arg1;
    arg0->unk14 = arg1;
    arg0->unk8 = 0;
    arg0->unk10 = 0;
    arg0->unk18 = 0;
    arg0->unk1C = temp_v1;
    arg0->unk20 = temp_v1;
    return temp_v1 != 0;
}

extern "C" void func_00574D78(void *arg0);

struct func_00328800_arg0 {
    char pad0[0x30];
    int unk30;
    int unk34;
    int unk38;
    int unk3C;
    int unk40;
    int unk44;
    int unk48;
    int unk4C;
};

extern "C" void func_00328800(struct func_00328800_arg0 *arg0, int arg1, int arg2) {
    func_00574D78(arg0);
    arg0->unk40 = arg1;
    arg0->unk44 = arg2;
    arg0->unk30 = 0;
    arg0->unk34 = 0;
    arg0->unk38 = 0;
    arg0->unk3C = 0;
    arg0->unk48 = 0;
    arg0->unk4C = 0;
}

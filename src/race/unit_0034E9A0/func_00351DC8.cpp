struct Obj {
    char pad0[0x10];
    char *unk10;
};

struct Sub {
    char pad0[0x520];
    unsigned char unk520;
    char pad1;
    unsigned char unk522;
};

extern "C" int func_0036C8E8(Obj *self);
extern "C" int func_003F1F88(char *arg0);
extern "C" void func_0035A5F8(char *arg0, int arg1, signed char arg2);
extern "C" void func_0036BEB8(Obj *arg0, int arg1);

extern "C" void func_00351DC8(Obj *arg0) {
    int temp_v0;
    int temp_v1;
    Sub *temp_s0;

    temp_v0 = func_0036C8E8(arg0);
    temp_s0 = (Sub *)((char *)arg0 + 0x104);
    if (temp_v0 == -1) {
        return;
    }
    if (temp_s0->unk522 != 0) {
        if (temp_v0 == 0 || temp_s0->unk520 == 0) {
            temp_s0->unk522 = 2;
        } else {
            if (func_003F1F88(arg0->unk10 + 0x234) == 0) {
                temp_s0->unk522 = 3;
            }
            temp_v1 = temp_s0->unk520;
            if (temp_v1 < temp_v0) {
                func_0035A5F8((char *)arg0, 0, 1);
            } else if (temp_v0 < temp_v1) {
                func_0035A5F8((char *)arg0, 0, -1);
            }
        }
    }
    return func_0036BEB8(arg0, temp_v0);
}

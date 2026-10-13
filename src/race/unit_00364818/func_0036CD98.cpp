struct func_0036CD98_arg0 {
    char pad0[0x110];
    unsigned char unk110;
    unsigned char unk111;
};

struct func_0036CD98_arg1 {
    char pad0[0x200];
    unsigned short unk200;
    char pad202[0x60];
    unsigned short unk262;
    char pad264[0xE10];
    unsigned char unk1074;
    unsigned char unk1075;
};

extern "C" void func_0036CD98(struct func_0036CD98_arg0 *arg0, struct func_0036CD98_arg1 *arg1) {
    unsigned char v = arg0->unk110;
    if (v != 0) {
        arg1->unk1074 = v;
    } else {
        arg1->unk1074 = arg1->unk262 / 100u;
    }

    unsigned char a = arg0->unk111;
    if (a != 0) {
        arg1->unk1075 = a;
        return;
    }
    arg1->unk1075 = (int) (arg1->unk200 + 0x384) / 1000;
}

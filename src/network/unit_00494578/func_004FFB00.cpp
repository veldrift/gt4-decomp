typedef int s32;

extern "C" void func_00503358(s32 arg0);

struct Obj_004FFB00 {
    char pad[8];
    s32 unk8;
};

struct G_004FFB00 {
    char pad0[0xFBC];
    s32 flag;
    char pad1[0x2238 - 0xFBC - 4];
    s32 cnt;
};

extern struct G_004FFB00 D_00645570;

extern "C" void func_004FFB00(Obj_004FFB00 *arg0) {
    func_00503358(arg0->unk8);
    s32 c = D_00645570.cnt;
    D_00645570.flag = 1;
    D_00645570.cnt = c - 1;
}

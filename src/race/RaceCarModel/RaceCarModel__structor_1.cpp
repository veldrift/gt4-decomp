typedef int s32;

extern "C" void func_0038FB58(s32 *arg0);
extern "C" void func_003B1890(void *arg0, s32 arg1);
extern "C" void func_004574A0(void *arg0, s32 arg1);
extern "C" void func_005C1628(char *arg0);

extern char D_0067DE00[];
extern char D_0067DF68[];
extern char D_006885F0[];
extern char D_00688628[];
extern char D_0067DFA0[];

struct func_0038F9B8_a {
    char pad0[8];
    s32 unk8;
};

struct func_0038F9B8_b {
    s32 unk0;
};

struct func_0038F9B8_c {
    char pad0[0x7DC];
    s32 unk7DC;
};

extern "C" void func_0038F9B8(char *arg0, s32 arg1) {
    char *temp;
    struct func_0038F9B8_b *tb;

    ((struct func_0038F9B8_a *)arg0)->unk8 = (s32)D_0067DE00;
    func_0038FB58((s32 *)arg0);
    temp = arg0 + 0xE20;
    ((struct func_0038F9B8_c *)temp)->unk7DC = (s32)D_0067DF68;
    func_003B1890(temp, 0);
    func_003B1890(arg0 + 0x5E0, 2);
    tb = (struct func_0038F9B8_b *)(arg0 + 0x24);
    tb->unk0 = (s32)D_006885F0;
    func_004574A0(tb, 0);
    tb = (struct func_0038F9B8_b *)(arg0 + 0x1C);
    tb->unk0 = (s32)D_00688628;
    func_004574A0(tb, 0);
    ((struct func_0038F9B8_a *)arg0)->unk8 = (s32)D_0067DFA0;
    if (arg1 & 1) {
        return func_005C1628(arg0);
    }
}

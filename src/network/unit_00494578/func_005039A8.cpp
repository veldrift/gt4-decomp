typedef int s32;

struct func_005039A8_obj {
    char pad0[8];
    s32 unk8;
};

extern char D_006897A0[];

extern "C" void func_005037F0(void *, s32);
extern "C" void func_0057CA38(void *, s32);
extern "C" void func_00574DA8(void *, s32);
extern "C" void func_005C1628(void *);

extern "C" void func_005039A8(void *arg0, s32 arg1) {
    char *temp_s0;
    char *temp_s1;
    struct func_005039A8_obj *o1;
    struct func_005039A8_obj *o2;
    struct func_005039A8_obj *o3;

    if ((char *)arg0 != (char *)-0x54) {
        temp_s0 = (char *)arg0 + 0x954;
        temp_s1 = (char *)arg0 + 0x54;
        if (temp_s1 != temp_s0) {
            do {
                func_005037F0(temp_s0 - 0x48, 2);
                temp_s0 -= 0x48;
            } while (temp_s1 != temp_s0);
        }
    }
    o1 = (struct func_005039A8_obj *)((char *)arg0 + 0x48);
    o1->unk8 = (s32)D_006897A0;
    func_0057CA38(o1, 0);
    o2 = (struct func_005039A8_obj *)((char *)arg0 + 0x3C);
    o2->unk8 = (s32)D_006897A0;
    func_0057CA38(o2, 0);
    o3 = (struct func_005039A8_obj *)((char *)arg0 + 0x30);
    o3->unk8 = (s32)D_006897A0;
    func_0057CA38(o3, 0);
    func_00574DA8(arg0, 2);
    if ((arg1 & 0x1) != 0) {
        return func_005C1628(arg0);
    }
}

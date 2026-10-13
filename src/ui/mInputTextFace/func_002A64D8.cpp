/* compiler: ee-gcc2.96-nsa-nosib */
extern "C" int func_004B3E40(void);

struct func_002A64D8_arg0 {
    char pad0[0x164];
    int unk164;
};

extern "C" int func_002A64D8(void *arg0) {
    struct func_002A64D8_arg0 *self = (struct func_002A64D8_arg0 *)arg0;
    int v = func_004B3E40();
    if (v == 0) {
        return v;
    }
    int flag = 0;
    int a = self->unk164;
    if (a == 0 || a == 6 || a == 2 || a == 7) {
        flag = 1;
    }
    return flag;
}

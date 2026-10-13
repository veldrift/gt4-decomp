extern "C" void func_003A16A8(char *arg0);

extern "C" void func_003BD3B0(char *arg0)
{
    int *var_a0;
    int *var_v1;
    int var_a1;
    int mask;

    func_003A16A8(arg0);
    mask = -0x100;
    var_a0 = (int *)(arg0 + 0x4080);
    var_v1 = (int *)(arg0 + 0x3F30);
    var_a1 = 2;
    do {
        var_a1 -= 1;
        *var_v1 &= mask;
        var_v1 = (int *)((char *)var_v1 + 0x70);
        *var_a0 &= mask;
        var_a0 = (int *)((char *)var_a0 + 0x94);
    } while (var_a1 >= 0);

    int *q = (int *)(arg0 + 0x42C8);
    *q &= ~0xFF;
    int *r = (int *)(arg0 + 0x4360);
    *r &= ~0xFF;
}

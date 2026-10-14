extern "C" long long func_0057FB50(float f);
extern "C" int func_00556CA0(void);
extern "C" void func_00556E48(int a, long long *buf);
extern "C" void func_0035EDD8(char *arg0) {
    long long buf[6];
    buf[0] = func_0057FB50(*(float *)(arg0 + 0x4));
    buf[1] = func_0057FB50(*(float *)(arg0 + 0x0));
    buf[2] = func_0057FB50(*(float *)(arg0 + 0x8));
    buf[3] = func_0057FB50(*(float *)(arg0 + 0xC));
    buf[4] = func_0057FB50(*(float *)(arg0 + 0x10));
    buf[5] = func_0057FB50(*(float *)(arg0 + 0x14));
    func_00556E48(func_00556CA0(), buf);
}

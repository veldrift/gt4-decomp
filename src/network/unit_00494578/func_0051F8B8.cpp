extern "C" int func_005390A0(unsigned char *, int *);
extern "C" void *func_005A4724(void *, const void *, unsigned int);
extern "C" int func_0051F8B8(int arg0, int arg1, unsigned char *arg2, unsigned int arg3) {
    int buf[2];
    if (arg3 < 9) return 0;
    func_005390A0(arg2, buf);
    func_005390A0(arg2 + 4, &buf[1]);
    if (buf[1] != arg3 - 8) return 0;
    func_005A4724((void *)buf[0], arg2 + 8, buf[1]);
    return 0;
}

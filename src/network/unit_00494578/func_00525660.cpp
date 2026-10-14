extern "C" int func_00538F98(unsigned char *, unsigned short *);
extern "C" void func_00525660(unsigned char *src, unsigned int *type, unsigned short *value) {
    unsigned short v;
    func_00538F98(src, &v);
    *type = v >> 12;
    *value = v & 0xfff;
}

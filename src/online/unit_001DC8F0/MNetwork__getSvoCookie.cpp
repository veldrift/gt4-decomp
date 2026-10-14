extern "C" void func_001D6E80(void *, int);
extern "C" void func_001D6ED8(void *, void *);
extern "C" void func_001DC5F8(void *, int) throw();
extern "C" void func_001DC650(void *, void *) throw();
extern "C" unsigned char *func_001F15F8(unsigned char *);
extern "C" void func_004E82C0(void *, const char *);
extern "C" void MNetwork__getSvoCookie(void *arg0, void *arg1, void *arg2, void *arg3) {
    unsigned char *buf[4];
    func_001D6ED8(buf, arg3);
    unsigned char *p = buf[0];
    func_001D6E80(buf, 2);
    func_001DC650(buf, arg1);
    p += 0x10;
    func_004E82C0(p, (const char *)func_001F15F8(buf[0]));
    func_001DC5F8(buf, 2);
}

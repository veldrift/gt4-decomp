extern "C" void func_005A4724(void *dst, const void *src, unsigned int n);
extern "C" void func_00545EB8(void *arg0, void *arg1);

extern "C" void func_005446A0(const void *arg0, const void *arg1) {
    char buf[0x80];
    char out[0x80];

    func_005A4724(buf, arg0, 0x40);
    func_005A4724(out, arg1, 0x40);
    func_00545EB8(buf, out);
    func_005A4724((char *)arg0, buf, 0x40);
}

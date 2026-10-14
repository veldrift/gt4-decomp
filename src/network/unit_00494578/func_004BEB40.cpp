/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
extern "C" int func_004BCE90(void *, u16 *, int, u16 *) throw();
extern "C" void func_004BDA70(void *, int, int, int) throw();
extern "C" void func_004BCC50(void *, u16 *, int) throw();
extern "C" int func_004BDF68(void *, int, u16 *) throw();
extern "C" int func_004BF3A8(void *, int, int);
extern "C" int func_004BEB40(void *self, u16 id, u16 *p) {
    u16 sp[8];
    int result = func_004BCE90(self, p, id, sp);
    if (result < 0) return result;
    if (sp[0] != 0) {
        if ((id & 0xff00) != 0x200) {
            *p = sp[0];
            result = func_004BF3A8(self, id, (sp[0] & 0xffff) | 0x400000);
            if (result < 0) return result;
        }
        return 0x80003b6f;
    }
    func_004BDA70(self, id, 0, 0);
    func_004BDA70(self, id, 4, 0);
    func_004BDA70(self, id, 2, 0);
    func_004BCC50(self, p, id);
    if (func_004BDF68(self, id, p) < 0) return 0x80001e6f;
    func_004BDA70(self, id, 0, 0x100);
    func_004BDA70(self, id, 4, 0x100);
    func_004BDA70(self, id, 2, 0x100);
    return 0;
}

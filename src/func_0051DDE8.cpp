extern "C" void func_00538870(int fd, char *buf);
extern "C" void func_0051E158(void *self, int cmd, unsigned int arg, void *buf, int size, int flags);

extern "C" void func_0051DDE8(void *self) {
    char buf[0x40];
    func_00538870(0, buf);
    func_0051E158(self, 0x12, 0xFFFF, buf, 0x40, 1);
}

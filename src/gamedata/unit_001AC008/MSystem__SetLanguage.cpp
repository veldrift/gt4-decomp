typedef int s32;

struct Buf001AC538 {
    void *unk0;
    char pad[0xC];
};

extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" char *func_00314AD8(void *arg0);
extern "C" void func_00436170(char *arg0);

extern "C" void MSystem__SetLanguage(void *self, s32 n, s32 x) {
    struct Buf001AC538 buf;

    if (n > 0) {
        func_00312370(&buf, (void *)x);
        func_00436170(func_00314AD8(buf.unk0));
        func_00312318(&buf, 2);
    }
}

typedef int s32;

struct Buf001AC538 {
    void *unk0;
    char pad[0xC];
};

extern "C" void func_00312318(void *arg0, int arg1);
extern "C" void func_00312370(void *arg0, void *arg1);
extern "C" char *func_00314AD8(void *arg0);
extern "C" void GranTurismo4__LoadingMode(char *arg0);

extern "C" void MSystem__SetLoadingMode(void *self, s32 n, s32 x) {
    struct Buf001AC538 buf;

    if (n > 0) {
        func_00312370(&buf, (void *)x);
        GranTurismo4__LoadingMode(func_00314AD8(buf.unk0));
        func_00312318(&buf, 2);
    }
}

typedef int s32;

struct Buf001DD380 {
    void *unk0;
    char pad[0xC];
};

struct Target001DD380 {
    char pad[0x14];
    s32 unk14;
};

extern "C" void func_001DC650(void *arg0, void *arg1);
extern "C" void func_001DC5F8(void *arg0, int arg1);

extern "C" void MNetwork__endEnableAbort(void *arg0, void *arg1) {
    struct Buf001DD380 buf;
    struct Target001DD380 *p;

    func_001DC650(&buf, arg1);
    p = (struct Target001DD380 *)buf.unk0;
    p->unk14 = 0;
    func_001DC5F8(&buf, 2);
}

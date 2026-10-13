typedef int s32;
typedef float f32;

struct Item {
    char pad0[0x18];
    s32 unk18;
    s32 unk1C;
    char pad20[0x4];
    s32 unk24;
    f32 unk28;
};

extern "C" void func_003A4DA0(struct Item *self);
extern "C" void func_003A4E48(void *p, f32 f);

extern "C" void func_003A4F00(struct Item *arg0, f32 fparg0) {
    s32 s0 = 0;
    s32 s2;
    char *ptr;
    f32 r;

    arg0->unk18 = 0;
    arg0->unk1C = 0;
    if (fparg0 <= 0.0f) {
        s2 = 0;
        ptr = (char *)arg0 + 0x50;
        for (; s2 < 8; s2++) {
            char *q = ptr;
            ptr += 0x150;
            func_003A4DA0((struct Item *)q);
        }
    } else {
        while (s0 < 8) {
            s32 t = s0 * 0x15;
            func_003A4E48((char *)arg0 + t * 0x10 + 0x50, fparg0);
            s0++;
        }
    }
    __asm__("min.s %0, %1, %2" : "=f"(r) : "f"(arg0->unk28), "f"(fparg0));
    arg0->unk28 = r;
    arg0->unk24 = 0;
}

typedef int s32;

extern char D_00537150[];
extern char D_00537458[];
extern char D_00537628[];
extern char D_00537058[];
extern char D_00537188[];
extern char D_00537278[];
extern char D_00537770[];
extern char D_00530630[];
extern char D_00530B00[];
extern void *D_0064B4B4;
extern void *D_0064B4AC;

extern "C" s32 func_00537F80(s32 arg0, s32 arg1, s32 arg2);

extern "C" s32 func_00537998(void) {
    func_00537F80(0, 0, (s32)D_00537150);
    func_00537F80(1, 0, (s32)D_00537458);
    func_00537F80(2, 0, (s32)D_00537628);
    func_00537F80(0x10, 0, (s32)D_00537058);
    func_00537F80(0x13, 0, (s32)D_00537188);
    func_00537F80(0x14, 0, (s32)D_00537278);
    func_00537F80(0x16, 0, (s32)D_00537770);
    func_00537F80(0x19, 0, (s32)D_00530630);
    func_00537F80(0x1A, 0, (s32)D_00530B00);

    if (D_0064B4B4 != 0) {
        func_00537F80(0xF, 0, *(s32 *)((char *)D_0064B4B4 + 0xF0));
        func_00537F80(0x12, 0, *(s32 *)((char *)D_0064B4B4 + 0xEC));
        func_00537F80(3, 0, *(s32 *)((char *)D_0064B4B4 + 0xB0));
        func_00537F80(4, 0, *(s32 *)((char *)D_0064B4B4 + 0xB4));
        func_00537F80(5, 0, *(s32 *)((char *)D_0064B4B4 + 0xB8));
        func_00537F80(9, 0, *(s32 *)((char *)D_0064B4B4 + 0xBC));
        func_00537F80(0xA, 0, *(s32 *)((char *)D_0064B4B4 + 0xC0));
        func_00537F80(0xB, 0, *(s32 *)((char *)D_0064B4B4 + 0xC4));
        func_00537F80(0xC, 0, *(s32 *)((char *)D_0064B4B4 + 0xC8));
        func_00537F80(0xD, 0, *(s32 *)((char *)D_0064B4B4 + 0xCC));
        func_00537F80(0xE, 0, *(s32 *)((char *)D_0064B4B4 + 0xD0));
        func_00537F80(0x15, 0, *(s32 *)((char *)D_0064B4B4 + 0xD4));
        func_00537F80(0x17, 0, *(s32 *)((char *)D_0064B4B4 + 0xD8));
    }

    if (D_0064B4AC != 0) {
        func_00537F80(0x18, 0, *(s32 *)((char *)D_0064B4AC + 0x40));
        func_00537F80(0x1B, 0, *(s32 *)((char *)D_0064B4AC + 0x44));
        func_00537F80(0x1C, 0, *(s32 *)((char *)D_0064B4AC + 0x48));
        func_00537F80(0x1D, 0, *(s32 *)((char *)D_0064B4AC + 0x4C));
        func_00537F80(0x1E, 0, *(s32 *)((char *)D_0064B4AC + 0x50));
        func_00537F80(0x1F, 0, *(s32 *)((char *)D_0064B4AC + 0x54));
        return func_00537F80(0x20, 0, *(s32 *)((char *)D_0064B4AC + 0x58));
    }
}

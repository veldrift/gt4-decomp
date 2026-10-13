extern unsigned short D_006B0C68, D_006B0C70, D_006B0C78;
extern unsigned short D_006B0C20[], D_006B0C40[], D_006B0C50[], D_006B0C60[];

extern "C" int func_004B9210(int a0) {
    if ((unsigned int)(a0 - 0x61) < 0x1A) {
        return D_006B0C68 + a0 - 0x61;
    }
    if ((unsigned int)(a0 - 0x41) < 0x1A) {
        return D_006B0C70 + a0 - 0x41;
    }
    if ((unsigned int)(a0 - 0x30) < 0xA) {
        return D_006B0C78 + a0 - 0x30;
    }
    if ((unsigned int)(a0 - 0x21) < 0xF) {
        return D_006B0C20[a0 - 0x21];
    }
    if ((unsigned int)(a0 - 0x3A) < 7) {
        return D_006B0C40[a0 - 0x3A];
    }
    if ((unsigned int)(a0 - 0x5B) < 6) {
        return D_006B0C50[a0 - 0x5B];
    }
    if ((unsigned int)(a0 - 0x7B) < 4) {
        return D_006B0C60[a0 - 0x7B];
    }
    return 0;
}

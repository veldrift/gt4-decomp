typedef float f32;
typedef unsigned char u8;
typedef unsigned short u16;

struct func_00348368_arg0 {
    char pad0[0x467];
    u8 unk467;
    char pad468[0x48C - 0x468];
    f32 unk48C;
    char pad490[0x4BA - 0x490];
    u16 unk4BA;
    u8 unk4BC;
    char pad4BD[0x514 - 0x4BD];
    f32 unk514;
    char pad518[0x522 - 0x518];
    u8 unk522;
    char pad523[0x53C - 0x523];
    f32 unk53C;
};

void func_00348368(struct func_00348368_arg0 *arg0) {
    if (arg0->unk4BC != 0) {
        arg0->unk514 = 0x0.0p+0f;
        return;
    }
    if (arg0->unk4BA != 0) {
        arg0->unk514 = 0x0.0p+0f;
        return;
    }
    if (arg0->unk467 == 8) {
        arg0->unk514 = 0x0.0p+0f;
        return;
    }
    if (arg0->unk522 == 0) {
        arg0->unk514 = 0x0.0p+0f;
        if (arg0->unk48C < 0x1.999998p-4f) {
            arg0->unk514 = 0x1.0p+0f;
        }
    } else {
        arg0->unk514 = 0x1.0p+0f;
        if (0x1.999998p-4f < arg0->unk48C) {
            if (arg0->unk53C < 0x1.1C71C6p-2f) {
                if (-0x1.1C71C6p-2f < arg0->unk53C) {
                    arg0->unk514 = 0x0.0p+0f;
                }
            }
        }
    }
}

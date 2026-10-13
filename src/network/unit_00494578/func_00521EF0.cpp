typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Addr8 {
    u8 bytes[8];
} __attribute__((aligned(4)));

struct Frame {
    u8 b0;
    u8 pad1;
    u16 h2;
    u16 h4;
    u16 h6;
};

extern "C" s32 func_00538EE8(u8 *arg0, u8 *arg1);
extern "C" s32 func_00539188(u8 *arg0, u16 *arg1);

extern "C" s32 func_00521EF0(s32 unused0, u8 *base, u32 limit, u32 *pos, Addr8 *out, u32 *count) {
    Frame f;

    f.h2 = 0;
    f.h4 = 0;
    f.h6 = 0;
    f.b0 = 0;

    if (*count >= 0x10) {
        return 0;
    }

    for (;;) {
        func_00538EE8(base + *pos, &f.b0);
        u32 old = *pos;
        u32 n1 = old + 1;
        *pos = n1;
        if (f.b0 & 0xC0) {
            *pos = old + 2;
            break;
        }
        if (f.b0 == 0) {
            break;
        }
        *pos = n1 + f.b0;
    }

    if (limit < *pos) {
        return 0xC35A;
    }

    func_00539188(base + *pos, &f.h2);
    *pos = *pos + 2;
    func_00539188(base + *pos, &f.h4);
    *pos = *pos + 6;
    func_00539188(base + *pos, &f.h6);
    *pos = *pos + 2;

    if (f.h2 == 1 && f.h4 == f.h2 && f.h6 == 4) {
        *out = *(Addr8 *)(base + *pos);
        (*count)++;
    }

    *pos = *pos + f.h6;
    return (limit >= *pos) ? 0 : 0xC35A;
}

typedef int s32;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Item { char pad0[2]; u8 unk2; char pad3[5]; s32 unk8; };
struct G { char pad0[0x104]; s32 unk104; };
extern G *D_00854150;
extern "C" Item *func_00515DD8(u32) throw();
extern "C" s32 func_00515E08(u16 *arg0) {
    u32 i = 0;
    if (arg0 == 0) return 0x17;
    G **global = &D_00854150;
    *arg0 = 0;
    G *g = *global;
    if (g == 0) return 0;
    if (g->unk104 == 0x100) return 8;
    do {
        Item *it = func_00515DD8(i++);
        if (it != 0 && (u8)(it->unk2 - 3) < 2 && g->unk104 == it->unk8) {
            *arg0 += 1;
        }
    } while (i < 0x1000);
    return 0;
}

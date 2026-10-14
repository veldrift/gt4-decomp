typedef int s32;
typedef unsigned int u32;
typedef unsigned char u8;

struct Item {
    char pad0[0xC];
    u8 b0C;
    char pad0D[3];
    u8 b10;
    char pad11[3];
    u8 b14;
    char pad15[7];
    s32 w1C;
    s32 unk20;
};
struct Obj {
    char pad0[0x100];
    Item *unk100;
    s32 unk104;
    char pad108[0x154 - 0x108];
    s32 unk154;
};
struct Msg {
    u8 b0, b1, b2, b3;
    short h4;
    short pad6;
    s32 w8;
    s32 wC;
};
struct Vt {
    char pad0[0x18];
    s32 (*f18)(short *);
};
struct Slot {
    char pad0[0x20];
    s32 unk20;
};

extern Vt *D_0064B4B4;

extern "C" {
void func_00532588(Obj *, u32, s32, s32, Msg *);
Slot *func_00535C88(Obj *, u32);
s32 func_00536568(s32);
}

extern "C" void func_005310D0(Obj *o, u32 idx)
{
    Item *it;
    Msg m;
    s32 s3 = o->unk104;
    s32 s4 = 0;

    if (s3 == 0x100) {
        return;
    }
    it = o->unk100;
    if (it == 0) {
        return;
    }
    m.b1 = func_00536568(s3);
    m.b0 = it->b0C;
    m.b2 = it->b10;
    m.b3 = it->b14;
    m.w8 = it->w1C;
    m.wC = o->unk154;
    if (D_0064B4B4 != 0) {
        s4 = D_0064B4B4->f18(&m.h4);
    } else {
        m.h4 = 0;
    }
    if (s4 == 0) {
        if (idx == (u32)-1) {
            idx = 0;
            do {
                it = (Item *)func_00535C88(o, idx);
                if (it != 0 && it->unk20 != 0 && (s32)idx != s3) {
                    func_00532588(o, idx, 0x16, 0x10, &m);
                }
                idx++;
            } while (idx < 0x40);
        } else {
            func_00532588(o, idx, 0x16, 0x10, &m);
        }
    }
}

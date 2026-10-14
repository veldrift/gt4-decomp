/* compiler: ee-gcc2.96-nogcse */
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned char u8;
struct Obj { int pad0; int *p4; int pad8; u32 *pC; char pad10[0x14]; char *p24; };
struct Info { u16 id; char pad2[14]; u32 time; char pad14[12]; };
extern "C" int func_004BEC88(Obj *, int) throw();
extern "C" int func_004BC978(char *, u16, Info *, int) throw();
extern "C" void func_004BC818(u16 *, u8 *, int) throw();
extern "C" int func_004BE840(Obj *, u16, u16, void *) throw();
extern "C" int func_004C0860(Obj *self, u16 id, u32 target) {
    Info info;
    int result[4];
    if (*self->p4 == 0) func_004BEC88(self, 1);
    int type = id & 0xff00;
    char *base = self->p24;
    int index;
    u16 count;
    if (type == 0x200) {
        index = id & 0xff;
        count = *(u16 *)(base + index * 16 + 0x48);
    } else {
        index = id & 0xff;
        count = *(u16 *)(base + index * 16 + 0x58);
    }
    u8 *data;
    if (type == 0x200) data = *(u8 **)(base + index * 16 + 0x40) + 8;
    else data = *(u8 **)(base + index * 16 + 0x50) + 8;
    info.id = 0;
    if (func_004BC978(base, id, &info, 0) <= 0) return 0x80001e78;
    int wrap = *self->pC < target;
    for (int i = 1; i < count; i++, data += 6) {
        func_004BC818(&info.id, data, 2);
        if (info.id == 0 || func_004BC978(self->p24, id, &info, 0) <= 0) return 0x80001e78;
        u32 time = info.time;
        if ((wrap == 0 && *self->pC >= time && target < time) ||
            (wrap == 1 && (*self->pC >= info.time || target < info.time))) {
            int r = func_004BE840(self, id, info.id, result);
            if (r < 0) return r;
            data -= 6;
        }
    }
    return 0;
}

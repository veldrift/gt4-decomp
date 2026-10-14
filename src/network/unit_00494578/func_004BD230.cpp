/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
struct Ent { u32 p; char pad4[4]; u16 flag; u16 a; u16 b; char padE[2]; };
struct TblA { char pad0[0x40]; Ent e[16]; };
struct TblB { char pad0[0x50]; Ent e[16]; };
struct Fs { char pad0[0x24]; char *tbl; };
struct Req { char data[0x20]; };
extern "C" void *func_004C3E98(u8 *, int, u32);
extern "C" void func_004BD1F0(Req *) throw();
extern "C" void func_004BCC50(Fs *, Req *, int) throw();
extern "C" void func_004BDA70(Fs *, int, int, int);
extern "C" void func_004BD230(Fs *fs, u16 id) {
    Req q;
    int kind = id & 0xff00;
    char *tbl = fs->tbl;
    if (kind == 0x200) ((TblA *)tbl)->e[(id & 0xff)].flag = 1;
    else ((TblB *)tbl)->e[(id & 0xff)].flag = 1;
    u8 *ptr;
    if (kind == 0x200) ptr = (u8 *)((TblA *)tbl)->e[(id & 0xff)].p;
    else ptr = (u8 *)((TblB *)tbl)->e[(id & 0xff)].p;
    u32 size;
    if (kind == 0x200) size = ((Ent *)(tbl + (id & 0xff) * 16 + 0x40))->a * 26 + 26;
    else {
        Ent *e = (Ent *)((u32)tbl + ((id & 0xff) * 16 + 0x50));
        size = (e->a + e->b) * 26 + 26;
    }
    func_004C3E98(ptr, 0, size);
    func_004BD1F0(&q);
    func_004BCC50(fs, &q, id);
    func_004BDA70(fs, id, 0, 0x100);
    func_004BDA70(fs, id, 4, 0x100);
    func_004BDA70(fs, id, 2, 0x100);
}

/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

struct Ent {
    u32 p;
    char pad4[6];
    u16 a;
    u16 b;
    char padE[2];
};
struct TblA {
    char pad0[0x40];
    Ent e[16];
};
struct TblB {
    char pad0[0x50];
    Ent e[16];
};
struct Fs {
    char pad0[0x24];
    char *tbl;
};

extern "C" {
int func_004BC978(void *, int, u16 *, int) throw();
void func_004BDA70(Fs *, int, int, int) throw();
int func_004BDF68(Fs *, int, u16 *) throw();
void *func_004C3E98(u8 *, int, u32);
}

extern "C" int func_004BE3B8(Fs *fs, u16 id)
{
    int kind = id & 0xFF00;
    int cnt;
    u8 *ptr;
    u32 size;
    u16 cur;
    u16 v[16];

    if (kind == 0x200) {
        cnt = ((TblA *)fs->tbl)->e[id & 0xFF].a;
    } else {
        Ent *e = (Ent *)((u32)fs->tbl + ((id & 0xFF) * 16 + 0x50));
        cnt = e->a + e->b;
    }
    cnt += 1;
    u32 total = cnt & 0xFFFF;
    if (kind == 0x200) {
        ptr = (u8 *)((TblA *)fs->tbl)->e[id & 0xFF].p;
    } else {
        ptr = (u8 *)((TblB *)fs->tbl)->e[id & 0xFF].p;
    }
    if (kind == 0x200) {
        size = ((Ent *)(fs->tbl + (id & 0xFF) * 16 + 0x40))->a * 6 + 6;
    } else {
        Ent *e = (Ent *)((u32)fs->tbl + ((id & 0xFF) * 16 + 0x50));
        size = (e->a + e->b) * 6 + 6;
    }
    func_004C3E98(ptr, 0, size);
    cur = 1;
    while (cur < total) {
        int r;
        v[0] = cur;
        r = func_004BC978(fs->tbl, id, &v[0], 0);
        if (r < 0) {
            return -1;
        }
        if (r != 0) {
            if (func_004BDF68(fs, id, &v[0]) < 0) {
                return -1;
            }
        }
        cur = cur + 1;
    }
    func_004BDA70(fs, id, 0, 0x100);
    func_004BDA70(fs, id, 4, 0x100);
    func_004BDA70(fs, id, 2, 0x100);
    return 0;
}

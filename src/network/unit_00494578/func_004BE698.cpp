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
struct Fs {
    char pad0[0x24];
    char *tbl;
};
struct Rec {
    u16 h0;
    u16 h2;
};

extern "C" {
void func_004BC868(u8 *, const u16 *, int) throw();
void func_004BDA70(Fs *, int, int, int) throw();
int func_004BE578(char *, int, int, int) throw();
}

static inline u32 destination(u32 base, u32 off, u32 count)
{
    base += off;
    base += count * 6;
    base += 6;
    return base;
}

static inline void writeRecord(u32 dst, Rec *rec)
{
    rec->h2 = 0;
    func_004BC868((u8 *)dst, &rec->h2, 1);
}

extern "C" int func_004BE698(Fs *fs, Rec *rec, u16 id)
{
    char *tbl = fs->tbl;
    u32 off;
    u32 dst;

    func_004BDA70(fs, id, 0, 0);
    func_004BDA70(fs, id, 4, 0);
    func_004BDA70(fs, id, 2, 0);
    off = rec->h0 * 20;
    if ((id & 0xFF00) == 0x200) {
        Ent *e = (Ent *)((u32)tbl + ((id & 0xFF) * 16 + 0x40));
        dst = destination(e->p, off, e->a);
    } else {
        Ent *e = (Ent *)((u32)tbl + ((id & 0xFF) * 16 + 0x50));
        dst = destination(e->p, off, e->a + e->b);
    }
    writeRecord(dst, rec);
    if (func_004BE578(tbl, id, 4, rec->h0) < 0) {
        return -1;
    }
    func_004BDA70(fs, id, 4, 0x100);
    if (func_004BE578(tbl, id, 0, rec->h0) < 0) {
        return -1;
    }
    func_004BDA70(fs, id, 0, 0x100);
    if (func_004BE578(tbl, id, 2, rec->h0) < 0) {
        return -1;
    }
    func_004BDA70(fs, id, 2, 0x100);
    return 0;
}

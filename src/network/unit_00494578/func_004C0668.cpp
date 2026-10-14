/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ent { char *p; char pad4[6]; u16 a,b; char padE[2]; };
struct TblA { char pad[0x40]; Ent e[16]; };
struct TblB { char pad[0x50]; Ent e[16]; };
extern "C" int func_004C0668(char *tbl, u16 id, char *pos) {
    int kind = id & 0xff00;
    char *ptr;
    if (kind == 0x200) ptr = ((TblA *)tbl)->e[id & 0xff].p;
    else ptr = ((TblB *)tbl)->e[id & 0xff].p;
    int result;
    if (kind == 0x200) {
        int size = ((TblA *)tbl)->e[id & 0xff].a * 26 + 26;
        result = ((pos - (ptr + size) + 1) / 2) & 0xffff;
    } else {
        Ent *e = (Ent *)((u32)tbl + ((id & 0xff) * 16 + 0x50));
        int size = (e->a + e->b) * 26 + 26;
        result = ((pos - (ptr + size) + 1) / 2) & 0xffff;
    }
    return result;
}

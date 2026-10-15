/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned short u16;
typedef unsigned int u32;
struct Ent { u32 data; u32 size; u16 x; u16 a; u16 b; u16 c; };
#define E40(tbl, id) ((Ent *)((char *)((tbl) + ((id) & 0xff) * 16) + 0x40))
#define E50(tbl, id) ((Ent *)((tbl) + (((id) & 0xff) * 16 + 0x50)))
extern "C" u32 func_004C0508(char *tbl, u16 id, u16 index) {
    u32 n = index * 2;
    u32 pos;
    u32 base;
    if ((id & 0xff00) == 0x200)
        pos = n + E40(tbl, id)->a * 26 + 26;
    else {
        u32 o = (id & 0xff) * 16 + 0x50;
        Ent *e = (Ent *)(tbl + o);
        pos = n + (e->a + e->b) * 26 + 26;
    }
    if (!((id & 0xff00) == 0x200 ? pos < E40(tbl, id)->size : pos < E50(tbl, id)->size))
        return 0;
    if ((id & 0xff00) == 0x200)
        base = E40(tbl, id)->data;
    else
        base = E50(tbl, id)->data;
    u32 r;
    if ((id & 0xff00) == 0x200) {
        r = base + (E40(tbl, id)->a * 26 + 26) + n;
    } else {
        u32 o = (id & 0xff) * 16 + 0x50;
        Ent *e = (Ent *)(tbl + o);
        r = base + ((e->a + e->b) * 26 + 26) + n;
    }
    return r;
}

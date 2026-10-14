/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Ent { u32 p; char pad4[4]; u16 flag, a, b; char padE[2]; };
struct TblA { char pad0[0x40]; Ent e[16]; };
struct TblB { char pad0[0x50]; Ent e[16]; };
struct Fs { char pad[0x24]; char *tbl; };
struct Rec { u16 h0, h2; u8 bytes[6]; u16 hA, hC; u8 len1, len2; u8 tail[4]; u16 h14; u16 pad16; u8 *p18, *p1c; };
extern "C" {
void func_004BD230(Fs *, u16) throw();
int func_004BC978(char *, int, Rec *, int) throw();
void func_004BD1F0(Rec *) throw();
void func_004BCC50(Fs *, Rec *, int) throw();
void func_004BC868(u8 *, const u16 *, int) throw();
void func_004BC818(u16 *, u8 *, int) throw();
int func_004BE3B8(Fs *, u16) throw();
void func_004BDAE8(char *, int, Rec *, int, u8 **, int *) throw();
int func_004C92D8(const u8 *, const u8 *, u32);
int func_004BD8F0(const u8 *, const u8 *, int, int) throw();
}
static inline u32 destination(u32 base, u32 off, u32 count) { base += off; base += count * 6; base += 6; return base; }
extern "C" int func_004BED58(Fs *fs, int mode, u16 id) {
    int errors;
    int k;
    u16 previous;
    Rec rec;
    int order[3] = {0, 2, 4};
    u16 hdr;
    u8 *text;
    int length;
    u8 *cursor;
    int kind = id & 0xFF00;
    char *tbl = fs->tbl;
    u16 cur;
    errors = 0;
    if ((kind == 0x200 ? ((TblA *)tbl)->e[id & 0xFF].p : ((TblB *)tbl)->e[id & 0xFF].p) == 0) return 0;
    if (mode == 2) { func_004BD230(fs, id); return 0; }
    u16 limit;
    if (kind == 0x200) limit = ((TblA *)tbl)->e[id & 0xFF].a + 1;
    else { Ent *e = (Ent *)((u32)tbl + ((id & 0xFF) * 16 + 0x50)); limit = e->a + e->b + 1; }
    rec.h0 = 0;
    if (func_004BC978(tbl, id, &rec, 1) <= 0) {
        errors = 1;
        if (mode == 0) return 1;
        func_004BD1F0(&rec);
        func_004BCC50(fs, &rec, id);
    }
    int valid = 1;
    for (cur = 1; cur < limit; cur++) {
        rec.h0 = cur;
        int r = func_004BC978(tbl, id, &rec, 1);
        if (r < 0) {
            errors++;
            if (mode == 0) return 1;
            u32 off = rec.h0 * 20;
            if ((u16)kind == 0x200) {
                Ent *e = (Ent *)((u32)tbl + ((id & 0xFF) * 16 + 0x40));
                cursor = (u8 *)destination(e->p, off, e->a);
            } else {
                Ent *e = (Ent *)((u32)tbl + ((id & 0xFF) * 16 + 0x50));
                cursor = (u8 *)destination(e->p, off, e->a + e->b);
            }
            rec.h2 = 0;
            func_004BC868(cursor, &rec.h2, 1);
        } else {
            valid += r > 0;
        }
    }
    u16 count = valid;
    if (kind == 0x200 ? ((TblA *)tbl)->e[id & 0xFF].flag != count : ((TblB *)tbl)->e[id & 0xFF].flag != count) {
        if (mode) errors++;
        if (kind == 0x200) ((TblA *)tbl)->e[id & 0xFF].flag = valid;
        else ((TblB *)tbl)->e[id & 0xFF].flag = valid;
    }
    u16 k2 = kind;
    for (k = 0; k < 3; k++) {
        int which = order[k];
        if (k2 == 0x200) { Ent *e = (Ent *)((u32)tbl + ((id & 0xFF) * 16 + 0x40)); cursor = (u8 *)e->p + which; }
        else { Ent *e = (Ent *)((u32)tbl + ((id & 0xFF) * 16 + 0x50)); cursor = (u8 *)e->p + which; }
        func_004BC818(&hdr, cursor, 2);
        if (hdr != 0x100) {
            if (mode == 0) return 1;
            return func_004BE3B8(fs, id) == 0 ? 1 : -1;
        }
        if (k2 == 0x200) { Ent *e = (Ent *)((u32)tbl + ((id & 0xFF) * 16 + 0x40)); cursor = (u8 *)e->p + which + 6; }
        else { Ent *e = (Ent *)((u32)tbl + ((id & 0xFF) * 16 + 0x50)); cursor = (u8 *)e->p + which + 6; }
        int bad = 0;
        previous = 0;
        u8 *last = 0;
        int lastlen = 0;
        for (cur = 1; cur < count; cur++) {
            func_004BC818(&rec.h0, cursor, 2);
            if (rec.h0 == 0 || func_004BC978(tbl, id, &rec, 0) <= 0) bad = 1;
            else if (which == 2) {
                if (rec.h14 < previous) bad = 1;
                else previous = rec.h14;
            } else if (which == 0) {
                func_004BDAE8(tbl, id, &rec, 0, &text, &length);
                int cmp = func_004C92D8(last, text, length < lastlen ? length : lastlen);
                if (cmp > 0 || (cmp == 0 && length < lastlen)) bad = 1;
                else { lastlen = length; last = text; }
            } else if (which == 4) {
                func_004BDAE8(tbl, id, &rec, 4, &text, &length);
                if (func_004BD8F0(last, text, lastlen, length) > 0) bad = 1;
                else { last = text; lastlen = length; }
            }
            if (bad) {
                if (mode == 0) return 1;
                return func_004BE3B8(fs, id) == 0 ? 1 : -1;
            }
            cursor += 6;
        }
    }
    return errors > 0;
}

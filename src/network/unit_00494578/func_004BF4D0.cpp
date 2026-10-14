/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
struct Entry { int flags; u8 pad4; u8 type; char pad6[10]; u8 f10; u8 len; char rest[10]; u8 text[0x55]; u8 extra[0x73]; u16 pending; };
struct Ent { u32 p; char pad4[4]; u16 flag, a, b; char padE[2]; };
struct Rec { u16 h0, h2; u8 bytes[6]; u16 hA, hC; u8 len1, len2; u32 tail; u16 h14; u16 pad16; u8 *p18, *p1c; };
struct TblA { char pad0[0x40]; Ent e[16]; };
struct TblB { char pad0[0x50]; Ent e[16]; };
struct Obj { char pad0[0xC]; u32 *pC; char pad10[0x14]; char *tbl; char pad28[0xC]; Entry *entry; };
extern "C" {
int func_004BD890(Obj *, u8 *, u8 *, int) throw();
int func_004BE840(Obj *, u16, u16, int *) throw();
int func_004BD4A8(Obj *, u16, int, Rec *, int) throw();
int func_004BEB40(Obj *, u16, Rec *) throw();
void func_004BF938(char *, Entry *, u8 *, u8 *, u8 *, u16 *);
int func_004C0110(Obj *, u16, int, int);
u8 *func_004C9198(u8 *, u8 *);
u8 *func_004C9228(u8 *, u8 *, int);
u32 func_004C9330(u8 *);
}
extern "C" int func_004BF4D0(Obj *self, u16 id, Entry *e, u8 *text, u8 *extra, int mode) throw() {
    Rec rec;
    u8 buf1[0x80];
    u8 buf2[0x100];
    u8 buf3[0x40];
    u8 buf4[0x40];
    int size;
    int r;
    Rec *pr = &rec;
    if (mode == 2) {
        if (func_004C9330(self->entry->text) + func_004C9330(text) >= 0x7F) return 0;
        func_004BD890(self, buf3, text, 1);
        func_004BD890(self, buf4, self->entry->text, 1);
        if (self->entry->pending) {
            r = func_004BE840(self, id, self->entry->pending, &size);
            self->entry->pending = 0;
            if (r < 0) return r;
        }
        size = func_004C9330(buf4) + (func_004C9330(self->entry->extra) + func_004C9330(buf3)) + func_004C9330(extra);
    } else {
        if (func_004C9330(text) >= 0x7F) return 0;
        func_004BD890(self, buf3, text, 1);
        size = func_004C9330(buf3) + func_004C9330(extra);
    }
    for (;;) {
        r = func_004BD4A8(self, id, size, pr, mode);
        if (r >= 0) break;
        if ((r & 0x7F00) != 0x3A00) return r;
        if (func_004C0110(self, id, mode, size) < 0) return r;
    }
    if (mode == 2) {
        func_004BF938(self->tbl, self->entry, self->entry->extra, &pr->bytes[0], &pr->bytes[2], &pr->hA);
        func_004BF938(self->tbl, e, extra, &pr->bytes[1], &pr->bytes[3], &pr->hC);
        if (func_004C9330(self->entry->extra) + func_004C9330(extra) >= 0xFD) return 0;
        func_004C9198(buf1, buf3);
        func_004C9198(buf1 + func_004C9330(buf1), buf4);
        func_004C9198(buf2, self->entry->extra);
        func_004C9198(buf2 + func_004C9330(buf2), extra);
    } else {
        func_004BF938(self->tbl, e, extra, &pr->bytes[0], &pr->bytes[2], &pr->hA);
        pr->bytes[1] = 0;
        pr->bytes[3] = 0;
        if (mode == 1) { pr->hC = 0x2B; pr->hA = e->type; }
        else pr->hC = 0;
        if (mode == 3) {
            func_004C9198(buf1, buf3);
            func_004C9198(buf2, extra);
            self->entry->pending = pr->h0;
        } else {
            func_004C9228(buf1, buf3 + func_004C9330(buf3) - pr->bytes[0], pr->bytes[0]);
            buf1[pr->bytes[0]] = 0;
            buf2[0] = 0;
        }
    }
    pr->tail = *self->pC;
    pr->p18 = buf1;
    pr->p1c = buf2;
    pr->len1 = func_004C9330(buf1);
    pr->len2 = func_004C9330(buf2);
    if (mode == 2) {
        pr->bytes[4] = func_004C9330(buf4);
        pr->bytes[5] = func_004C9330(self->entry->extra);
    } else {
        pr->bytes[5] = pr->len2;
        pr->bytes[4] = pr->len1;
    }
    r = func_004BEB40(self, id, pr);
    if (r < 0) {
        if ((r & 0x7F00) != 0x3B00) return r;
        if (mode == 3) self->entry->pending = pr->h0;
    } else {
        if ((id & 0xFF00) == 0x200) ((TblA *)self->tbl)->e[id & 0xFF].flag++;
        else ((TblB *)self->tbl)->e[id & 0xFF].flag++;
    }
    return 0;
}

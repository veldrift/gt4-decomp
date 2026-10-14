/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef unsigned int u32;
struct Ent { s32 name; s32 pad; };
struct Hdr { char pad0[8]; Hdr *self; u32 count; Ent ent[1]; };
struct Tab { const char *name; s32 idx; };

extern "C" void func_00462738(void *, const char *, s32) throw();
extern "C" s32 func_00462798(s32) throw();
extern "C" void func_004627B0(void *, s32) throw();
extern "C" void func_00462900(void *) throw();
extern "C" void func_00462D68(void) throw();
extern "C" void func_00462EC8(s32);
extern "C" void func_004859F0(void *, u32, s32);
extern "C" u32 func_00485BA0(const char *);
extern "C" s32 func_004AE230(void *, const char *, s32);
extern "C" int func_0057F238(const char *, const char *) throw();

extern char D_008475C0[];
extern char D_008485C0[];
extern char D_00623A50[];
extern Hdr *D_00623A74;
extern Tab D_00623A78[0x49];
extern char D_00624898[];

static inline bool hasEntries(Hdr *h) { return h->count != 0; }

extern "C" void func_00463000(void) {
    Hdr *h;
    func_00462D68();
    if (D_00623A74 == 0) {
        func_00462EC8(0);
        func_004627B0(D_008475C0, 0x1000);
        func_00462798(0x1E0000);
        func_00462738(D_008485C0, "/sound/gt4sys.ins", 0);
        func_00462798(0x5040);
        func_00462738(D_008485C0 + 0x24, "/sound/gt4race.ins", 0);
        func_00462738(D_008485C0 + 0x48, "/sound/gt4count.ins", 0);
        func_00462738(D_00623A50, "/sound/roadnoiz.es", 1);
        s32 sp[8];
        func_004AE230(sp, "/sound/gt4se.inf", 1);
        h = (Hdr *)sp[4];
        {
            u32 i = 0;
            s32 d = (s32)h - (s32)h->self;
            h->self = h;
            if (h->count != 0) {
                Ent *e = h->ent;
                do {
                    i++;
                    e->name += d;
                    e++;
                } while (i < h->count);
            }
        }
        D_00623A74 = h;
        u32 k = 0;
        func_00462900(D_008485C0);
        func_00462900(D_008485C0 + 0x24);
        func_00462900(D_008485C0 + 0x48);
        if (hasEntries(h)) {
            Ent *e = h->ent;
            do {
                const char *nm = (const char *)e->name;
                for (s32 j = 0; j < 0x49; j++) {
                    if (func_0057F238(nm, D_00623A78[j].name) == 0) {
                        D_00623A78[j].idx = k;
                        func_004859F0(D_00624898, func_00485BA0(D_00623A78[j].name), D_00623A78[j].idx);
                        break;
                    }
                }
                k++;
                e++;
            } while (k < h->count);
        }
    }
}

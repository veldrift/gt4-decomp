struct Product {
    char name[0xc8];
    int id;
    char cc[16], dc[16], ec[16], fc[16];
    char pad10c[4], text[20];
    int extra;
};
struct Iterator {
    int (*destroy)(struct Iterator *);
    int (*next)(struct Iterator *);
    char pad8[8];
    int (*get)(struct Iterator *, struct Product **);
};
struct Catalog {
    char pad[0x30];
    int (*iterator)(struct Catalog *, int, struct Iterator **);
};
extern struct Catalog *D_0064A550;
extern char D_006C20B0[], D_006C20D8[], D_006C2128[], D_006C2138[], D_006C2158[];
extern int func_0057D9C0(const char *, ...);
extern void func_005A2E98(const char *, int, const char *);
int func_0050F488(void) {
    struct Iterator *it;
    struct Product *p;
    struct Catalog *c;
    int status;
    func_0057D9C0(D_006C20B0);
    c = D_0064A550;
    if(c->iterator(c, 1, &it) == 0) {
        do {
            status = it->get(it, &p);
            if(status == 0) {
                if(p == 0) func_005A2E98(D_006C20D8, 0x14f, D_006C2128);
                func_0057D9C0(D_006C2138, p, p->id, p->text, p->cc, p->dc, p->ec, p->fc, p->extra);
            } else {
                func_0057D9C0(D_006C2158, status);
            }
        } while(it->next(it) == 0);
        it->destroy(it);
    }
    return 0;
}

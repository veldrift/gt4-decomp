struct Product {
    char name[0x64];
    int id, id68, id6c;
    char text[0xc8], text138[16], text148[16];
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
extern struct Catalog *D_0064A55C;
extern char D_006C2238[], D_006C20D8[], D_006C2260[], D_006C2270[], D_006C2158[];
extern int func_0057D9C0(const char *, ...);
extern void func_005A2E98(const char *, int, const char *);
int func_0050FB78(void) {
    struct Iterator *it;
    struct Product *p;
    struct Catalog *c;
    int status;
    func_0057D9C0(D_006C2238);
    c = D_0064A55C;
    if(c->iterator(c, 1, &it) == 0) {
        do {
            status = it->get(it, &p);
            if(status == 0) {
                if(p == 0) func_005A2E98(D_006C20D8, 0x2ae, D_006C2260);
                func_0057D9C0(D_006C2270, p, p->id, p->id68, p->id6c, p->text, p->text138, p->text148, p->extra);
            } else {
                func_0057D9C0(D_006C2158, status);
            }
        } while(it->next(it) == 0);
        it->destroy(it);
    }
    return 0;
}

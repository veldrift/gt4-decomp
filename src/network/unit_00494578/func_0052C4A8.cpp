struct Entry { char pad0[0xC]; unsigned short flags; short pad2; char sub[1]; };
struct Node { int f0; Node *next; Entry e; };
struct Ctx { int err; char pad4[0x10]; char list[1]; };
extern "C" void func_00538F98(char *, unsigned short *);
extern "C" int func_0052CEA0(Ctx *, unsigned short);
extern "C" Node *func_0052DD60(char *);
extern "C" unsigned short func_00528770(char *);
extern "C" int func_0052D8B0(char *, Node *);

extern "C" int func_0052C4A8(Ctx *arg0, char *arg1, unsigned int arg2, unsigned short *arg3) {
    unsigned short sp[2];
    int r = 0;
    if (arg0 == 0) return 0xD2F3;
    func_00538F98(arg1, &sp[0]);
    arg1 += 2;
    int sz = sp[0] * 2 + 2;
    *arg3 = sz;
    if (arg2 < (unsigned short)sz) return 0xD2F5;
    unsigned int k = 0;
    if (sp[0] != 0) {
        char *lst = arg0->list;
        do {
            char *cur = arg1;
            arg1 += 2;
            func_00538F98(cur, &sp[1]);
            r = func_0052CEA0(arg0, sp[1]);
            Node *n = func_0052DD60(lst);
            while (n != 0) {
                if (n->f0 != 0) {
                    Entry *e = n ? &n->e : 0;
                    char *p = n ? n->e.sub : (char *)0x10;
                    if (p != 0) {
                        if (func_00528770(p) == sp[1]) {
                            int v = func_0052D8B0(lst, n);
                            if (v != 0) r = v;
                            unsigned short fl = e->flags;
                            if (fl & 0x800) {
                                if (fl & 0x8000) arg0->err = 0xC;
                                if (fl & 0x2000) arg0->err = 5;
                            }
                            return r;
                        }
                    }
                }
                n = n->next;
            }
            k++;
        } while (k < sp[0]);
    }
    return r;
}

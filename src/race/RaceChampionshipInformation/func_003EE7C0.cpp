typedef int s32;

struct Node {
    char pad[0x3444];
    union {
        s32 val;
        void *any;
    } u;
};

struct Tab {
    char pad[0x8];
    Node **ent;
};

struct Top {
    char pad[0x60];
    Tab *tab;
};

extern "C" void func_003EE7C0(char *arg0, Top *arg1) {
    Top *t1 = arg1;
    char *t0 = arg0 + 0x2FC;
    s32 i;
    for (i = 0; i < 6; i++) {
        s32 v = *(s32 *)t0;
        t0 += 0x188;
        Node *n = *(Node **)((char *)t1->tab->ent + i * 4);
        n->u.val = v;
    }
}

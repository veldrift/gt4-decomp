/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;

struct Node {
    char pad[0x3444];
    s32 val;
};

struct Tab {
    s32 count;
    s32 pad4;
    Node **ent;
};

struct Top {
    char pad[0x60];
    Tab *tab;
};

extern "C" void RaceTrainingInformation__finishEntryCar(char *arg0, Top *arg1) {
    Top *t1 = arg1;
    s32 i;
    s32 n = t1->tab->count;
    t1->tab->ent[0]->val = n - 1;
    for (i = 1; i < n; i++) {
        Node *e = *(Node **)((char *)t1->tab->ent + i * 4);
        e->val = i - 1;
    }
}

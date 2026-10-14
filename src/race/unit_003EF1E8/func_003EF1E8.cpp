/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
struct Node { char pad[0x10]; Node *next; s32 idx; };
struct List { s32 n; char pad[0x10]; Node *first; };
struct A1 { char pad[0x60]; List *l; };
struct Ent { char pad[8]; s32 v; char pad2[0x188 - 0xC]; };
extern "C" void RaceEntryBase__sortByRank(void *);
extern "C" s32 func_00447598(void *, s32);

extern "C" void func_003EF1E8(char *arg0, A1 *arg1) {
    s32 k = 0;
    List *l = arg1->l;
    s32 n = l->n;
    RaceEntryBase__sortByRank(l);
    Node *p = l->first;
    if (n > 0) {
        do {
            s32 id = p->idx;
            if (id != 0) {
                s32 j = k;
                k++;
                s32 r = func_00447598(arg0, j);
                s32 off = id * 0x188 + 0x2F0;
                Ent *e = (Ent *)(arg0 + off);
                e->v = e->v + r;
            }
            p = p->next;
        } while (--n != 0);
    }
}

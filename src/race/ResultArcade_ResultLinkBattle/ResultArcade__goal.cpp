/* compiler: ee-gcc2.96-no-strict-aliasing */
typedef int s32;
typedef short s16;
struct VE { s16 delta; s16 idx; void *fn; };
struct Node { char pad[0x10]; Node *next; s32 id; };
struct NList { char pad[0x14]; Node *head; };
struct Other { char pad[0x60]; NList *list; };
struct Self {
    s32 f0; s32 f4; s32 f8; char *fC; s32 f10; s32 slots[1];
    char pad18[0x48 - 0x18]; s32 f48; char pad4C[0x4F4 - 0x4C]; s32 f4F4;
};
extern "C" void RaceEntryBase__sortByRank(NList *);
extern "C" void ResultArcade__setPlayerRank(Self *, s32) throw();
extern "C" void ResultArcade__setCarName(Self *, s32, Node *) throw();
extern "C" void ResultArcade__setCarIconNumber(Self *, s32, s32) throw();
extern "C" void ResultArcade__goal(Self *self, Other *other, s32 arg2) {
    if (self->f10 != 0 && self->f48 == 0) {
        s32 idx = 0;
        RaceEntryBase__sortByRank(other->list);
        Node *n = other->list->head;
        if (n == 0) return;
        char *base = (char *)self + 4;
        for (; n != 0; n = n->next, idx++) {
            s32 id = n->id;
            s32 offset = id * 4 + 0x10;
            s32 *slot = (s32 *)(base + offset);
            if (*slot != 0 || arg2 != id) continue;
            *slot = 1;
            self->f48 = 1;
            s32 cnt = self->f4F4;
            for (s32 i = 0; i < cnt; i++) {
                if (self->slots[i] == 0) { self->f48 = 0; break; }
            }
            ResultArcade__setCarName(self, idx, n);
            ResultArcade__setCarIconNumber(self, idx, id);
            VE *e = (VE *)(self->fC + 0x48);
            ((void (*)(void *, s32, Node *))e->fn)((char *)self + e->delta, idx, n);
            if (n->id == self->f4) ResultArcade__setPlayerRank(self, idx);
            break;
        }
    }
}

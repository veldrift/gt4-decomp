typedef int s32;
struct Node { char pad0[4]; Node *prev; Node *next; };
struct Bucket { s32 count; Node *head; };
struct Tbl {
    char pad0[0x3C];
    void *unk3C;
    char pad40[4];
    s32 unk44;
    Bucket *unk48;
    s32 (*unk4C)(void *, s32, s32);
    char pad50[4];
    void (*unk54)(s32, s32, s32);
    s32 unk58;
    char pad5C[4];
    s32 unk60;
    void *unk64;
    char pad68[4];
    Tbl *unk6C;
};
extern "C" Node *func_005122A8(void *, s32);
extern "C" s32 func_005112D0(Tbl *arg0, s32 arg1) {
    if (arg0 == 0 || arg1 == 0) return 1;
    arg0->unk54(arg1, arg0->unk44, arg0->unk60);
    s32 idx = arg0->unk4C(arg0->unk3C, arg0->unk60, arg0->unk44);
    Node *n = func_005122A8(arg0->unk64, arg1);
    if (n == 0) return 2;
    Bucket *b = (Bucket *)(idx * 8 + (s32)arg0->unk48);
    Node *h = b->head;
    n->prev = 0;
    n->next = h;
    if (h) h->prev = n;
    Tbl *t = arg0->unk6C;
    b->head = n;
    arg0->unk58 = arg0->unk58 + 1;
    b->count = b->count + 1;
    if (t) func_005112D0(t, arg1);
    return 0;
}

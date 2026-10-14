struct Info { char pad[0xA]; unsigned short flag; };
struct Inner { char pad[4]; Info *info; char pad2[0x48]; int limit; };
struct Node { Node *next; int pad; Inner *data; };
struct Iter { Node *cur; Node *end; };
extern "C" void func_00474698(void *);
extern "C" void func_00474750(void *);
extern "C" void func_004747B8(void *);
extern "C" void func_0047D660(Inner *, void *);

extern "C" Node *func_00480518(void *a0, void *a1, int a2, Node *cur, Node *end) {
    Iter it;
    it.cur = cur;
    it.end = end;
    Node **pe = &it.end;
    while (it.cur != *pe) {
        if (a2 < it.cur->data->limit) return it.cur;
        unsigned short f = it.cur->data->info->flag;
        if (f) func_00474698(a1);
        func_0047D660(it.cur->data, a1);
        if (f) {
            func_00474750(a1);
            Node *nx = it.cur->next;
            it.cur = nx;
            it.cur = func_00480518(a0, a1, f, nx, it.end);
            func_004747B8(a1);
        } else {
            it.cur = it.cur->next;
        }
    }
    return it.end;
}

struct Node { int a; Node *prev,*next; };
struct Entry { int flag; Node *node; };
struct Table { char pad[0x3c]; unsigned count; char gap[8]; unsigned entries; };
struct Iter { char pad[0x18]; Table *table; int gap; unsigned index; Node *current,*pending; int flag; };
extern "C" int func_00511BB8(Iter *it) {
    Node *n = it->current;
    unsigned index = it->index;
    if (n) n = n->next;
    else {
        Node *p = it->pending;
        if (p || it->flag) {
            it->pending = 0;
            n = p;
            it->flag = 0;
        }
    }
    while (!n) {
        Table *t = it->table;
        ++index;
        if (index >= t->count) break;
        Entry *e = (Entry *)(index * 8 + t->entries);
        if (e->flag) { n=e->node; break; }
    }
    it->index=index;
    it->current=n;
    return n ? 0 : 4;
}

typedef unsigned int u32;
struct Node { char pad[8]; Node *next; };
struct Segment { u32 length; Node *head; };
struct Obj { char pad[0x3c]; u32 count; char gap[8]; Segment *segments; };
extern "C" Node *func_00512068(Obj *o, u32 index) {
    u32 n = o->count;
    u32 i = 0;
    u32 start = 0;
    u32 length = 0;
    for (; i < n; i++) {
        length = o->segments[i].length;
        if (index < start + length) break;
        start += length;
    }
    if (index >= start + length) return 0;
    Node *p = o->segments[i].head;
    if (p) {
        do {
            if (start == index) return p;
            p = p->next;
            start++;
        } while (p);
    }
    return 0;
}

/* compiler: ee-gcc2.96-as2004 */
typedef unsigned short u16;
typedef unsigned int u32;
typedef struct U64 { u32 lo, hi; } U64;
struct Queue { char pad[0x18]; };
struct Node { u32 size; struct Node *next; char data[1]; };
struct Obj {
    int handle; char pad4[0x20]; struct Queue queue; char pad3C[0x2C];
    u16 flags; char pad6A[0xE]; U64 addr; int port;
};
struct Api { char pad0[0x20]; int (*send)(int, U64, int, void *, int, int *); };
extern struct Api *D_0064B4B0;
struct Node *func_0052DD60(struct Queue *);
void func_0052D8B0(struct Queue *, struct Node *);

int func_0052B508(struct Obj *obj) {
    int sent = 0;
    struct Queue *q = &obj->queue;
    struct Node *n = func_0052DD60(q);
    struct Node *next;
    if (n) do {
        struct Node *remove = 0;
        if (n->size) {
            short *packet = n ? (short *)((char *)n + 0x16) : (short *)0xe;
            short flags = obj->flags & 0x3ff;
            int len = (u16)(*(u16 *)n - 0x12);
            int r;
            *packet = flags | (short)0x8000;
            r = D_0064B4B0->send(obj->handle, obj->addr, obj->port, packet, len, &sent);
            if (r) break;
            remove = n;
            if (len != sent) break;
        }
        next = n->next;
        n = next;
        if (remove) func_0052D8B0(q, remove);
    } while (next);
    return 0;
}

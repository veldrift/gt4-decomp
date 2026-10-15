/* compiler: ee-gcc2.96-as2004 */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long U64 __attribute__((aligned(4)));
struct Header { u16 flags, size, len; };
struct Address { U64 id; int port; };
struct Node { int active; struct Node *next; u8 data[1]; };
struct Queue { char pad[0x18]; };
struct Self;
struct Conn {
    unsigned state; int arg; char pad8[0xc]; struct Queue send, recv; char timer[0x34];
    u16 seq; char pad7a[6]; int arg80, arg84; char pad88[4];
    void (*data)(struct Self *, struct Conn *, u8 *, u16, int, int);
    void (*event)(struct Self *, struct Conn *, int, int, int);
    char pad94[0x404]; int context;
};
struct Self {
    int unk; struct Conn *conns; void *io; struct Queue recv; char pad24[0x2c]; unsigned count;
    char pad54[0x20]; int busy; char pad78[0xc];
    void (*data)(struct Self *, U64, int, u8 *, u16, int); char pad88[8]; int context;
};
struct Ops { char pad[0x50]; void (*close)(int, int); };
extern struct Ops *D_0064B710;
extern unsigned D_0064B458;
u16 func_00528770(void *);
int func_0052A3F8(struct Self *);
void func_0052D4E0(void *);
void func_0052D550(void *);
int func_0052D8B0(struct Queue *, struct Node *);
struct Node *func_0052DD60(struct Queue *);
int func_0053A890(void *, unsigned *);
int func_0053EFD0(void *);
void *func_005A48D8(void *, int, unsigned);

int func_0052A588(struct Self *self) {
    struct { struct Header h, h2; unsigned ticks; } loc;
    u8 *p;
    struct Node *n, *remove;
    int event = -1;
    loc.h.len = 0;
    if (!self) return 0xd2f2;
    if (self->io) func_0053EFD0(self->io);
    if (self->busy) return 0;
    {
    int r = func_0052A3F8(self);
    if (r) return r;
    }
    {
    struct Conn *c = self->conns;
    unsigned i;
    for (i = 0; i < self->count; i++, c++) {
        int notify = 0;
        switch (c->state) {
        case 0: case 1: break;
        case 2: notify = 1; event = 3; break;
        case 3: func_0052D550(&c->send); notify = 1; event = 2; break;
        case 4: notify = 1; event = 4; break;
        case 5:
            func_0053A890(c->timer, &loc.ticks);
            if (loc.ticks) {
                func_0052D4E0(&c->send); func_0052D4E0(&c->recv);
                if (D_0064B710) D_0064B710->close(-1, c->arg84);
                func_005A48D8(c, 0, 0x49c);
            }
            break;
        case 6: func_0053A890(c->timer, &loc.ticks); if (loc.ticks > D_0064B458) c->state = 3; break;
        case 7: c->state = 5; notify = 1; event = 5; break;
        case 8: notify = 1; event = 0; break;
        case 9: case 10: func_0053A890(c->timer, &loc.ticks); if (loc.ticks > 30000) c->state = 3; break;
        case 11: break;
        case 12: c->state = 13; notify = 1; event = 1; break;
        case 13:
            func_0053A890(c->timer, &loc.ticks);
            if (loc.ticks > D_0064B458) c->state = 3;
            else {
                struct Queue *q = &c->recv;
                n = func_0052DD60(q);
                while (n) {
                    remove = 0;
                    if (n->active) {
                        int accept = 0;
                        u8 *payload;
                        loc.h.len = 0;
                        p = n ? n->data : 0;
                        if (*(u16 *)p & 0x4000) {
                            if (func_00528770(p) == c->seq + 1) {
                                accept = 1;
                                c->seq = func_00528770(p);
                                if (c->seq == 0xffff) c->seq = 0;
                            }
                        } else accept = 1;
                        if (accept) {
                            ((u8 *)&loc.h.flags)[0] = p[0]; ((u8 *)&loc.h.flags)[1] = p[1]; loc.h.flags &= 0xf800;
                            if (loc.h.flags & 0x6000) loc.h.size = 4; else loc.h.size = 2;
                            payload = p + loc.h.size;
                            ((u8 *)&loc.h.len)[0] = p[0]; ((u8 *)&loc.h.len)[1] = p[1]; loc.h.len &= 0x7ff;
                            if (c->data) c->data(self, c, payload, loc.h.len, c->arg80, c->context);
                            remove = n;
                        }
                    }
                    n = n->next;
                    if (remove) func_0052D8B0(q, remove);
                }
            }
            break;
        }
        if (notify) { if (c->event) c->event(self, c, event, c->arg, c->context); else c->state = 5; }
    }
    }
    {
    struct Queue *q = &self->recv;
    n = func_0052DD60(q);
    while (n) {
        remove = 0;
        if (n) {
            if (n->active) {
                struct Address *addr = (struct Address *)n->data;
                u8 *payload;
                p = (u8 *)(addr + 1);
                loc.h2.len = 0;
                ((u8 *)&loc.h2.flags)[0] = p[0]; ((u8 *)&loc.h2.flags)[1] = p[1]; loc.h2.flags &= 0xf800;
                if (loc.h2.flags & 0x6000) loc.h2.size = 4; else loc.h2.size = 2;
                payload = p + loc.h2.size;
                ((u8 *)&loc.h2.len)[0] = p[0]; ((u8 *)&loc.h2.len)[1] = p[1]; loc.h2.len &= 0x7ff;
                self->data(self, addr->id, addr->port, payload, loc.h2.len, self->context);
                remove = n;
            }
            p = (u8 *)n->next;
        } else p = 0;
        n = (struct Node *)p;
        if (remove) func_0052D8B0(q, remove);
    }
    }
    return 0;
}

typedef unsigned char u8;
typedef unsigned short u16;
struct Entry { int *data; char pad[12]; void *value10; int value14; };
struct Obj { char pad0[0x88]; struct Entry *entries; u8 selected; char pad1[0x9C-0x8D]; u16 count; char pad2[0xBC-0x9E]; unsigned size; int valueC0; };
struct Packet { u16 code; u8 index; u8 pad; };
struct IOV { void *p; int len; };
struct IOVec { struct IOV v[8]; int total; int count; };
static inline void init(struct IOVec *v) { v->count = 0; v->total = 0; }
static inline void append(struct IOVec *v, void *p, int size) {
    int n = v->count;
    v->v[n].p = p;
    v->v[n].len = size;
    v->total += size;
    v->count++;
}
extern int func_00525648(int, int);
extern void func_00526040(void *, int *, u16 *);
extern int func_00527510(void *, int, int, int, struct IOVec *);
extern void *func_005A48D8(void *, int, unsigned);
extern int func_00524F70(struct Obj *o, u8 index) {
    struct Packet packet;
    struct IOVec vec;
    u16 port = 0xFFFE;
    int out = 0;
    if (!o) return 2;
    if (index >= o->size) return 2;
    if (!o->entries) return 3;
    {
    int result;
            struct Entry *e = o->entries + index;
            func_00526040(o, &out, &port);
            if (o->selected == index) o->selected = -1;
            packet.code = func_00525648(8, 4);
            packet.index = index;
            init(&vec);
            append(&vec, &packet, 4);
            result = func_00527510(o, 0, 0, 0xF000, &vec);
            if (result == 0) {
                unsigned count = o->count;
                unsigned i = 0;
                if (count) {
                    int *p = e->data;
                    do { i++; *p = 0; p++; } while (i < count);
                }
                func_005A48D8((char *)e + 4, 0, 12);
                e->value10 = 0;
                e->value14 = o->valueC0;
                return 0;
            }
    return result;
    }
}

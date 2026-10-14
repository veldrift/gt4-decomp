typedef unsigned char u8;
typedef unsigned short u16;
enum State { STATE_0 };
enum Kind { KIND_0, KIND_1 };
struct Entry { int a, value; };
struct Packet { u8 value, pad; u16 id; u8 type; };
struct Record { int owner; State value; int id; Kind type; int user; };
struct Self { char pad[0x168]; void (*callback)(Record *); int user; };
struct Global { char pad[0x118]; int owner; };
extern "C" Global *D_0064B4B4;
extern "C" Entry *func_00515DD8(unsigned int);
extern "C" void func_00516030(int, int, unsigned int) throw();
extern "C" void *func_005A48D8(void *, int, unsigned int);
extern "C" int func_0051A820(Self *self, int arg1, int arg2, Packet *p) {
    u8 value;
    if (self->callback == 0) {
        if (p->type == 1) {
            value = p->value;
            Entry *e = func_00515DD8(p->id);
            if (e) {
                e->value = value;
                func_00516030(value, p->id, -2);
            }
        }
    } else {
        if (p->type == 1) {
            Entry *e = func_00515DD8(p->id);
            if (e) { value = p->value; e->value = value; }
        }
        Record r;
        func_005A48D8(&r, 0, 0x14);
        r.owner = D_0064B4B4->owner;
        r.value = (State)p->value;
        r.id = p->id;
        r.type = (Kind)p->type;
        r.user = self->user;
        self->callback(&r);
    }
    return 6;
}

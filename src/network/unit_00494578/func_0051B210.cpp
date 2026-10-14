typedef unsigned char u8;
typedef unsigned short u16;
struct State { int a,b,c,type; };
struct Self { char pad[0x100]; State *state; };
struct Packet { u8 id; char pad[7]; u16 a,b,c,d,e; char pad12[4]; char text[1]; };
struct Entry { int flag,a,b,c,d,e; char text[1]; };
extern "C" Entry *func_0051B8A8(Self *, unsigned int);
extern "C" Entry *func_0051B968(Self *, unsigned int);
extern "C" void func_00518EE0(Self *, unsigned int) throw();
extern "C" char *func_005A609C(char *, const char *);
extern "C" int func_0051B210(Self *self, int arg1, int arg2, Packet *p) {
    if (self == 0) return 0x24;
    State *state = self->state;
    if (state == 0) return 0x24;
    if ((unsigned)(state->type - 4) < 2) {
    u8 id = p->id;
    if (id >= 0x40) return 0x24;
    Entry *e = func_0051B8A8(self, id);
    if (e == 0) {
        e = func_0051B968(self, id);
        if (e == 0) return 0x24;
    }
    e->a = p->a;
    e->b = p->b;
    e->c = p->c;
    e->d = p->d;
    e->e = p->e;
    func_005A609C(e->text, p->text);
    if (e->flag == 0) func_00518EE0(self, id);
    }
    return 0x24;
}

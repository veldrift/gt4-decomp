struct Entry { char pad0[0xC]; int ready; char pad10[0x10]; int state; };
struct Info { char pad0[0xC]; int kind; };
struct Self { char pad0[0x100]; Info *info; int index; };
struct Work { char pad0[0x10C]; int busy; };
struct Packet { int status; int value; };
struct Global { char pad0[0x118]; Self *self; int pad11c; void (*callback)(Packet *); int value; };
extern Global D_00854038;
extern Work *D_0064B4B4;
extern "C" Entry *func_00535C88(Self *, unsigned int);
extern "C" int func_00518B70() {
    Self *self = D_00854038.self;
    int i = 0;
    if (self == 0) return 0;
    if (D_0064B4B4->busy == 0) {
    Info *info = self->info;
    int result = 8;
    if (info != 0) {
    if ((int)__builtin_expect((unsigned int)(info->kind - 4) < 2U, 1)) {
        do {
            if (i != self->index) {
                Entry *e = func_00535C88(self, i);
                if (e != 0 && e->state == 1 && e->ready == 0) return 0;
            }
            i++;
        } while (i < 0x40);
        D_0064B4B4->busy = 1;
        if (D_00854038.callback != 0) {
            Packet pk;
            pk.status = 0;
            pk.value = D_00854038.value;
            D_00854038.callback(&pk);
            D_00854038.callback = 0;
            D_00854038.value = 0;
        }
    }
    result = 0;
    }
    return result;
    }
    return 0;
}

typedef long long s64;
typedef int s32;
struct Slot { s64 q[47]; };
struct Self { s64 pad; Slot slots[3]; s64 pad2[4]; s32 cur; };
extern "C" s32 func_004462A0(Slot *);
extern "C" s32 func_004462E0(Slot *);
extern "C" s32 func_00446320(Slot *);
extern "C" s32 func_00446360(Slot *);
extern "C" s32 func_004463A0(Slot *);
extern "C" s32 func_004463E0(Slot *);
extern "C" s32 func_00446420(Slot *);
extern "C" s32 func_00446460(Slot *);
extern "C" s32 func_004464A0(Slot *);
extern "C" s32 func_004464E0(Slot *);
extern "C" s32 func_00446520(Slot *);
extern "C" s32 func_00446560(Slot *);
extern "C" s32 func_004465A0(Slot *);
extern "C" s32 func_004465E0(Slot *);
extern "C" s32 func_00446620(Slot *);
extern "C" s32 func_00446660(Slot *);
extern "C" s32 func_004466A0(Slot *);
extern "C" s32 func_004466E0(Slot *);
extern "C" s32 func_00446720(Slot *);
extern "C" s32 func_00446760(Slot *);
extern "C" s32 func_004467A0(Slot *);
extern "C" s32 func_004467E0(Slot *);
extern "C" s32 func_00446820(Slot *);
extern "C" s32 func_00446860(Slot *);
extern "C" s32 func_004468A0(Slot *);
extern "C" s32 func_004468E0(Slot *);
extern "C" s32 func_0044A1B8(s32);

extern "C" s32 func_0043F4C8(Self *self, s32 id) {
    s32 r = -1;
    switch (id) {
    case 1:
        r = func_00446360(&self->slots[self->cur]);
        break;
    case 2:
        r = func_004463A0(&self->slots[self->cur]);
        break;
    case 3:
        r = func_004463E0(&self->slots[self->cur]);
        break;
    case 4:
        r = func_004464E0(&self->slots[self->cur]);
        break;
    case 5:
        r = func_00446520(&self->slots[self->cur]);
        break;
    case 7:
        r = func_004464A0(&self->slots[self->cur]);
        break;
    case 8:
        r = func_00446560(&self->slots[self->cur]);
        break;
    case 10:
        r = func_00446420(&self->slots[self->cur]);
        break;
    case 11:
        r = func_004462A0(&self->slots[self->cur]);
        break;
    case 13:
        r = func_004466A0(&self->slots[self->cur]);
        break;
    case 14:
        r = func_004466E0(&self->slots[self->cur]);
        break;
    case 15:
        r = func_004465A0(&self->slots[self->cur]);
        break;
    case 16:
        r = func_004465E0(&self->slots[self->cur]);
        break;
    case 17:
        r = func_00446620(&self->slots[self->cur]);
        break;
    case 18:
        r = func_00446660(&self->slots[self->cur]);
        break;
    case 19:
        r = func_004467E0(&self->slots[self->cur]);
        break;
    case 20:
        r = func_00446820(&self->slots[self->cur]);
        break;
    case 21:
        r = func_00446760(&self->slots[self->cur]);
        break;
    case 22:
        r = func_00446720(&self->slots[self->cur]);
        break;
    case 23:
        r = func_004467A0(&self->slots[self->cur]);
        break;
    case 24:
        r = func_00446460(&self->slots[self->cur]);
        break;
    case 25:
        r = func_004462E0(&self->slots[self->cur]);
        break;
    case 26:
        r = func_00446320(&self->slots[self->cur]);
        break;
    case 27:
        r = func_00446860(&self->slots[self->cur]);
        break;
    case 28:
        r = func_004468A0(&self->slots[self->cur]);
        break;
    case 31:
        r = func_004468E0(&self->slots[self->cur]);
        break;
    }
    if (r < 0) {
        if (func_0044A1B8(id)) r = 0;
    }
    return r;
}

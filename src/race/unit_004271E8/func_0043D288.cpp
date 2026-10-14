/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Input { unsigned short x, type; };
struct Output { int x, buttons; char pad[24]; int flags; };
extern "C" void *func_0055F1F0(void *);
extern "C" int func_0055F048(void *, int);
extern "C" int func_0055F0A0(void *, int);
extern "C" void func_0043D288(void *, Output *out, Input *in, int mode) {
    void *dev = func_0055F1F0(in);
    int a = func_0055F048(dev, 1);
    int b = func_0055F0A0(dev, 1);
    int flags = 0;
    int buttons = 0;
    int both = a | b;
    if (both & 0x10) buttons |= 4;
    if (both & 0x40) buttons |= 8;
    if (both & 0x80) buttons |= 0x80;
    if (both & 0x20) buttons |= 0x100;
    if (both & 0x1000) buttons |= 0x20;
    if (both & 0x4000) buttons |= 0x10;
    if (both & 0x8000) buttons |= 0x2000;
    if (both & 0x2000) buttons |= 0x40;
    if (a & 0x400) buttons |= 0x800;
    if (a & 0x800) buttons |= 0x1000;
    if (a & 0x400) buttons |= 1;
    if (a & 0x800) buttons |= 2;
    if (a & 0x100) buttons |= 0x200;
    if (a & 0x200) buttons |= 0x400;
    switch (in->type & 15) {
    case 1:
        if (b & 0x400) buttons |= 1;
        if (b & 0x800) buttons |= 2;
        if (b & 0x200) buttons |= 0x10;
        break;
    case 2:
        if (b & 0x400) buttons |= 1;
        if (b & 0x800) buttons |= 2;
        if (b & 0x100) buttons |= 0x200;
        if (b & 0x200) buttons |= 0x400;
        break;
    case 3:
        if (b & 0x100) buttons |= 1;
        if (b & 0x200) buttons |= 2;
        if (b & 2) buttons |= 0x200;
        if (b & 4) buttons |= 0x400;
        break;
    }
    if (mode == 1 || mode == 4) {
        if (both & 0x10) flags |= 2;
        if (both & 0x2000) flags |= 4;
        if (a & 2) flags |= 8;
        switch (in->type & 15) {
        case 2:
        case 3:
            if (b & 0x4000000) flags |= 8;
        case 1:
            if (b & 0x80) buttons |= 0x4000;
            if (b & 0x20) buttons |= 0x8000;
            if (b & 0x10) buttons |= 0x10000;
            if (b & 0x40) buttons |= 0x20000;
            break;
        }
    }
    out->buttons = buttons;
    out->flags |= flags;
}

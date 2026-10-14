/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Packet { unsigned char data[0x20]; };
struct Obj { char pad[0x18]; Packet packet; int done; int unused; unsigned frame; int repeat; unsigned *header; };
extern "C" void AutomobileControlRecord__Recorder__steer_update(void *) throw();
extern "C" int func_00345C90(void *) throw();
extern "C" void AutomobileControl__clearPacket(void *);
extern "C" void func_005F4918(void *, void *);
extern "C" void func_005F4948(void *, void *);
extern "C" void func_005F4978(void *, void *);
extern "C" void AutomobileControlRecord__Recorder__read(Obj *o, Packet *out) {
    unsigned *header = o->header;
    if (o->done == 0) {
        ++o->frame;
        if (o->frame >= *header) {
            AutomobileControl__clearPacket(&o->packet);
            o->done = 1;
        } else {
            AutomobileControlRecord__Recorder__steer_update(o);
            if (o->repeat == 0) {
                int flags = func_00345C90(o) - 1;
                if (flags & 0x100) func_005F4918(o, &o->packet.data[0]);
                if (flags & 0x80) func_005F4918(o, &o->packet.data[1]);
                if (flags & 0x10) func_005F4948(o, &o->packet.data[2]);
                if (flags & 2) func_005F4978(o, &o->packet.data[4]);
                if (flags & 1) func_005F4918(o, &o->packet.data[7]);
                if (flags & 4) func_005F4978(o, &o->packet.data[8]);
                if (flags & 8) func_005F4978(o, &o->packet.data[10]);
                if (flags & 0x40) func_005F4978(o, &o->packet.data[12]);
                if (flags & 0x20) func_005F4978(o, &o->packet.data[14]);
                if (flags & 0x200) {
                    int n = func_00345C90(o) - 1;
                    o->packet.data[3] = n;
                    for (int i = 0; i < n; i++) func_005F4918(o, &o->packet.data[16 + i]);
                }
                o->repeat = func_00345C90(o);
            }
            --o->repeat;
        }
    }
    *out = o->packet;
}

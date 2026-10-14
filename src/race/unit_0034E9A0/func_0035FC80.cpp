/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Body { char pad[0x4b2]; unsigned char busy; };
struct Car { char pad[0x104]; Body body; };
extern "C" unsigned short AutomobileGetCrashPenalty(Body *) throw();
extern "C" int func_0035FC80(Car *car) {
    int r = 0;
    Body *b = &car->body;
    if (b->busy != 0) return r;
    r = (AutomobileGetCrashPenalty(b) + 59) / 60;
    return r;
}

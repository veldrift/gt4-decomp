struct Car;
struct S { char p[0x1C]; Car *car; };
extern "C" void RaceEntryCar__structor_0(Car *c) throw();
extern "C" Car *exception__structor_0(int size);

extern "C" Car *RaceEntryBase__newEntryForm(S *self) {
    Car *t = self->car;
    Car *c;
    if (t != 0) {
        c = t;
        self->car = 0;
    } else {
        c = exception__structor_0(0x35D0);
        RaceEntryCar__structor_0(c);
    }
    return c;
}

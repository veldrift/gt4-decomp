/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Rep { char pad[0x130]; char *entries; };
struct Car { char pad[0x14]; int idx; };
extern "C" void setCarEquipment(Car *, char *);

extern "C" void RaceReplayInformation__updateEntryCar(Rep *self, Car *car) {
    setCarEquipment(car, self->entries + car->idx * 0x228 + 0x960);
}

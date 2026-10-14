/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Car { char pad[0x198]; int flags; };
struct List { char pad[8]; Car **head; };
struct Data { char pad[0x60]; List *list; };
struct Obj { char pad[0x6c]; Data *data; char pad70[0xf100-0x70]; Car *replacement; Car *old; };
extern "C" void RaceEntryCar__clear(void *, int);
extern "C" void setCarEquipment(void *, void *);
extern "C" void RaceSolitaire__loadReplaceData(Obj *self, char *src) {
    Car *car = self->replacement;
    if (!self->old) {
        Data *data = self->data;
        self->old = *data->list->head;
        *data->list->head = car;
    }
    RaceEntryCar__clear(car, 0);
    setCarEquipment(car, src + 0x960);
    car->flags = 0x100;
}

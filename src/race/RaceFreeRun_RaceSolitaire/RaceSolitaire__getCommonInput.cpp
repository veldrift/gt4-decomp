/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Data { char pad[0xe0]; int flag; bool isActive() const { return flag != 0; } };
struct Obj { char pad[0x6c]; Data *data; };
extern "C" void *RaceSolitaire__getCommonInput(Obj *self) {
    char *b = (char *)self + 0xe84c;
    if (self->data->isActive()) return b;
    return ((char *)self + 0xe48c);
}

struct Obj;
extern "C" bool func_0057CE80(Obj *o);

struct SelectBar {
    char pad[0xEC];
    float unkEC;
};

extern "C" int mSelectBar__canDecrement(void *arg0) {
    SelectBar *self = (SelectBar *)arg0;
    int var_v1;

    if (func_0057CE80((Obj *)((char *)arg0 + 0xBC))) {
        return 0;
    }
    var_v1 = 1;
    if (!(self->unkEC < 0.0f)) {
        var_v1 = 0;
    }
    return var_v1;
}

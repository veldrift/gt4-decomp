struct Fields00105500 {
    char padding[0x20];
    float first;
    float second;
};

extern "C" void func_00105500(struct Fields00105500 *self, float first, float second)
{
    self->first = first;
    self->second = second;
}

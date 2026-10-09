struct Fields00565B98 {
    char padding[0x24];
    int first;
    int second;
};

extern "C" void func_00565B98(struct Fields00565B98 *self, int first, int second)
{
    self->first = first;
    self->second = second;
}

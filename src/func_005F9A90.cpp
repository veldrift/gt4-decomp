struct Fields00565B98 {
    char padding[0x24];
    int first;
    int second;
};

extern "C" void func_005F9A90(struct Fields00565B98 *self, int first, int second)
{
    self->first = first;
    self->second = second;
}

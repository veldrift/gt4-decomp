typedef int s32;
extern "C" void *func_00604488(void *a);
extern "C" void *func_00454B08(void *self, unsigned int key);
extern "C" void *func_00450BF0(void *self) {
    void *r;
    if (func_00604488(self) != 0) {
        r = func_00454B08(func_00604488(self), 0x800001);
        if (r != 0) {
            return (char *)r + 4;
        }
    }
    return (void *)"unkown";
}

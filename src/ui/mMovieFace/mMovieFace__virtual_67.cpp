/* compiler: ee-gcc2.96-no-strict-aliasing */
extern "C" void mImageFace__virtual_67(void *);
extern "C" void func_00218A60(void *, void *);
extern "C" void func_003285A8(int);
extern "C" void func_003285F8(int);
extern "C" void func_0021D828(void *, int) throw();
extern "C" void mMovieFace__virtual_67(char *self) {
    int buf[4];
    mImageFace__virtual_67(self);
    int *out = (int *)(self + 0x114);
    if (*out == 0) {
        func_00218A60(buf, self + 0xF0);
        if (out != buf) {
            int p = buf[0];
            if (p) func_003285A8(p);
            int old = *out;
            if (old) func_003285F8(old);
            *out = p;
        }
        func_0021D828(buf, 2);
    }
}

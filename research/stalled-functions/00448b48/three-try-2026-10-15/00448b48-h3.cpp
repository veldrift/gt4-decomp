struct Source {
    unsigned long word0, word1, word2, word3, word4, word5, word6, word7;
    unsigned char byte;
};
struct Destination {
    unsigned long word0, word1, word2, word3, word4, word5;
    unsigned char byte;
    unsigned long word6, word7;
    Destination &operator=(const Source &source) {
        word0 = source.word0;
        word1 = source.word1;
        word2 = source.word2;
        word3 = source.word3;
        word4 = source.word4;
        word5 = source.word5;
        byte = source.byte;
        word6 = source.word6;
        word7 = source.word7;
        return *this;
    }
};
extern void *D_00623800;
extern void *D_00623804;
extern "C" long func_00449298(void *, int, Source *);
extern "C" long func_00448B48(unsigned long identifier, Destination *destination) {
    int high = identifier >> 32;
    int low = identifier & 0xFFFFFFFF;
    Source source;
    long found;
    if (high == 0) found = func_00449298(D_00623800, low, &source);
    else if (high == 0x26) found = func_00449298(D_00623804, low, &source);
    else return false;
    if (found) {
        *destination = source;
        return true;
    }
    return found;
}

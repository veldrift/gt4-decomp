struct Source {
    unsigned long word0, word1, word2, word3, word4, word5, word6, word7;
    unsigned char byte;
};
struct Destination {
    unsigned long word0, word1, word2, word3, word4, word5;
    unsigned char byte;
    unsigned long word6, word7;
};
extern void *D_00623800;
extern void *D_00623804;
extern "C" bool func_00449298(void *, int, Source *);
extern "C" bool func_00448B48(unsigned long identifier, Destination *destination) {
    int high = identifier >> 32;
    int low = identifier & 0xFFFFFFFF;
    Source source;
    bool found;
    if (high == 0) found = func_00449298(D_00623800, low, &source);
    else if (high == 0x26) found = func_00449298(D_00623804, low, &source);
    else return false;
    if (found) {
        destination->word0 = source.word0;
        destination->word1 = source.word1;
        destination->word2 = source.word2;
        destination->word3 = source.word3;
        destination->word4 = source.word4;
        destination->word5 = source.word5;
        destination->byte = source.byte;
        destination->word6 = source.word6;
        destination->word7 = source.word7;
        return true;
    }
    return found;
}

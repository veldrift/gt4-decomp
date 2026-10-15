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
static inline bool copy_info(void *table, int number, Destination *destination) {
    Source source;
    bool found = func_00449298(table, number, &source);
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
extern "C" bool func_00448B48(unsigned long identifier, Destination *destination) {
    int high = identifier >> 32;
    int low = identifier & 0xFFFFFFFF;
    if (high == 0) return copy_info(D_00623800, low, destination);
    if (high == 0x26) return copy_info(D_00623804, low, destination);
    return false;
}

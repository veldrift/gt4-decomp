typedef int s32;
typedef unsigned int size_t;

inline void *operator new(size_t, void *p) throw() { return p; }

struct Blk_005D3CE8 {
    s32 w[11];
};

extern "C" Blk_005D3CE8 *func_005D3CE8(const Blk_005D3CE8 *first, const Blk_005D3CE8 *last, Blk_005D3CE8 *result) {
    for (; first != last; ++first, ++result) {
        new (result) Blk_005D3CE8(*first);
    }
    return result;
}

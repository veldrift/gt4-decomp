typedef int s32;

struct Item_002B5500 {
    char pad[0x1C];
    unsigned int lo : 17;
    unsigned int on : 1;
    unsigned int hi : 14;
};

extern "C" s32 mListBox__get_total_item_count(void *list);
extern "C" Item_002B5500 *func_002B49B8(void *list, s32 i);

extern "C" void mListBox__setItemActive(void *list, s32 i, s32 on) {
    if (i >= 0 && i < mListBox__get_total_item_count(list)) {
        Item_002B5500 *it = func_002B49B8(list, i);
        it->on = on != 0;
    }
}

typedef unsigned int u32;
struct Entry { u32 number; int offset; };
struct TableData { int magic; unsigned short flags,version; volatile int count; int unknownC; Entry entries[1];
 int row_count() const { return count; }
 u32 row_number(int index) const { u32 result=-1; if(index>=0 && index<count) result=entries[index].number; return result; }
 int search(u32 number) const {     int low = -1;
    int high = row_count();
    if (high <= 0) return -1;
    do {
        int middle = (low + high) >> 1;
        u32 value = row_number(middle);
        if (value == number) return middle;
        if (value < number) low = middle;
        else high = middle;
    } while (low + 1 != high);
    return -1; }
};
struct Table { TableData *data; };
extern "C" int SPEC_DATABASE__DatabaseTable__searchNumber(Table *self,u32 number) { return self->data->search(number); }

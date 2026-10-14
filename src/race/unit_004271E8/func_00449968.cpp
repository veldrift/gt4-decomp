struct Entry{int offset,id;};
struct Data{int unknown,count,unknown8,unknownC;Entry entries[0];};
struct Table{Data*data;};
struct Record{unsigned short bytes;char text[0];};
extern "C" int func_0057F188(const char*,const char*,unsigned);
extern "C" int func_00449968(Table*self,const char*name,int index,unsigned length){
    Data*d=self->data;
    Entry*entries=d->entries;
    char*blob=(char*)(entries+d->count);
    int entryOffset=index*8;
    unsigned cursor=*(int*)((char*)entries+entryOffset);
    unsigned short stored=*(unsigned short*)(blob+cursor);
    cursor+=2;
    int size=stored-1;
    if(length==(unsigned)size)return func_0057F188(name,(const char*)((unsigned)blob+cursor),length);
    return length-size;
}

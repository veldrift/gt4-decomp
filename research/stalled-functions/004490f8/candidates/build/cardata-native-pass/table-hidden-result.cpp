/* compiler: ee-gcc2.96-no-strict-aliasing */
struct Header {
    unsigned int unknown0;
    unsigned short flags, unknown6;
    unsigned int count, unknownC;
};
struct Table { Header *header; int unknown4; char *entries,*records,*first,*second,*relative,*relativeData,*end; };
extern "C" Table func_004490F8(Header *source) {
 Table result; result.header=source; char *data=(char *)(source+1);
 unsigned int count=source->count; result.entries=data;
 char *base=data+count*8; unsigned short flags=source->flags&1;
 char *firstData=base+8; char *secondData=base+0x208;
 if(flags) {result.records=base;result.first=firstData;result.second=secondData;
 char *relative=base+*(int*)base;result.relative=relative;result.relativeData=relative+8;result.end=relative+*(int*)relative;
 }else result.end=base;
 return result;
}

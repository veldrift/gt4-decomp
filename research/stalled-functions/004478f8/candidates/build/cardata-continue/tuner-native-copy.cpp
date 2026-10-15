struct TunerCodes { unsigned long first; unsigned short last;
 TunerCodes() {} TunerCodes(const TunerCodes &o) : first(o.first),last(o.last) {}
 unsigned char at(int i) const { return ((const unsigned char *)this)[i]; }
}; extern "C" bool func_004478B8(unsigned long,TunerCodes*);
extern "C" int func_004478F8(unsigned long identifier,int *output,int capacity) {
 if(!output)return 0; TunerCodes row; if(!func_004478B8(identifier,&row))return 0;
 int i=0; int count=0; TunerCodes codes(row);
 for(;i<10;++i) { if(i>=capacity)break; int code=codes.at(i); if(!code)break; output[count++]=code; }
 return count;
}

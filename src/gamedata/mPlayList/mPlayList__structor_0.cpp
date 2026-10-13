// Native object wrapper: the constructor installs its read-only data pointer.
struct RefCounter {int unknown0;virtual ~RefCounter();};
struct hObject:RefCounter {hObject() __asm__("func_0030A678");virtual ~hObject();int unknown8,unknownC;};
struct mPlayList:hObject {void* const data;mPlayList(void*) __asm__("func_0019E5E0");virtual ~mPlayList();};
mPlayList::mPlayList(void* value):data(value){}

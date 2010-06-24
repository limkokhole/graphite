#ifndef ISEGMENT_INCLUDE
#define ISEGMENT_INCLUDE

#include "graphiteng/Types.h"

class ISlot;

class ISegment 
{
public:
    virtual int length() const = 0;
    virtual Position advance() const = 0;
    virtual ISlot & operator[] (int index) = 0;
    virtual const ISlot & operator[] (int index) const = 0;
    virtual void runGraphite() = 0;
    virtual void chooseSilf(uint32 script) = 0;
};


//PR the following functions are still to be encapsulated properly

class LoadedFace;
class IFont;
class FontImpl;

extern GRNG_EXPORT FontImpl *create_font(IFont *font, LoadedFace *face, float ppm);
extern GRNG_EXPORT void destroy_font(FontImpl *font);



class ITextSource;

extern GRNG_EXPORT ISegment *create_rangesegment(FontImpl *font, LoadedFace *face, const ITextSource *txt);
extern GRNG_EXPORT void destroy_segment(ISegment *seg);

#endif // SEGMENT_INCLUDE

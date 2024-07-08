#include "TuioContainerStruct.h"
#include "TUIO/TuioContainer.h"

FTuioContainerStruct::FTuioContainerStruct(const TUIO::TuioContainer& source)
    : Position(source.getX(), source.getY())
    , Speed(source.getXSpeed(), source.getYSpeed())
    , SessionID(source.getSessionID())
    , SourceID(source.getTuioSourceID())
    , Timestamp(source.getTuioTime().getTotalMilliseconds() / 1000.0)
{ }

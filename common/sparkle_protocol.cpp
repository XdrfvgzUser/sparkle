#include "sparkle_protocol.h"

/* ================================================================================================================== */

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const RegisterSurfaceFdRequest &data)
{
    stream << RegisterSurfaceFdRequestCode;
    stream << data.name;
    stream.writeFD(data.fd);
    stream << data.width;
    stream << data.height;
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, RegisterSurfaceFdRequest &data)
{
    stream >> data.name;
    stream.readFD(&data.fd);
    stream >> data.width;
    stream >> data.height;
    return stream;
}

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const UnregisterSurfaceRequest &data)
{
    stream << UnregisterSurfaceRequestCode;
    stream << data.name;
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, UnregisterSurfaceRequest &data)
{
    stream >> data.name;
    return stream;
}

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const SetSurfacePositionRequest &data)
{
    stream << SetSurfacePositionRequestCode;
    stream << data.name;
    stream << data.x1;
    stream << data.y1;
    stream << data.x2;
    stream << data.y2;
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, SetSurfacePositionRequest &data)
{
    stream >> data.name;
    stream >> data.x1;
    stream >> data.y1;
    stream >> data.x2;
    stream >> data.y2;
    return stream;
}

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const SetSurfaceStrataRequest &data)
{
    stream << SetSurfaceStrataRequestCode;
    stream << data.name;
    stream << data.strata;
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, SetSurfaceStrataRequest &data)
{
    stream >> data.name;
    stream >> data.strata;
    return stream;
}

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const SetSurfaceAlphaRequest &data)
{
    stream << SetSurfaceAlphaRequestCode;
    stream << data.name;
    stream << data.alpha;
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, SetSurfaceAlphaRequest &data)
{
    stream >> data.name;
    stream >> data.alpha;
    return stream;
}

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const AddSurfaceDamageRequest &data)
{
    stream << AddSurfaceDamageRequestCode;
    stream << data.name;
    stream << data.x1;
    stream << data.y1;
    stream << data.x2;
    stream << data.y2;
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, AddSurfaceDamageRequest &data)
{
    stream >> data.name;
    stream >> data.x1;
    stream >> data.y1;
    stream >> data.x2;
    stream >> data.y2;
    return stream;
}

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const DisplaySizeNotification &data)
{
    stream << DisplaySizeNotificationCode;
    stream << data.width;
    stream << data.height;
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, DisplaySizeNotification &data)
{
    stream >> data.width;
    stream >> data.height;
    return stream;
}

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const PointerDownNotification &data)
{
    stream << PointerDownNotificationCode;
    stream << data.surface;
    stream << data.slot;
    stream << data.x;
    stream << data.y;
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, PointerDownNotification &data)
{
    stream >> data.surface;
    stream >> data.slot;
    stream >> data.x;
    stream >> data.y;
    return stream;
}

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const PointerUpNotification &data)
{
    stream << PointerUpNotificationCode;
    stream << data.surface;
    stream << data.slot;
    stream << data.x;
    stream << data.y;
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, PointerUpNotification &data)
{
    stream >> data.surface;
    stream >> data.slot;
    stream >> data.x;
    stream >> data.y;
    return stream;
}

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const PointerMotionNotification &data)
{
    stream << PointerMotionNotificationCode;
    stream << data.surface;
    stream << data.slot;
    stream << data.x;
    stream << data.y;
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, PointerMotionNotification &data)
{
    stream >> data.surface;
    stream >> data.slot;
    stream >> data.x;
    stream >> data.y;
    return stream;
}

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const KeyDownNotification &data)
{
    stream << KeyDownNotificationCode;
    stream << data.code;
    return stream;
};

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, KeyDownNotification &data)
{
    stream >> data.code;
    return stream;
};

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const KeyUpNotification &data)
{
    stream << KeyUpNotificationCode;
    stream << data.code;
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, KeyUpNotification &data)
{
    stream >> data.code;
    return stream;
}

/* ================================================================================================================== */

WereSocketUnixMessageStream &operator<<(WereSocketUnixMessageStream &stream, const SoundData &data)
{
    stream << data.size;
    stream.write(data.data, data.size);
    return stream;
}

WereSocketUnixMessageStream &operator>>(WereSocketUnixMessageStream &stream, SoundData &data)
{
    stream >> data.size;
    data.data = stream.get(data.size);
    return stream;
}

/* ================================================================================================================== */

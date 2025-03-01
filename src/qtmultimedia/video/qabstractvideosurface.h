/****************************************************************************
**
** Copyright (C) 2009 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtMultimedia module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** No Commercial Usage
** This file contains pre-release code and may not be distributed.
** You may use this file in accordance with the terms and conditions
** contained in the Technology Preview License Agreement accompanying
** this package.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
**
**
**
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QABSTRACTVIDEOSURFACE_H
#define QABSTRACTVIDEOSURFACE_H

#include <QtCore/qobject.h>
#include <qtmultimedia/video/qvideoframe.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

//QT_MODULE(Multimedia)

class QRectF;
class QVideoSurfaceFormat;

class QAbstractVideoSurfacePrivate;

class QAbstractVideoSurface : public QObject
{
    Q_OBJECT

public:
    enum Error
    {
        NoError,
        UnsupportedFormatError,
        IncorrectFormatError,
        StoppedError,
        ResourceError
    };

    explicit QAbstractVideoSurface(QObject *parent = 0);
    ~QAbstractVideoSurface();

    virtual QList<QVideoFrame::PixelFormat> supportedPixelFormats(
            QAbstractVideoBuffer::HandleType handleType = QAbstractVideoBuffer::NoHandle) const = 0;
    virtual bool isFormatSupported(
            const QVideoSurfaceFormat &format, QVideoSurfaceFormat *similar = 0) const;

    QVideoSurfaceFormat surfaceFormat() const;

    virtual bool start(const QVideoSurfaceFormat &format);
    virtual void stop();

    bool isStarted() const;

    virtual bool present(const QVideoFrame &frame) = 0;

    Error error() const;

Q_SIGNALS:
    void startedChanged(bool started);
    void surfaceFormatChanged(const QVideoSurfaceFormat &format);
    void supportedFormatsChanged();

protected:
    QAbstractVideoSurface(QAbstractVideoSurfacePrivate &dd, QObject *parent);

    void setError(Error error);

private:
    Q_DECLARE_PRIVATE(QAbstractVideoSurface)
};

QT_END_NAMESPACE

QT_END_HEADER

#endif

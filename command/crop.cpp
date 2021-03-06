#include "crop.h"
#include <QtGui/QImage>
#include <QString>
#include <QStringList>
#include "image_processing/imageprocessor.h"

/**
* args: sourcefile x1 y1 x2 y2 destfile
*/
void Cropper::run(QStringList args) throw(CommandException)
{
    if (args.size() != 6 || args.isEmpty()) {
        throw CommandException("crop requires 5 parameters: sourcefile x1 y1 x2 y2 destfile");
    }

    bool conversion_ok = true;

    QString sourcefile = args.at(0);
    int x1             = args.at(1).toInt(&conversion_ok);
    int y1             = args.at(2).toInt(&conversion_ok);
    int x2             = args.at(3).toInt(&conversion_ok);
    int y2             = args.at(4).toInt(&conversion_ok);
    QString destfile   = args.at(5);

    if (!conversion_ok)
    {
        throw CommandException("Unable to parse integer parameter");
    }

    QImage original(sourcefile);

    QImage cropped = ImageProcessor::crop(original, x1, y1, x2, y2);

    cropped.save(destfile);
}

QString Cropper::usage()
{
    return "<sourcefile> <x1 (integer)> <y1 (integer)> <x2 (integer)> <y2 (integer)> <destfile>";
}

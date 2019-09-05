#ifndef ANNOTATIONITEM_H
#define ANNOTATIONITEM_H

#include "labelmanager.h"
#include <QString>
#include <QJsonObject>

class JsonException: public std::exception{
public:
    JsonException(std::string message);
    const char * what() const noexcept;
private:
    std::string message;
};

class AnnotationItem
{
public:
    QString label;
    int id; // instance id
    AnnotationItem();
    AnnotationItem(QString label, int id);
    virtual ~AnnotationItem();
    virtual QString toStr() const = 0;
    virtual QJsonObject toJsonObject() const;
    virtual void fromJsonObject(const QJsonObject &json);
};

#endif // ANNOTATIONITEM_H

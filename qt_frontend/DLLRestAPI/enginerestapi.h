#ifndef ENGINERESTAPI_H
#define ENGINERESTAPI_H

#include <QObject>

#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

class enginerestapi : public QObject
{
    Q_OBJECT
public:
    enginerestapi(QObject *parent = nullptr);
    ~enginerestapi();

public slots:
    void SignalFromDllRestApi(QString);
    void nostoSlot(QNetworkReply *reply);

private:
    QNetworkAccessManager *nostoManager;
    QNetworkReply *nostoReply;
};

#endif // ENGINERESTAPI_H

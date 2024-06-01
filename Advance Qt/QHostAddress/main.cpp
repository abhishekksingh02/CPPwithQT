#include <QCoreApplication>
#include <QHostAddress>/*
#include <QNetworkApplication>*/
#include <QAbstractSocket>
#include <QNetworkInterface>


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QHostAddress> list = QNetworkInterface::allAddresses();

    for(int i=0;i<list.count();i++)
    {
        QHostAddress address = list.at(i);
        qInfo() <<address.toString();

        qInfo() <<"/t LoopBack: "<<address.isLoopback();

        switch (address.protocol())
        {
        case  QAbstractSocket::UnknownNetworkLayerProtocol:
            qInfo() << "Protcol: Unknown";
            break;
        case  QAbstractSocket::AnyIPProtocol:
            qInfo() << "Protcol: Any";
            break;
        case QAbstractSocket::IPv4Protocol:
            qInfo() << "Protcol: IPv4";
            break;
        case QAbstractSocket::IPv6Protocol:
            qInfo() << "Protcol: IPv6";
            break;
        default:
            break;
        }
    }

    return a.exec();
}

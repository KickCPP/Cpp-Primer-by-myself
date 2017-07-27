#include <iostream>
#include <string>
#include <memory>

using std::shared_ptr; using std::string;
using std::cout; using std::endl;

struct destination{
    string ip;
    int port;
    destination(string ip_, int port_): ip(ip_), port(port_) {}
};

struct connection {
    string destIp;
    int destPort;
    connection(string dip, int dp): destIp(dip), destPort(dp) {}
};

connection connect(destination* pDest)
{
    auto pConn = std::make_shared<connection>(pDest->ip, pDest->port);
    cout << "creating connection(" << pConn.use_count() << ")" << endl;
    return *pConn;
}

void disconnect(connection pConn)
{
    cout << "connection close(" << pConn.destIp << ":" << pConn.destPort << ")" << endl;
}


void f(destination &d)
{
    connection conn = connect(&d);
    shared_ptr<connection> p(&conn, [](connection *conn) {disconnect(*conn);});
    cout << "connecting now(" << p.use_count() << ")" << endl;
}

int main()
{
    destination dest("192.168.1.1", 20);
    f(dest);
    return 0;
}

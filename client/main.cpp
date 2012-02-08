// main.cc
#include "Client.h"
#include <QApplication>


int main(int argc, char** argv)
{
  
  QApplication app(argc, argv);

  Client client;
  client.start("127.0.0.1", 16065);

  return app.exec();
}

// web_relay
// Arduino Uno or (Leonardo with Ethernet SHield R3)

#include <SPI.h>
#include <Ethernet.h>

// MAC address just has to be unique. This should work
byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
// The IP address will be dependent on your local network:
byte ip[] = { 192, 168, 1, 30 };
EthernetServer server(80);

int relayPin = A0;

char line1[100];

void setup()
{
  pinMode(relayPin, OUTPUT);
  Ethernet.begin(mac, ip);
  server.begin();
}

void loop()
{
  EthernetClient client = server.available();
  if (client) 
  {
    while (client.connected()) 
    {
      readHeader(client);
      if (! pageNameIs("/"))
      {
        client.stop();  
        return;
      }
      digitalWrite(relayPin, valueOfParam('a'));
      client.println("HTTP/1.1 200 OK");
      client.println("Content-Type: text/html");
      client.println();

      // send the body
      client.println("<html><body>");
      client.println("<h1>Relay Remote</h1>");

      client.println("<h2><a href='?a=1'/>On</a></h2>");
      client.println("<h2><a href='?a=0'/>Off</a></h2>");
      client.println("</body></html>");

      client.stop();            
    }
  }
}


void readHeader(EthernetClient client)
{
  // read first line of header
  char ch;
  int i = 0;
  while (ch != '\n')
  {
    if (client.available())
    {
      ch = client.read();
      line1[i] = ch;
      i ++;
    }
  }
  line1[i] = '\0'; 
  Serial.println(line1);
}

boolean pageNameIs(char* name)
{
   // page name starts at char pos 4
   // ends with space
   int i = 4;
   char ch = line1[i];
   while (ch != ' ' && ch != '\n' && ch != '?')
   {
     if (name[i-4] != line1[i])
     {
       return false;
     }
     i++;
     ch = line1[i];
   }
   return true;
}

int valueOfParam(char param)
{
  for (int i = 0; i < strlen(line1); i++)
  {
    if (line1[i] == param && line1[i+1] == '=')
    {
      return (line1[i+2] - '0');
    }
  }
  return 0;
}


#include "SPI.h"
#include "avr/pgmspace.h"
#include "Ethernet.h"
#include "WebServer.h"
#include "EmitColor.h"

#define VERSION_STRING "0.0.1"

static uint8_t mac[] = { 0x90, 0xA2, 0xDA, 0x0D, 0x18, 0x48 };
static uint8_t ip[]  = { 10, 0, 1, 12 };

P(title)    = "<html><head><title>Webduino LED Controller" VERSION_STRING "</title></head><body>\n";
P(html_end) = "</body></html>";

P(root_header) = "<h1>Webduino LED Controller</h1>";


unsigned short int STEADY_RED = 1;
unsigned short int STEADY_GREEN = 2;
unsigned short int STEADY_BLUE = 3;
unsigned short int STEADY_YELLOW = 4;
unsigned short int BLINK_RED = 5;
unsigned short int NONE = 0; 

unsigned short int emit = NONE;

/* This creates an instance of the webserver.  By specifying a prefix
 * of "", all pages will be at the root of the server. */
#define PREFIX ""
WebServer webserver(PREFIX, 9889);


void root(WebServer &server, WebServer::ConnectionType type, char *params, bool tail_complete)
{
  server.httpSuccess();
  
  server.printP(title);
  server.printP(root_header);
  server.print(params);
  server.printP(html_end);
}

void badRequest(WebServer &server, WebServer::ConnectionType type, char *url_tail, bool tail_complete)
{
  server.httpFail();
}

void setLight(WebServer &server, WebServer::ConnectionType method, char *params, bool tail_complete)
{
  server.httpSuccess();
  
  if (tail_complete) {
    if (strcmp(params, "red") == 0) emit = STEADY_RED;
    if (strcmp(params, "green") == 0) emit = STEADY_GREEN;
    if (strcmp(params, "blue") == 0) emit = STEADY_BLUE;
    if (strcmp(params, "yellow") == 0) emit = STEADY_YELLOW;
    if (strcmp(params, "blink_red") == 0) emit = BLINK_RED;

    if (strcmp(params, "none") == 0) emit = NONE;
  }
} 


void setup()
{
  pinMode(REDPin, OUTPUT);
  pinMode(GREENPin, OUTPUT);
  pinMode(BLUEPin, OUTPUT);
  Serial.begin(9600);  
  
  Ethernet.begin(mac, ip);

  webserver.setDefaultCommand(&root);
  webserver.setFailureCommand(&badRequest);

  webserver.addCommand("index.html", &root);
  webserver.addCommand("set_light.html", &setLight);

  webserver.begin();
}

void loop()
{
  char buff[64];
  int len = 64;

  /* process incoming connections one at a time forever */
  webserver.processConnection(buff, &len);
  
  /* Refactor to use switch instead of multiple if */
  if (emit == NONE) none();
  if (emit == STEADY_RED) steadyRed();
  if (emit == STEADY_GREEN) steadyGreen();
  if (emit == STEADY_BLUE) steadyBlue();
  if (emit == STEADY_YELLOW) steadyYellow();
  
  // Todo: Not functional, use mills instead of dealy
  if (emit == BLINK_RED) {
    steadyRed();
    delay(1000);
    none();
  }
  
}

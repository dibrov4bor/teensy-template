#include "WProgram.h"
#include <pb_encode.h>
#include <pb_decode.h>
#include "geo.pb.h"

uint8_t buffer[128];

extern "C" int main(void) {
  geo_GeoRecord message = geo_GeoRecord_init_zero;
  message.has_latitude = true;
  message.longtitude = 12345;
  message.has_longtitude = true;
  message.latitude = 67890;
  pb_ostream_t stream = pb_ostream_from_buffer(buffer, sizeof(buffer));
  bool status = pb_encode(&stream, geo_GeoRecord_fields, &message);

  Serial.begin(9600);
  Serial.print(stream.bytes_written);
  Serial.println(" bytes have been written");

  pinMode(13, OUTPUT);
  digitalWriteFast(13, status ? HIGH : LOW);


  while (1) {
  }
}


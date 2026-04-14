/*
 * Du an: Doc nhiet do LM35 va gui qua Serial
 * Mon: Mang Cam Bien - Tuan 03
 * Thanh vien: SV A (Chủ repo) & SV B (Yen Nhi - Collaborator)
 */

int adcValues[3];  // Giữ 3 kênh của SV A
float nhietDo[3];  // Giữ 3 kênh của SV A

void setup() {
  Serial.begin(9600);
  delay(100);
}

void loop() {
  // Đọc dữ liệu từ 3 kênh cảm biến
  adcValues[0] = analogRead(A0);
  nhietDo[0] = (adcValues[0] * 500.0) / 1023.0;
  
  adcValues[1] = analogRead(A1);
  nhietDo[1] = (adcValues[1] * 500.0) / 1023.0;

  adcValues[2] = analogRead(A2);
  nhietDo[2] = (adcValues[2] * 500.0) / 1023.0;
  
  // Gửi dữ liệu dưới dạng JSON (Cải tiến của SV B)
  Serial.print("{");
  Serial.print("\"T1\":"); Serial.print(nhietDo[0], 1);
  Serial.print(",");
  Serial.print("\"T2\":"); Serial.print(nhietDo[1], 1);
  Serial.print(",");
  Serial.print("\"T3\":"); Serial.print(nhietDo[2], 1);
  Serial.println("}");

  delay(1000); // Gửi dữ liệu mỗi giây để tránh quá tải Serial
}
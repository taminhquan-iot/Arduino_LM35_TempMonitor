/*
 * Dự án: Giám sát nhiệt độ LM35 (JSON Format)
 * Mục tiêu: Đóng gói dữ liệu vào định dạng JSON để truyền qua Serial
 */

int adcValues[2];
float nhietDo[2];

void setup() {
  Serial.begin(9600);
  // Đợi Serial khởi động ổn định
  while (!Serial) { ; } 
}

void loop() {
  // Đọc dữ liệu từ cảm biến LM35
  adcValues[0] = analogRead(A0);
  nhietDo[0] = (adcValues[0] * 500.0) / 1023.0;

  adcValues[1] = analogRead(A1);
  nhietDo[1] = (adcValues[1] * 500.0) / 1023.0;

  // Gửi dữ liệu dưới dạng JSON
  Serial.print("{");
  Serial.print("\"T1\":"); Serial.print(nhietDo[0], 1); // Lấy 1 chữ số thập phân
  Serial.print(",");
  Serial.print("\"T2\":"); Serial.print(nhietDo[1], 1);
  Serial.println("}");

  delay(1000); // Gửi dữ liệu mỗi giây để tránh quá tải Serial
}

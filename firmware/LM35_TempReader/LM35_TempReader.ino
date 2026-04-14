/*
 * Dự án: Giám sát nhiệt độ LM35 (JSON Format)
 * Mục tiêu: Đóng gói dữ liệu vào định dạng JSON để truyền qua Serial
 */



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
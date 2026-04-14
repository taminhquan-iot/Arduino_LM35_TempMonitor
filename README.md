# Dự án: Hệ thống theo dõi nhiệt độ LM35 (Arduino)

## 1. Mô tả dự án
Dự án ứng dụng vi điều khiển Arduino và cảm biến nhiệt độ tương tự LM35 để giám sát nhiệt độ môi trường. Dữ liệu được đọc liên tục và gửi lên máy tính qua giao tiếp Serial dưới dạng CSV để dễ dàng theo dõi và xử lý.

## 2. Các tính năng chính
* Đọc dữ liệu nhiệt độ đồng thời từ 3 kênh cảm biến (A0, A1, A2).
* Tự động chuyển đổi từ tín hiệu ADC thô (0-1023) sang nhiệt độ thực tế (°C).
* Định dạng chuỗi dữ liệu đầu ra chuẩn CSV (Ví dụ: `25,26,24`).

## 3. Yêu cầu phần cứng
| STT | Tên thiết bị | Số lượng | Ghi chú |
|:---:|:---|:---:|:---|
| 1 | Board mạch Arduino Uno R3 | 1 | Hoặc các board tương đương |
| 2 | Cảm biến nhiệt độ LM35 | 3 | Dải đo từ 0°C đến 100°C |
| 3 | Dây cắm (Jumper wires) | 1 bộ | Dùng loại đực-đực, đực-cái |
| 4 | Breadboard (Test board) | 1 | Để cắm chung nguồn và đất |

## 4. Hướng dẫn sử dụng
1. **Kết nối phần cứng:** Nối chân VCC và GND của 3 cảm biến LM35 vào nguồn 5V và GND của Arduino. Nối lần lượt chân tín hiệu (OUT) của 3 cảm biến vào các chân Analog `A0`, `A1`, `A2` trên board.
2. **Nạp code:** Mở file `firmware/LM35_TempReader/LM35_TempReader.ino` bằng phần mềm Arduino IDE. Chọn đúng port và bấm Upload.
3. **Theo dõi:** Mở công cụ Serial Monitor trên Arduino IDE, set Baudrate ở mức `9600` để xem nhiệt độ trả về.

## 5. Cấu trúc thư mục
```text
Arduino_LM35_TempMonitor/
├── firmware/
│   └── LM35_TempReader/
│       └── LM35_TempReader.ino
├── README.md
└── .gitignore
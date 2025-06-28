// // 매일 일정한 시간에 포텐셔미터 값을 측정하여 네이버 메일 보내는 프로그램
// #include <WiFi.h>
// #include <ESP_Mail_Client.h>
// #include <NTPClient.h>
// #include <WiFiUdp.h>

// #define WIFI_SSID "Wokwi-GUEST"
// #define WIFI_PASSWORD ""

// #define SMTP_HOST "smtp.naver.com"

// #define SMTP_PORT esp_mail_smtp_port_587

// #define AUTHOR_EMAIL "taesamja@naver.com"
// #define AUTHOR_PASSWORD "이메일 비밀번호 적기"

// SMTPSession smtp;

// String strSender = "보내는 사람 이름";
// String strRecipientName = "받는 사람 이름";
// String strRecipientMail = "taesamja@naver.com"; // 받는사람 메일주소
// String strSubject = "가변저항값"; // 메일제목
// String strMsg = "";

// #define POT 35

// WiFiUDP ntpUDP;
// NTPClient timeClient(ntpUDP, 32400);

// void setup() {
//   Serial.begin(115200);
//   WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
//   while(WiFi.status() != WL_CONNECTED) {
//     delay(500);
//     Serial.print(".");
//   }
//   Serial.println("");
//   Serial.println("WiFi connected");
//   Serial.println("IP address: ");
//   Serial.println(WiFi.localIP());
//   Serial.println();

//   timeClient.begin();
// }

// void loop() {
//   timeClient.update();

//   if(timeClient.isTimeSet()) {
//     if(timeClient.getHours() == 17 && 
//        timeClient.getMinutes() == 07 && 
//        timeClient.getSeconds() == 0) {
//       int potValue = analogRead(POT);
//       strMsg = "오늘의 포텐셔미터 값은: ";
//       strMsg += String(potValue);
//       strMsg += " 입니다.";

//       sendEmail();
//     }
//   }
//   delay(1000);
// }

// void sendEmail() {
//   smtp.debug(1);
//   smtp.callback(smtpCallback);
//   ESP_Mail_Session session;

//   session.server.host_name = SMTP_HOST;
//   session.server.port = SMTP_PORT;
//   session.login.email = AUTHOR_EMAIL;
//   session.login.password = AUTHOR_PASSWORD;
//   session.login.user_domain = F("mydomain.net");

//   session.time.ntp_server = F("pool.ntp.org, time.nist.gov");
//   session.time.gmt_offset = 3;
//   session.time.day_light_offset = 0;

//   SMTP_Message message;

//   message.sender.name = strSender;
//   message.sender.email = AUTHOR_EMAIL;
//   message.subject = strSubject;
//   message.addRecipient(strRecipientName, strRecipientMail);

//   String textMsg = strMsg;
//   message.text.content = textMsg;

//   message.text.charSet = F("utf-8");
//   message.text.transfer_encoding = Content_Transfer_Encoding::enc_7bit;
//   message.priority = esp_mail_smtp_priority::esp_mail_smtp_priority_low;
//   message.addHeader(F("Message-ID: <abcde.fghij@gmail.com"));

//   if(!smtp.connect(&session))
//     return;

//   if(!MailClient.sendMail(&smtp, &message)) {
//     Serial.print("Error sending Email, ");
//     Serial.println(smtp.errorReason());
//   }    
  
//   ESP_MAIL_PRINTF("Free Heap: %d\n", MailClient.getFreeHeap());
// }

// void smtpCallback(SMTP_Status status) {
//   Serial.println(status.info());

//   if(status.success())
//   {
//     Serial.println("--------------------");
//     ESP_MAIL_PRINTF("Message sent success: %d\n", status.completedCount());
//     ESP_MAIL_PRINTF("Message sent failed: %d\n", status.failedCount());
//     Serial.println("--------------------");
//     struct tm dt;

//     for(size_t i = 0; i < smtp.sendingResult.size(); i++)
//     {
//       SMTP_Result result = smtp.sendingResult.getItem(i);
//       time_t ts = (time_t)result.timestamp;
//       localtime_r(&ts, &dt);

//       ESP_MAIL_PRINTF("Message No: %d\n", i+1);
//       ESP_MAIL_PRINTF("Status: %s\n", result.completed ? "success" : "failed");
//       ESP_MAIL_PRINTF("Date/Time: %d/%d/%d/ %d:%d:%d\n", dt.tm_year+1900, dt.tm_mon+1, dt.tm_mday, dt.tm_hour, dt.tm_min, dt.tm_sec);
//       ESP_MAIL_PRINTF("Recipient: %s\n", result.recipients.c_str());
//       ESP_MAIL_PRINTF("Subject: %s\n", result.subject.c_str());
//     }
//     Serial.println("-----------------------\n");

//     smtp.sendingResult.clear();
//   }
// }
// // 초음파센서로 택배 검출하여 이메일 보내기
// #include <WiFi.h>
// #include <ESP_Mail_Client.h>

// #define WIFI_SSID "Wokwi-GUEST"
// #define WIFI_PASSWORD ""

// #define SMTP_HOST "smtp.gmail.com"

// #define SMTP_PORT esp_mail_smtp_port_587

// #define AUTHOR_EMAIL "taesamja12345@gmail.com"
// #define AUTHOR_PASSWORD "uazyldspzkimedmc"

// SMTPSession smtp;

// String strSender = "ESP32 송신";  // 보내는 사람 이름
// String strRecipientName = "부산전자공고 수신";  // 받는 사람 이름
// String strRecipientMail = "taesamja@naver.com"; // 받는 사람 메일 주소
// String strSubject = "택배 도착 The package is here"; // 메일 제목
// String strMsg = "소중한 택배가 도착했어요. !!! ^^"; // 메일 내용

// #define TRIG_PIN 27
// #define ECHO_PIN 26

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
//   Serial.println("");

//   pinMode(TRIG_PIN, OUTPUT);
//   pinMode(ECHO_PIN, INPUT);
// }

// void loop() {
//     digitalWrite(TRIG_PIN, HIGH);
//     delayMicroseconds(10);
//     digitalWrite(TRIG_PIN, LOW);
 
//     unsigned long duration = pulseIn(ECHO_PIN, HIGH);
 
//     float distanceCM = ((34000.0*(float)duration)/1000000.0)/2.0;
//     Serial.println(distanceCM);
   
//     if(distanceCM > 2 && distanceCM < 20) {
//       Serial.println("택배 검출");
//       sendEmail();
//       for(int i=0; i<360; i++)
//       {
//         delay(1000);
//       }
//     }  
//     delay(100);
// }

// // ----------- 규격화 된 메일 코드 시작 -----------------------
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
// // ----------- 규격화 된 메일 코드 끝 --------------------------
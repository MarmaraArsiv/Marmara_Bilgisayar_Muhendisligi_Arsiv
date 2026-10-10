@ -1,215 +0,0 @@
#include <SPI.h>
#include <SD.h>

#define CS_PIN         10
#define LDR_PIN        A0
#define LM35_PIN       A5
#define BUTON_PIN      2

#define KAYIT_MS       1000
#define SICAK_ESIK     35.0
#define SICAK_DUSUK    10.0
#define LDR_KARANLIK   200
#define LDR_COK_PARLAK 900
#define VREF           5.0

struct Istatistik {
  float sicakMax      = -999;
  float sicakMin      = 999;
  float sicakTop      = 0;
  int   ldrMax        = 0;
  int   ldrMin        = 1023;
  long  ldrTop        = 0;
  long  say           = 0;
  int   sicakAlarm    = 0;
  int   karanlikAlarm = 0;
};
Istatistik stat;

unsigned long sonKayit = 0;
unsigned long kayitNo  = 0;
bool butonOnceki       = HIGH;
bool sdHazir           = false;

char uptimeBuf[20];
char durumBuf[40];

void uptimeStr() {
  unsigned long ms  = millis();
  unsigned long sn  = ms / 1000;
  unsigned long dk  = sn / 60;
  unsigned long sa  = dk / 60;
  unsigned long gun = sa / 24;
  sn %= 60; dk %= 60; sa %= 24;
  sprintf(uptimeBuf, "%03lu-%02lu:%02lu:%02lu", gun, sa, dk, sn);
}

float sicaklikOku() {
  long top = 0;
  for (int i = 0; i < 8; i++) {
    top += analogRead(LM35_PIN);
    delay(5);
  }
  float voltaj = (top / 8.0) * (VREF / 1023.0);
  return voltaj * 100.0;
}

int ldrOku() {
  long top = 0;
  for (int i = 0; i < 4; i++) {
    top += analogRead(LDR_PIN);
    delay(2);
  }
  return top / 4;
}

void durumEtiket(float sicak, int ldr) {
  durumBuf[0] = '\0';
  if (sicak >= SICAK_ESIK)     strcat(durumBuf, "SICAK_ALARM|");
  if (sicak <= SICAK_DUSUK)    strcat(durumBuf, "SOGUK_ALARM|");
  if (ldr   <= LDR_KARANLIK)   strcat(durumBuf, "KARANLIK|");
  if (ldr   >= LDR_COK_PARLAK) strcat(durumBuf, "COK_PARLAK|");
  if (strlen(durumBuf) == 0)   strcat(durumBuf, "Normal");
  else durumBuf[strlen(durumBuf) - 1] = '\0'; // son | sil
}

void csvYaz(unsigned long no, float sicak, int ldr) {
  File f = SD.open("veri.csv", FILE_WRITE);
  if (!f) { Serial.println(F("ERR: veri.csv")); return; }
  if (f.size() == 0)
    f.println(F("No,Uptime,Sicaklik(C),LDR_Ham,LDR_Yuzde,Durum"));
  f.print(no);                         f.print(',');
  f.print(uptimeBuf);                  f.print(',');
  f.print(sicak, 2);                   f.print(',');
  f.print(ldr);                        f.print(',');
  f.print(map(ldr, 0, 1023, 0, 100)); f.print(',');
  f.println(durumBuf);
  f.close();
}

void ozetYaz() {
  if (SD.exists("ozet.txt")) SD.remove("ozet.txt");
  File f = SD.open("ozet.txt", FILE_WRITE);
  if (!f) { Serial.println(F("ERR: ozet.txt")); return; }

  float sicakOrt    = (stat.say > 0) ? (stat.sicakTop / stat.say) : 0;
  float ldrOrt      = (stat.say > 0) ? (stat.ldrTop / (float)stat.say) : 0;
  int   ldrOrtYuzde = map((int)ldrOrt, 0, 1023, 0, 100);

  f.println(F("========================================"));
  f.println(F("         OZET RAPORU"));
  f.println(F("========================================"));
  uptimeStr();
  f.print(F("Olusturuldu  : ")); f.println(uptimeBuf);
  f.print(F("Toplam kayit : ")); f.println(stat.say);
  f.println();
  f.println(F("-------- SICAKLIK ----------------------"));
  f.print(F("  Maksimum : ")); f.print(stat.sicakMax, 2); f.println(F(" C"));
  f.print(F("  Minimum  : ")); f.print(stat.sicakMin, 2); f.println(F(" C"));
  f.print(F("  Ortalama : ")); f.print(sicakOrt,      2); f.println(F(" C"));
  f.print(F("  Sicak alarm sayisi : ")); f.println(stat.sicakAlarm);
  f.println();
  f.println(F("-------- ISIK (LDR) --------------------"));
  f.print(F("  Maksimum : ")); f.print(stat.ldrMax);
  f.print(F(" (")); f.print(map(stat.ldrMax, 0, 1023, 0, 100)); f.println(F("%)"));
  f.print(F("  Minimum  : ")); f.print(stat.ldrMin);
  f.print(F(" (")); f.print(map(stat.ldrMin, 0, 1023, 0, 100)); f.println(F("%)"));
  f.print(F("  Ortalama : ")); f.print((int)ldrOrt);
  f.print(F(" (")); f.print(ldrOrtYuzde); f.println(F("%)"));
  f.print(F("  Karanlik alarm sayisi : ")); f.println(stat.karanlikAlarm);
  f.println();
  f.println(F("-------- ESIKLER -----------------------"));
  f.print(F("  Sicak alarm esigi  : ")); f.print(SICAK_ESIK,  1); f.println(F(" C"));
  f.print(F("  Soguk alarm esigi  : ")); f.print(SICAK_DUSUK, 1); f.println(F(" C"));
  f.print(F("  Karanlik LDR esigi : ")); f.println(LDR_KARANLIK);
  f.println(F("========================================"));
  f.close();

  Serial.println(F("========================================"));
  Serial.println(F(">>> ozet.txt yazildi <<<"));
  Serial.print(F("Kayit: "));    Serial.println(stat.say);
  Serial.print(F("SicakMax: ")); Serial.print(stat.sicakMax, 1); Serial.println(F(" C"));
  Serial.print(F("SicakMin: ")); Serial.print(stat.sicakMin, 1); Serial.println(F(" C"));
  Serial.print(F("LDRMax: "));   Serial.println(stat.ldrMax);
  Serial.print(F("LDRMin: "));   Serial.println(stat.ldrMin);
  Serial.println(F("========================================"));
}

void setup() {
  Serial.begin(9600);
  delay(500);

  pinMode(LDR_PIN,     INPUT);
  pinMode(LM35_PIN,    INPUT);
  pinMode(BUTON_PIN,   INPUT_PULLUP);
  pinMode(LED_BUILTIN, OUTPUT);

  Serial.println(F("========================================"));
  Serial.println(F("  Veri Toplayici v2 Basliyor..."));
  Serial.println(F("========================================"));

  if (!SD.begin(CS_PIN)) {
    Serial.println(F("HATA: SD kart baslatilamadi!"));
    sdHazir = false;
  } else {
    sdHazir = true;
    Serial.println(F("SD kart hazir."));
  }

  Serial.println(F("Format: No | Uptime | Sicak | LDR | %Isik | Durum"));
  Serial.println(F("Butona bas -> ozet.txt olustur"));
  Serial.println(F("----------------------------------------"));

  sonKayit = millis();
}

void loop() {
  unsigned long simdi = millis();

  bool butonSimdi = digitalRead(BUTON_PIN);
  if (butonOnceki == HIGH && butonSimdi == LOW) {
    delay(30);
    if (digitalRead(BUTON_PIN) == LOW) {
      Serial.println(F("BUTON BASILDI -> ozet yaziliyor..."));
      if (sdHazir) ozetYaz();
      else Serial.println(F("SD yok, ozet yazilamadi."));
    }
  }
  butonOnceki = butonSimdi;

  if (simdi - sonKayit >= KAYIT_MS) {
    sonKayit = simdi;
    kayitNo++;

    float sicak = sicaklikOku();
    int   ldr   = ldrOku();
    uptimeStr();
    durumEtiket(sicak, ldr);

    if (sicak > stat.sicakMax) stat.sicakMax = sicak;
    if (sicak < stat.sicakMin) stat.sicakMin = sicak;
    if (ldr   > stat.ldrMax)   stat.ldrMax   = ldr;
    if (ldr   < stat.ldrMin)   stat.ldrMin   = ldr;
    stat.sicakTop += sicak;
    stat.ldrTop   += ldr;
    stat.say++;
    if (sicak >= SICAK_ESIK)   stat.sicakAlarm++;
    if (ldr   <= LDR_KARANLIK) stat.karanlikAlarm++;

    digitalWrite(LED_BUILTIN, sicak >= SICAK_ESIK ? HIGH : LOW);

    if (sdHazir) csvYaz(kayitNo, sicak, ldr);

    if ((kayitNo - 1) % 15 == 0) {
      Serial.println(F("No     | Uptime       | Sicak   | LDR  | %Isik | Durum"));
      Serial.println(F("-------|--------------|---------|------|-------|-------"));
    }

    Serial.print(kayitNo);                      Serial.print(F("\t| "));
    Serial.print(uptimeBuf);                    Serial.print(F("\t| "));
    Serial.print(sicak, 2);                     Serial.print(F(" C\t| "));
    Serial.print(ldr);                          Serial.print(F("\t| "));
    Serial.print(map(ldr, 0, 1023, 0, 100));   Serial.print(F("%\t| "));
    Serial.println(durumBuf);
  }
}
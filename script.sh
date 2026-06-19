#!/bin/bash

KIRMIZI='\033[0;31m'
YESIL='\033[0;32m'
SARI='\033[0;33m'
RENKSIZ='\033[0m'

## Path yolları (hardcoded)
logpath="/var/log/"


echo -e "${SARI}APT paketleri güncelleniyor.. (şifre sorabilir, o yüzden lütfen şifrenizi girin)${RENKSIZ}"
sudo apt-get update && sudo apt upgrade -y

echo "Yollar Kontrol ediliyor.."

if [ -e "$logpath" ]; then
    echo -e "${SARI}[!] Günlük yolu mevcut.${RENKSIZ}"
else
    echo -e "${YESIL}[+] Günlük yolu oluşturuluyor..${RENKSIZ}"
    sudo mkdir -p "$logpath"
fi

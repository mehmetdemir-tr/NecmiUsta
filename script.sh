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

echo -e "${SARI}[?] RAM kontrol ediliyor..${RENKSIZ}"
BOS_RAM=$(free -m | awk 'NR==2{print $7}')
echo -e "${YESIL}[+] RAM Durumu: ${BOS_RAM} MB${RENKSIZ}"

if [ "$BOS_RAM" -lt 500 ]; then
    echo -e "${KIRMIZI}[!!] Sistem belleği çok düşük, sunucuda aksaklıklar çıkabilir..${RENKSIZ}"
else
    echo -e "${YESIL}[+] Sistem belleği stabil, devam ediliyor..${RENKSIZ}"
fi

read -p "Log klasörü temizlensin mi? (E/H) >> " KULLANICI

if [ "$KULLANICI" == "E" ] || [ "$KULLANICI" == "e" ]; then
    echo -e "${SARI}[!] Güvenli log temizliği yapılıyor...${RENKSIZ}"
    sudo find /var/log -type f -name "*.log" -exec truncate -s 0 {} \;
    echo -e "${YESIL}[+] Log dosyaları başarıyla sıfırlandı.${RENKSIZ}"
else
    echo -e "${RENKSIZ}Temizlik işlemi iptal edildi.${RENKSIZ}"
fi

read -p "Kullanıcı oluşturulsun mu? (E/H) >> " user1
if [ "$user1" == "E" ] || ["$user1" == "e" ]; then
   read -p "Kullanıcı adı girin >> " username
   sudo adduser "$username"
   echo -e "${YESIL}[+] Kullanıcı oluşturuldu.${RENKSIZ}"
   sudo usermod -aG sudo "$username"
   echo -e "${YESIL}[+] Kullanıcıya Yönetici hakları tanımlandı.${RENKSIZ}"

else
   echo -e "${KIRMIZI}[-] İptal edildi.${RENKSIZ}"
fi
sleep 2
clear
cat << 'EOF'
⠀⠀⠀⢸⣦⡀⠀⠀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⢸⣏⠻⣶⣤⡶⢾⡿⠁⠀⢠⣄⡀⢀⣴⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⣀⣼⠷⠀⠀⠁⢀⣿⠃⠀⠀⢀⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠴⣾⣯⣅⣀⠀⠀⠀⠈⢻⣦⡀⠒⠻⠿⣿⡿⠿⠓⠂⠀⠀⢀⡇⠀⠀⠀⠀⠀⠀⠀Necmi Ustanın
⠀⠀⠀⠉⢻⡇⣤⣾⣿⣷⣿⣿⣤⠀⠀⣿⠁⠀⠀⠀⢀⣴⣿⣿⠀⠀⠀⠀⠀⠀⠀  İsviçre Çakısı
⠀⠀⠀⠀⠸⣿⡿⠏⠀⢀⠀⠀⠿⣶⣤⣤⣤⣄⣀⣴⣿⡿⢻⣿⡆⠀⠀⠀⠀⠀⠀          
⠀⠀⠀⠀⠀⠟⠁⠀⢀⣼⠀⠀⠀⠹⣿⣟⠿⠿⠿⡿⠋⠀⠘⣿⣇⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⢳⣶⣶⣿⣿⣇⣀⠀⠀⠙⣿⣆⠀⠀⠀⠀⠀⠀⠛⠿⣿⣦⣤⣀⠀⠀
⠀⠀⠀⠀⠀⠀⣹⣿⣿⣿⣿⠿⠋⠁⠀⣹⣿⠳⠀⠀⠀⠀⠀⠀⢀⣠⣽⣿⡿⠟⠃
⠀⠀⠀⠀⠀⢰⠿⠛⠻⢿⡇⠀⠀⠀⣰⣿⠏⠀⠀⢀⠀⠀⠀⣾⣿⠟⠋⠁⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠀⠀⣰⣿⣿⣾⣿⠿⢿⣷⣀⢀⣿⡇⠁⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠉⠁⠀⠀⠀⠀⠙⢿⣿⣿⠇⠀⠀⠀⠀⠀⠀     by mehmetdemir-tr
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀                                                                                 
EOF
echo -e "${YESIL}[+] Konfigürasyon tamamlandı, sunucu artık kullanılmaya hazır!${RENKSIZ}"
sleep 3

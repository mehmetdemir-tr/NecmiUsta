// Translated from bash to C file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define KIRMIZI  "\033[0;31m"
#define YESIL    "\033[0;32m"
#define SARI     "\033[0;33m"
#define MAVI     "\033[0;34m"
#define RENKSIZ  "\033[0m"

void logo_goster() {
    printf("%s", MAVI);
    printf("⠀⠀⠀⢸⣦⡀⠀⠀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⢸⣏⠻⣶⣤⡶⢾⡿⠁⠀⢠⣄⡀⢀⣴⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⣀⣼⠷⠀⠀⠁⢀⣿⠃⠀⠀⢀⣿⣿⣿⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠴⣾⣯⣅⣀⠀⠀⠀⠈⢻⣦⡀⠒⠻⠿⣿⡿⠿⠓⠂⠀⠀⢀⡇⠀⠀⠀⠀⠀⠀⠀Necmi Ustanın\n");
    printf("⠀⠀⠀⠉⢻⡇⣤⣾⣿⣷⣿⣿⣤⠀⠀⣿⠁⠀⠀⠀⢀⣴⣿⣿⠀⠀⠀⠀⠀⠀⠀  İsviçre Çakısı\n");
    printf("⠀⠀⠀⠀⠸⣿⡿⠏⠀⢀⠀⠀⠿⣶⣤⣤⣤⣄⣀⣴⣿⡿⢻⣿⡆⠀⠀⠀⠀⠀⠀          \n");
    printf("⠀⠀⠀⠀⠀⠟⠁⠀⢀⣼⠀⠀⠀⠹⣿⣟⠿⠿⠿⡿⠋⠀⠘⣿⣇⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⢳⣶⣶⣿⣿⣇⣀⠀⠀⠙⣿⣆⠀⠀⠀⠀⠀⠀⠛⠿⣿⣦⣤⣀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⣹⣿⣿⣿⣿⠿⠋⠁⠀⣹⣿⠳⠀⠀⠀⠀⠀⠀⢀⣠⣽⣿⡿⠟⠃\n");
    printf("⠀⠀⠀⠀⠀⢰⠿⠛⠻⢿⡇⠀⠀⠀⣰⣿⠏⠀⠀⢀⠀⠀⠀⣾⣿⠟⠋⠁⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠀⠀⣰⣿⣿⣾⣿⠿⢿⣷⣀⢀⣿⡇⠁⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠋⠉⠁⠀⠀⠀⠀⠙⢿⣿⣿⠇⠀⠀⠀⠀⠀⠀     by mehmetdemir-tr\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠙⢿⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠀⠀⠀⠀⠀⠀⠀\n");
    printf("%s", RENKSIZ);
}

void f_saglik() {
    printf("%s--- Sistem Sağlık Kontrolü ---%s\n", MAVI, RENKSIZ);
    system("[ -d /var/log ] && echo -e '" YESIL "[+] /var/log dizini mevcut.'" RENKSIZ " || echo -e '" SARI "[-] /var/log bulunamadı.' " RENKSIZ);
    system("free -m | awk 'NR==2{print \"" YESIL "[+] Boş RAM Durumu: \" $7 \" MB\" " RENKSIZ "}'");
}

void f_temizlik() {
    printf("%s[!] Güvenli log temizliği başlatılıyor...%s\n", SARI, RENKSIZ);
    system("sudo find /var/log -type f -name \"*.log\" -exec truncate -s 0 {} \\;");
    printf("%s[+] Log dosyaları başarıyla sıfırlandı.%s\n", YESIL, RENKSIZ);
}

void f_bakim() {
    int secim;
    printf("\n1) Bakım Modunu AÇ (Trafiği Engelle)\n2) Bakım Modunu KAPAT (Trafiği Aç)\nSeçiminiz >> ");
    if (scanf("%d", &secim) != 1) return;

    if (secim == 1) {
        printf("%s[!] Sunucu Bakım Moduna Alınıyor...%s\n", KIRMIZI, RENKSIZ);
        system("sudo iptables -A INPUT -p tcp --dport 80 -j DROP");
        system("sudo iptables -A INPUT -p tcp --dport 443 -j DROP");
        printf("%s[+] BAKIM AKTİF: HTTP/HTTPS trafiği engellendi.%s\n", KIRMIZI, RENKSIZ);
    } else if (secim == 2) {
        printf("%s[+] Sunucu Bakım Modundan Çıkarılıyor...%s\n", YESIL, RENKSIZ);
        system("sudo iptables -D INPUT -p tcp --dport 80 -j DROP");
        system("sudo iptables -D INPUT -p tcp --dport 443 -j DROP");
        printf("%s[+] BAKIM KAPALI: Sunucu trafiğe açıldı.%s\n", YESIL, RENKSIZ);
    }
}

void f_ag() {
    printf("%s--- Ağ ve Sürücü Teşhisi ---%s\n", MAVI, RENKSIZ);
    printf("%s[*] Donanım Listesi:%s\n", SARI, RENKSIZ);
    system("lspci | grep -i -E \"ethernet|network|wireless\" || echo 'Donanım listelenemedi (WSL kısıtı).' ");
    printf("\n%s[*] Ağ Arayüzleri:%s\n", SARI, RENKSIZ);
    system("ip link show");
    printf("\n%s[*] Ping Testi (8.8.8.8):%s\n", SARI, RENKSIZ);
    system("ping -c 3 8.8.8.8");
}

void f_kisayollar() {
    printf("%s--- Kısayollar ve Sistem Özeti ---%s\n", MAVI, RENKSIZ);
    printf("1. İşlemci Bilgisi:  lscpu | grep 'Model name'\n");
    printf("2. Disk Durumu:      df -h\n");
    printf("3. Açık Portlar:     sudo ss -tulpn\n");
    system("uptime");
}

void f_restart() {
    char onay;
    printf("Sunucu ŞİMDİ yeniden başlatılacak. Emin misiniz? (E/H) >> ");
    if (scanf(" %c", &onay) != 1) return;
    if (onay == 'E' || onay == 'e') {
        printf("%s[!] Sunucu kapatılıyor...%s\n", KIRMIZI, RENKSIZ);
        system("sudo shutdown -r now");
    }
}

void ana_menu() {
    int secim;
    logo_goster();
    while (1) {
        printf("\n%s=====================================%s\n", SARI, RENKSIZ);
        printf("       %sNECMİ USTA MENÜ%s\n", YESIL, RENKSIZ);
        printf("%s=====================================%s\n", SARI, RENKSIZ);
        printf("1) Sağlık Kontrolü\n2) Log Temizliği\n3) Bakım Modu\n4) Ağ Teşhisi\n5) Kısayollar\n6) Sunucu Restart\n0) Çıkış\n>> ");
        if (scanf("%d", &secim) != 1) break;

        switch (secim) {
            case 1: f_saglik(); break;
            case 2: f_temizlik(); break;
            case 3: f_bakim(); break;
            case 4: f_ag(); break;
            case 5: f_kisayollar(); break;
            case 6: f_restart(); break;
            case 0: exit(0);
            default: printf("Hatalı seçim.\n");
        }
    }
}

int main(int argc, char *argv[]) {
    char *prog_name = strrchr(argv[0], '/');
    if (prog_name) prog_name++;
    else prog_name = argv[0];

    if (strcmp(prog_name, "necmi-sağlık") == 0) {
        f_saglik();
    } else if (strcmp(prog_name, "necmi-temizlik") == 0) {
        f_temizlik();
    } else if (strcmp(prog_name, "necmi-bakım") == 0) {
        f_bakim();
    } else if (strcmp(prog_name, "necmi-ağ") == 0) {
        f_ag();
    } else {
        ana_menu();
    }
    return 0;
}

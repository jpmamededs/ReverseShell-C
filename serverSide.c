#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

    printf("██████╗ ███████╗██╗   ██╗███████╗██████╗ ███████╗███████╗\n");
    sleep(0.2);
    printf("██╔══██╗██╔════╝██║   ██║██╔════╝██╔══██╗██╔════╝██╔════╝\n");
    sleep(0.2);
    printf("██████╔╝█████╗  ██║   ██║█████╗  ██████╔╝███████╗█████╗  \n");
    sleep(0.2);
    printf("██╔══██╗██╔══╝  ╚██╗ ██╔╝██╔══╝  ██╔══██╗╚════██║██╔══╝  \n");
    sleep(0.2);
    printf("██║  ██║███████╗ ╚████╔╝ ███████╗██║  ██║███████║███████╗\n");
    sleep(0.2);
    printf("╚═╝  ╚═╝╚══════╝  ╚═══╝  ╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝\n\n");
    sleep(0.4);
    printf("███████╗██╗  ██╗███████╗██╗     ██╗                      \n");   
    sleep(0.2);               
    printf("██╔════╝██║  ██║██╔════╝██║     ██║                      \n");
    sleep(0.2);
    printf("███████╗███████║█████╗  ██║     ██║                      \n");
    sleep(0.2);
    printf("╚════██║██╔══██║██╔══╝  ██║     ██║                      \n");
    sleep(0.2); 
    printf("███████║██║  ██║███████╗███████╗███████╗                 \n");
    sleep(0.2);
    printf("╚══════╝╚═╝  ╚═╝╚══════╝╚══════╝╚══════╝                 \n");
    sleep(0.2);

    sleep(3);
    system("clear");

    printf("[*] Starting Netcat listener on port 8081...\n");

    int ret = system("nc -nvlp 8081");

    if (ret == -1) {
        fprintf(stderr, "[!] Failed to start Netcat. Make sure 'nc' is installed and in your PATH.\n");
        return 1;
    }

    printf("[*] Listener terminated.\n");
    return 0;
}

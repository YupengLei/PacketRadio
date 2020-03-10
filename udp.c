/*
   CS656-002 Group W3
   Vincent (vc342), Owen (oeh3), Yupeng (yl2236), Yanxinwen (yl2235)
   Pranav (pg449), Indira (ian8)
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char *argv[]) {

    if (argc != 7) {
        perror("Incorrect amount of parameters\nFormat is: {host IP} {port} {filename} {Delay in microseconds} {packet size} {Free to put anything}");
    }
    char* host = argv[1];
    int portNumber = atoi(argv[2]);
    char* filename = argv[3];
    int delay = atoi(argv[4]);
    int packetSize = atoi(argv[5]);

    int socketdest;
    char packet[packetSize];
    struct sockaddr_in serverAddr;

    socketdest = socket(PF_INET, SOCK_DGRAM, 0);

    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(portNumber);
    serverAddr.sin_addr.s_addr = inet_addr(host);

    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        perror("Error: ");
        return(-1);
    }
    while(1) {
        int read = fread(packet, 1, packetSize, file);

        if (read > 0) {
            sendto(socketdest, packet, packetSize, 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
            usleep(delay);
        }
        if (read < packetSize) {
            if (feof(file)) {
                printf("End of file\nPlayback completed\n");
                break;
            }
            if (ferror(file)) {
                perror("Error: ");
                return(-1);
            }
        }
    }
    fclose(file);
    return 0;
}

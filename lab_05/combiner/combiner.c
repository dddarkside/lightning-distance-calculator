//#include "stdio.h"
//#include "stdlib.h"
//
//
//int main() {
//	/*char a = 'a';
//	char* p = &a;
//	char** black_list = (char**)malloc(sizeof(char*));
//	black_list[0] = p;
//	char vivod = black_list[0][0];*/
//
//	char* a = (char*)"abcd";
//	char b = a[1];
//}

#include "stdio.h"
#include <fcntl.h>
#include <sys\types.h>
#include <sys\stat.h>
#include "locale.h"
#include "string.h"
#include "io.h"
//#include <unistd.h>

#define FIFO_LIMIT 15
#define LIGHTNING_LEVEL 11999
#define SECS_IN_DAY 86400
#define SECS_IN_HOUR 3600
#define SECS_IN_MIN 60
#define SOUND_SPEED 343

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "rus");

    char fifo_name_l[FIFO_LIMIT];
    char fifo_name_s[FIFO_LIMIT];
    strcpy(fifo_name_l, argv[1]);
    strcpy(fifo_name_s, argv[2]);
    int fd_l = open(fifo_name_l, O_RDONLY | O_NONBLOCK);
    int fd_s = open(fifo_name_s, O_RDONLY | O_NONBLOCK);

    int counter = 0;
    int light;
    int time1;
    int time2;
    char sound[5];
    char voidness;
    void* p_l = &light;
    void* p_t1 = &time1;
    void* p_t2 = &time2;
    void* p_s = &sound;
    void* p_v = &voidness;
    while (1) {

        read(fd_l, p_l, sizeof(int));         // мб нужен atoi // данные
        read(fd_l, p_v, sizeof(char));   // '\n'
        read(fd_l, p_t1, sizeof(int));        // мб нужен atoi // время
        read(fd_l, p_v, sizeof(char));   // '\n'
        if (light > LIGHTNING_LEVEL) {
            printf("время измерения вспышки №%d: %d:%d:%d\n",
                ++counter,
                time1 / SECS_IN_DAY,
                time1 / SECS_IN_HOUR,
                time1 / SECS_IN_MIN);

            while (1) {
                read(fd_s, p_s, 5);
                read(fd_s, p_v, 5);
                read(fd_s, p_t2, 5); // мб нужен atoi
                read(fd_s, p_v, 5);
                if (sound[0] == 'C') {
                    printf("время измерения хлопка №%d: %d:%d:%d\n",
                        counter,
                        time2 / SECS_IN_DAY,
                        time2 / SECS_IN_HOUR,
                        time2 / SECS_IN_MIN);
                    printf("расстояние до грозы №%d: %d\n",
                        counter,
                        (time2 - time1) * SOUND_SPEED);
                    sound[0] = 'A'; // На всякий
                }
            }
        }
    }
}
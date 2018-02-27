/*
** EPITECH PROJECT, 2018
** navy.h
** File description:
** This is my header file for the navy project
*/

#ifndef NAVY_H_
	#define NAVY_H_

#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/redirect.h>

int is_it_valid(char *input);
int *take_input(void);
int *encrypt_message(int nb);
int game_loop(int player, int enemy_pid, int who_play, int positions[8][8]);
int nb_jumps(char *all, int opt, int fs, char *line);
int check_space(char *all, int nb_calls, int *check, int fs);
int copy_line(char *all, char *line, int i);
void reset_it(int fd, int *nb_calls, char *all);
char *get_next_line(int fd);
int wait_attack(void);
int hitted_or_not(int letter, int nb, int positions[8][8]);
void waiting(int positions[8][8], int enemy_pid);
void my_pid(void);
int good_place(char *line);
int no_double(char *line);
int good_line(char *line);
int good_nb_boats(char *str, char *line);
int good_text(char *str);
void print_usage(void);
int manage_p2(int argc, char *argv[]);
int manage_args(int argc, char *argv[]);
int my_str_isnum(char const *str);
int my_strcmp(char const *s1, char const *s2);
int is_it_hitted(int nb);
int count_hits(int map[8][8]);
int end_message(int positions[8][8], int enemy[8][8]);
int is_there_boat(int position);
int count_boats(int positions[8][8]);
int well_received(int nbsig, siginfo_t *info, void *ptr);
int well_sended(int nbsig, siginfo_t *info, void *ptr);
int first_received(void);
int first_send(int pid);
void my_putchar(char c);
int my_strlen(char *str);
int reverse_bin(int mess[3]);
int decrypt_message(int nbsig);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
int negative(char const *str, int i);
int apply_negative(int neg);
int end(char const *str, int i);
void initialize(int positions[8][8]);
void good_positions(char *line);
void put_positions(char *line, int positions[8][8]);
void get_positions(int positions[8][8], char *file);
int response(int nbsig, siginfo_t *info, void *ptr);
void wait_response(void);
void analyse_response(int *coord, int enemy[8][8]);
void draw_head(void);
void draw_boat(int nb, int j);
void which_positions(int which_map);
void display_map(int positions[8][8], int which_map);
void can_i_display(int player, int positions[8][8], int enemy[8][8]);
void my_strcpy(char *str, char *str2, int k);
char *null_or_not(char *line, int check, int fd);
int check_status(int check[4], char *all, char *line);
void attack(int enemy[8][8], int enemy_pid);
int received(int nbsig, siginfo_t *info, void *ptr);
int sended(int nbsig, siginfo_t *info, void *ptr);
void ready_to_kill(int *numb, int *letters, int pid);
int send_it(int letter, int nb, int pid);
int communication(void);
int main(int argc, char *argv[]);

#endif /* !NAVY_H_ */

#ifndef READ_SIZE
#define READ_SIZE (1000)
#endif /* !READ_SIZE */
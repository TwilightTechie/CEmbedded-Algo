#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<time.h>
#include<stdlib.h>
/*#include "hacking.h"*/

#define DATAFILE "/var/chance.data" //File to store user data

// Custom user struct to store information about users

struct user {
	int uid;
	int credits;
	int highscore;
	char name[100];
	int (*current_game) ();
};

// Function Prototype
int get_player_data();
void register_new_player();
void update_player_data();
void show_highscore();
void jackpot();
void input_name();
void print_cards();

int main(){
//TODO

}

//This function read the player data from the current UID
//from the file. It return -1 if it unable to find player
//data for the current UID.
int get_player_data() {
	int fd, uid, read_bytes;
	struct user entry;

	uid = getuid();

	fd = open(DATAFILE, O_RDONLY);
	if (fd == -1) //can't open the file, maybe it doesnt exist
		return -1;
	read_bytes = read(fd, &entry, sizeof(struct user)); // Read the first chunk
	while(entry.uid != uid && read_bytes > 0) { // loop untill proper uid is found
		read_bytes = read(fd, &entry, sizeof(struct user)); //keep reading
	}
	close(fd); //close the file.
	if(read_bytes < sizeof(struct user)) // This mean that the end of the file was reached.
		return -1;
	else
		player = entry // Copy the read entry into the player struct.
	return 1; // Return success
}

// This is the new user registration function.
// It will create a new player account and append it to the file.
void register_new_player() {
	int fd;

	printf("-=-={ New Player Registration }=-=-\n");
	printf("Enter Your name: ");
	input_name();

	player.uid = getuid();
	player.highscore = player.credits = 100;

	fd = open(DATAFILE, O_WRONLY|O_CREAT|O_APPEND, S_IRUSR|S_IWUSR);
	if (fd == -1)
		fatal("in register_new_player() while opening the file");
	write(fd, &player, sizeof(struct user));
	close(fd);

	printf("\nWelcome to the Game of Chance %s.\n",player.name);
	printf("You have given %u credits. \n", player.credits);
}

void update_player_data() {
	int fd, i, read_uid;
	char burned_byte;

	fd = open(DATAFILE, O_RDWR);
	if (fd == -1) // If open fails here, something is really wrong.
		fatal("in update_player_data() while opening the file");
	read(fd, &read_uid, 4); // Read the uid from the first struct
	while(read_uid != player.uid) { // Loop untill correct UID is found
		for (i = 0; i < sizeof(struct user) - 4; i ++) // Read through the
			read(fd, &burned_byte, 1); // rest of that struct
		read(fd, &read_uid, 4); // Read the uid from the next struct.
	}
	write(fd, &(player.credits), 4); // Update credits.
	write(fd, &(player.highscore), 4); // Update highscore.
	write(fd, &(player.name), 100); // Update name.
	close(fd);
}

//This function will display the current high score and
// the name of the person who set that high score.

void show_highscore() {
	unsigned int top_score = 0;
	char top_name[100];
	struct user entry;
	int fd;

	printf("\n======================| HIGH SCORE |=========================");
	fd = open(DATAFILE, O_RDONLY);
	if (fd == -1)
		fatal("in show_highscore() while opening file");
	while(read(fd, &entry, sizeof(struct user)) > 0){ // Loop untill end of the file.
		if(entry.highscore > top_score) { // If there is a higher score
			top_score = entry.highscore; //set top_score to that score
			strcpy(top_name, entry.name); // and top_name to that username.
		}
	}
	close(fd);
	if(top_score > player.highscore)
		printf("%s has the high score of %u\n", top_name, top_score);
	else
		printf("you currently have the high score of %u  credits!\n", player.highscore);
	printf("============================================================\n\n");
}

//This function simply award the jackpot for the Pick a Number game.
void jackpot() {
	printf("*+*+*+*+*+ JACKPOT *+*+*+*+*+\n");
	printf("You have won the jackpot of 100 credits!\n");
	player.credit += 100;
}

//This Function is used to input the player name, since
// scanf(%s, &whatever) will stop input at the first space.
void input_name() {
	char *name_ptr, input_char='\n';
	while(input_char == '\n') // Flush any leftover
		scanf("%c", &input_char); //newline chars

	name_ptr = (char *) &(player.name); //name_ptr = player's name address
	while(input_char != '\n') { //loop untill new lines
		*name_ptr = input_char; // Put the input char into name field
		scanf("%c", &input_char); // Get the next char.
		name_ptr++;
	}
	*name_ptr = 0; //Terminate the string.
}

// This function prints the 3 cards for the Find the ace game.
// It expects a message to display, a pointer to the cards array,
// and the card the user has picked as input. If the user_pick is
// -1, then the selection number are displayed.
void print_cards(char *message, char *cards, int user_pick) {
	int i;

	printf("\n\t*** %s ***\n", message);
	printf("    \t._.\t._.\t._.\n");
	printf("Cards:\t|%c|\t|%c|\t|%c|\n\t", cards[0], cards[1], cards[2]);
	if (user_pick == -1)
		printf(" 1 \t 2 \t 3 \t");
	else {
		for(i = 0; i < user_pick; i ++)
			printf("%t");
		printf(" ^--Your pick\n");
	}
}

// The function inputs wagers for both the No Match Dealer and
// Find the Ace games. It expects the available credits and the
// previous wager as arguments. The previous_wager is only important
// for the second wager in the Fid the Ace game. The function return
// -1 if the wager is too big or too little, and it returns the
// wager amout otherwise.



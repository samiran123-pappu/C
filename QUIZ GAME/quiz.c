#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif


void show_record();
void reset_score();
void help();
void edit_score(float, char []);


int main(){
    int countr, r, rl, count, i, n;
    float score;
    char choice;
    char playerName[20];
    time_t t;

    time(&t);

    printf("================================= your name please ==========================\n\t\t");
    fgets(playerName, 20, stdin);
    playerName[strcspn(playerName, "\n")] = '\0';

    mainhome:
    system(CLEAR);
    printf("\n\t\t _____________________________________________________________");



    printf("\n\t\t\t WELCOME ");
    printf("\n\t\t\t TO ");
    printf("\n\t\t\t QUIZ GAME %s ", playerName );
    printf("\n\t\t _____________________________________________________________");
    printf("\n\t\t _____________________________________________________________");
    printf("\n\t\t                                 TEST YOUR GENERAL KNOWLEDGE.... SET  YOUR OWN RECORD...!!");
    printf("\n\t\t _____________________________________________________________");
    printf("\n\t\t _____________________________________________________________");
    printf("\n\t\t PRESS S TO START THE GAME");
    printf("\n\t\t PRESS V TO VIEW THE HIGHEST SCORE  ");
    printf("\n\t\t PRESS R TO RESET SCORE");
    printf("\n\t\t PRESS H FOR HELP            ");
    printf("\n\t\t PRESS Q TO QUIT             ");
    printf("\n\t\t\t _____________________________________________________________");

    for(i=0; i<80; i++){
        printf("=");
    }
    printf("\nCurrent date and time : %s", ctime(&t));

    for(i=0; i<80; i++){
        printf("=");
    }
    printf("\n");
    choice = toupper(getchar());
    getchar();

    if(choice == 'S'){
        system(CLEAR);
        printf("--------------------------- Welcome %s to the Quiz Game ---------------------------\n", playerName);
        printf("\n\n Here are some tips you might wanna know before playing:");
        printf("---------------------------------------------------------------------------");
        printf("\n >> There are 2 rounds in this Quiz Game,WARMUP ROUND & CHALLANGE ROUND.");
        printf("\n >> In warmup round you will be asked a total of 6 questions to test your general");
        printf("\n    knowledge. You will be eligible to play the challange round if you can give atleast 2");
        printf("\n    right answers, otherwise you can't proceed further to the challange round.");
        printf("\n >> your game starts with the challange round in which you will be asked");
        printf("\n    a total of 23 questions. Each right answer will be awarded  $100,000.!!!");

        printf("\n By this way you can earn upto one MILLION DOLLARS...!!!");
        printf("\n >> You will be given 4 options and you have to press A, B, C or D for the");
        printf("\n    right answer.");
        printf("\n >> You will be asked questions continuously, till right answers are given");
        printf("\n >> No negative marking for wrong answers!");
        printf("\n\n\t!!!!!!!!!!!!!!! GOOD LUCK !!!!!!!!!!!!!!!.");

        printf("\n\n Press Y to start the game...\n");
        printf("\n Press any other key to return to the main menu\n!");



        if(toupper(getchar()) == 'Y'){
            goto home;
        }
        else{
            goto mainhome;
        }

    }
    if(choice == 'H'){
        help();
        getchar();
        goto mainhome;
    
    }else if(choice == 'V'){
        show_record();
        goto mainhome;
    }
    else if(choice == 'R'){
        reset_score();
        getchar();
        goto mainhome;
    }
    else if(choice == 'Q'){
        system(CLEAR);
        printf("\n\n\n\t\t\t THANKS FOR PLAYING THE GAME. HAVE A NICE DAY..\n\n\n");
        exit(1);
    }
    else{
        printf("\n\n\t\t\t Invalid choice! Please try again.\n\n");
        goto mainhome;
    }

    home:
    system(CLEAR);
    count = 0;
    for(i=1; i<=6; i++){
        getchar();
        system(CLEAR);
        r = i;
        switch(r){
            case 1:
            printf("\n\nWhat is the capital of India?\n\n");
            printf("A. Mumbai\t\tB. Kolkata\n\n");
            printf("C. Chennai\t\tD. Delhi\n\n");
            printf("Your answer: ");
            if(toupper(getchar()) == 'D'){
                printf("\nCorrect!!!\n");
                count++;
            }
            else{
                printf("\nWrong!!! The correct answer is D. Delhi\n");
            }
            break;
            case 2:
            printf("\n\nWho is the current president of USA?\n\n");
            printf("A. Donald Trump\t\tB. Joe Biden\n\n");
            printf("C. George W. Bush\t\tD. Bill Clinton\n\n");
            printf("Your answer: ");
            if(toupper(getchar()) == 'B'){
                printf("\nCorrect!!!\n");
                count++;
            }
            else{
                printf("\nWrong!!! The correct answer is B. Joe Biden\n");
            }
            break;
            case 3:
            printf("\n\nWhich planet is known as the Red Planet?\n\n");
            printf("A. Venus\t\tB. Mars\n\n");
            printf("C. Jupiter\t\tD. Saturn\n\n");
            printf("Your answer: ");
            if(toupper(getchar()) == 'B'){
                printf("\nCorrect!!!\n");
                count++;
            }
            else{
                printf("\nWrong!!! The correct answer is B. Mars\n");
            }
            break;
            case 4:
            printf("\n\nWhich planet is known as the Blue Planet?\n\n");
            printf("A. Venus\t\tB. Mars\n\n");
            printf("C. Jupiter\t\tD. Saturn\n\n");
            printf("Your answer: ");
            if(toupper(getchar()) == 'D'){
                printf("\nCorrect!!!\n");
                count++;
            }
            else{
                printf("\nWrong!!! The correct answer is D. Saturn\n");
            }
            break;
            case 5:
            printf("\n\nWhich planet is known as the Green Planet?\n\n");
            printf("A. Venus\t\tB. Mars\n\n");
            printf("C. Jupiter\t\tD. Saturn\n\n");
            printf("Your answer: ");
            if(toupper(getchar()) == 'A'){
                printf("\nCorrect!!!\n");
                count++;
            }
            else{
                printf("\nWrong!!! The correct answer is A. Venus\n");
            }
            break;
            case 6:
            printf("\n\nWhich planet is known as the Gas Giant?\n\n");
            printf("A. Venus\t\tB. Mars\n\n");
            printf("C. Jupiter\t\tD. Saturn\n\n");
            printf("Your answer: ");
            if(toupper(getchar()) == 'C'){
                printf("\nCorrect!!!\n");
                count++;
            }
            else{
                printf("\nWrong!!! The correct answer is C. Jupiter\n");
            }
            break;
        }
    }

    if(count >= 2){
        system(CLEAR);
        printf("\n\n\t\t CONGRATULATIONS %s! YOU ARE ELIGIBLE FOR THE CHALLANGE ROUND\n", playerName);
        printf("\n\t\t Press Enter to continue...");
        getchar();

        countr = 0;
        for(i=7; i<=23; i++){
            getchar();
            system(CLEAR);
            r = i;
            switch(r){
                case 7:
                printf("\n\nWhich planet is known as the Ice Giant?\n\n");
                printf("A. Venus\t\tB. Mars\n\n");
                printf("C. Jupiter\t\tD. Saturn\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'D'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is D. Saturn\n");
                }
                break;

                case 8:
                printf("\n\nWhich planet is known as the Gas Giant?\n\n");
                printf("A. Venus\t\tB. Mars\n\n");
                printf("C. Jupiter\t\tD. Saturn\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'C'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is C. Jupiter\n");
                }
                break;

                case 9:
                printf("\n\nWhich planet is known as the Dwarf Planet?\n\n");
                printf("A. Venus\t\tB. Mars\n\n");
                printf("C. Jupiter\t\tD. Saturn\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'B'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is B. Mars\n");
                }
                break;

                case 10:
                printf("\n\nWhich planet is known as the Ringed Planet?\n\n");
                printf("A. Venus\t\tB. Mars\n\n");
                printf("C. Jupiter\t\tD. Saturn\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'D'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is D. Saturn\n");
                }
                break;

                case 11:
                printf("\n\nWhich planet is known as the Largest Planet?\n\n");
                printf("A. Venus\t\tB. Mars\n\n");
                printf("C. Jupiter\t\tD. Saturn\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'C'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is C. Jupiter\n");
                }
                break;

                case 12:
                printf("\n\nWhat is the national animal of India?\n\n");
                printf("A. Lion\t\tB. Tiger\n\n");
                printf("C. Elephant\t\tD. Peacock\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'B'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is B. Tiger\n");
                }
                break;

                case 13:
                printf("\n\nWhich is the largest ocean in the world?\n\n");
                printf("A. Atlantic Ocean\t\tB. Indian Ocean\n\n");
                printf("C. Pacific Ocean\t\tD. Arctic Ocean\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'C'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is C. Pacific Ocean\n");
                }
                break;

                case 14:
                printf("\n\nWhat does CPU stand for?\n\n");
                printf("A. Central Program Unit\t\tB. Central Processing Unit\n\n");
                printf("C. Control Processing Unit\t\tD. Computer Processing Unit\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'B'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is B. Central Processing Unit\n");
                }
                break;

                case 15:
                printf("\n\nWhat is the chemical formula of water?\n\n");
                printf("A. CO2\t\tB. O2\n\n");
                printf("C. H2O\t\tD. NaCl\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'C'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is C. H2O\n");
                }
                break;

                case 16:
                printf("\n\nWho wrote Hamlet?\n\n");
                printf("A. Charles Dickens\t\tB. William Shakespeare\n\n");
                printf("C. Mark Twain\t\tD. Rabindranath Tagore\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'B'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is B. William Shakespeare\n");
                }
                break;

                case 17:
                printf("\n\nWhat is the fastest land animal?\n\n");
                printf("A. Lion\t\tB. Tiger\n\n");
                printf("C. Cheetah\t\tD. Horse\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'C'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is C. Cheetah\n");
                }
                break;

                case 18:
                printf("\n\nWhat is the currency of Japan?\n\n");
                printf("A. Won\t\tB. Yen\n\n");
                printf("C. Dollar\t\tD. Peso\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'B'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is B. Yen\n");
                }
                break;

                case 19:
                printf("\n\nWhat is 12 x 8?\n\n");
                printf("A. 86\t\tB. 94\n\n");
                printf("C. 96\t\tD. 98\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'C'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is C. 96\n");
                }
                break;

                case 20:
                printf("\n\nWho is known as the Father of the Nation in India?\n\n");
                printf("A. Jawaharlal Nehru\t\tB. Sardar Patel\n\n");
                printf("C. Mahatma Gandhi\t\tD. Subhas Chandra Bose\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'C'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is C. Mahatma Gandhi\n");
                }
                break;

                case 21:
                printf("\n\nIn which year did India get independence?\n\n");
                printf("A. 1947\t\tB. 1950\n\n");
                printf("C. 1935\t\tD. 1962\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'A'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is A. 1947\n");
                }
                break;

                case 22:
                printf("\n\nWhich gas do plants absorb from the atmosphere?\n\n");
                printf("A. Oxygen\t\tB. Nitrogen\n\n");
                printf("C. Carbon Dioxide\t\tD. Hydrogen\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'C'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is C. Carbon Dioxide\n");
                }
                break;

                case 23:
                printf("\n\nWho developed the C programming language?\n\n");
                printf("A. Bjarne Stroustrup\t\tB. Dennis Ritchie\n\n");
                printf("C. James Gosling\t\tD. Guido van Rossum\n\n");
                printf("Your answer: ");
                if(toupper(getchar()) == 'B'){
                    printf("\nCorrect!!!\n");
                    countr++;
                }
                else{
                    printf("\nWrong!!! The correct answer is B. Dennis Ritchie\n");
                }
                break;
            }
        }

        score = (float)countr * 100000;
        system(CLEAR);
        printf("\n\n\t\t********** QUIZ COMPLETED **********\n");
        printf("\n\t\tCorrect answers in challange round: %d out of 17\n", countr);
        printf("\n\t\tYour winning amount is: $%.0f\n", score);
        edit_score(score, playerName);
    }
    else{
        system(CLEAR);
        printf("\n\nSORRY %s, you are not eligible for the challange round.\n", playerName);
        printf("You gave only %d correct answers in warmup round.\n", count);
    }

    printf("\n\nPress any key to return to main menu...");
    getchar();
    goto mainhome;
}

void show_record(){
    FILE *f;
    float score;
    char name[20];

    f = fopen("score.txt", "r");
    if(f == NULL){
        printf("\n\nNO RECORD AVAILABLE YET.\n");
        return;
    }

    if(fscanf(f, "%f\n", &score) != 1){
        fclose(f);
        printf("\n\nNO RECORD AVAILABLE YET.\n");
        return;
    }

    if(fgets(name, 20, f) == NULL){
        strcpy(name, "Unknown");
    }
    name[strcspn(name, "\n")] = '\0';
    fclose(f);

    system(CLEAR);
    printf("\n\n		*******************************************\n");
    printf("\t	         HIGHEST SCORE RECORD\n");
    printf("\t\t*******************************************\n");
    printf("\n\t\t %s has secured the highest score: $%.0f\n", name, score);
    printf("\n\t\t*******************************************\n");
    printf("\nPress Enter to continue...");
    getchar();
}

void reset_score(){
    FILE *f;
    f = fopen("score.txt", "w");
    if(f == NULL){
        printf("\n\nUnable to reset score file.\n");
        return;
    }

    fprintf(f, "0\nNoName\n");
    fclose(f);
    printf("\n\nScore has been reset successfully.\n");
}

void help(){
    system(CLEAR);
    printf("\n\n				 HELP");
    printf("\n -------------------------------------------------------------------------");
    printf("\n 1. In warmup round, answer at least 2 out of 6 questions correctly.");
    printf("\n 2. Then you can enter the challange round with questions up to case 23.");
    printf("\n 3. Each correct answer in challange round gives you $100,000.");
    printf("\n 4. Choose option A, B, C or D and press Enter.");
    printf("\n 5. You can view and reset high score from main menu.");
    printf("\n -------------------------------------------------------------------------");
    printf("\n Press Enter to go back to main menu...");
}

void edit_score(float score, char plnm[]){
    FILE *f;
    float oldScore = 0;
    char oldName[20] = "NoName";

    f = fopen("score.txt", "r");
    if(f != NULL){
        fscanf(f, "%f\n", &oldScore);
        if(fgets(oldName, 20, f) != NULL){
            oldName[strcspn(oldName, "\n")] = '\0';
        }
        fclose(f);
    }

    if(score >= oldScore){
        f = fopen("score.txt", "w");
        if(f != NULL){
            fprintf(f, "%.2f\n%s\n", score, plnm);
            fclose(f);
        }
        printf("\n\nCONGRATULATIONS %s!!! You set a new high score of $%.0f\n", plnm, score);
    }
    else{
        printf("\n\nYour score: $%.0f\n", score);
        printf("Current highest score: $%.0f by %s\n", oldScore, oldName);
    }
}
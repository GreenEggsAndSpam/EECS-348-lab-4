#include <stdio.h>

//function to find and print all combinations of scoring plays for a given score
void findCombinations(int score) {
    printf("Possible combinations of scoring plays if a team's score is %d:\n", score);
    //check for 8 point td
    for (int td8 = 0; td8 <= score / 8; td8++) {
        //7 point td
        for (int td7 = 0; td7 <= (score - td8 * 8) / 7; td7++) {
            //6 point td
            for (int td6 = 0; td6 <= (score - td8 * 8 - td7 * 7) / 6; td6++) {
                //3 point fieldgoal
                for (int fg = 0; fg <= (score - td8 * 8 - td7 * 7 - td6 * 6) / 3; fg++) {
                    //2 point safety
                    for (int safety = 0; safety <= (score - td8 * 8 - td7 * 7 - td6 * 6 - fg * 3) / 2; safety++) {
                        if (td8 * 8 + td7 * 7 + td6 * 6 + fg * 3 + safety * 2 == score) {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", td8, td7, td6, fg, safety);
                        }
                    }
                }
            }
        }
    }
}

int main() {
    int score;

    while (1) {
        //get the score from user
        printf("Enter the NFL score (Enter 0 or 1 to STOP): ");
        scanf("%d", &score);

        //enter 0 or 1 to exit 
        if (score <= 1) {
            break;
        }

        //executes function
        findCombinations(score);
    }

    return 0;
}

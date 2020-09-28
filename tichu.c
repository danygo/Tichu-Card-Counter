#include <stdio.h>

void initCards(int stack[][17]) {
    int i, j;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 17; j++) {
            stack[i][j] = j + 1;
        }
    }
}

void showCards(int stack[][17]) {
    int i, j;

    for (i = 0; i < 4; i++) {
        j = 0;

        while (j < 17) {
            if (stack[i][j] == 0) printf("0 ");
            else if (stack[i][j] == 1) printf("mah jong ");
            else if (stack[i][j] == 2) printf("hunds ");
            else if (stack[i][j] == 3) printf("phoenix ");
            else if (stack[i][j] == 4) printf("dragon ");
            else if (stack[i][j] == 14) printf("jack ");
            else if (stack[i][j] == 15) printf("queen ");
            else if (stack[i][j] == 16) printf("king ");
            else if (stack[i][j] == 17) printf("ace ");
            else printf("%d ", j - 2);

            j++;
        }

        printf("\n");
    }
}

void removeCard(int stack[][17], int cardColumn) {
    int i;

    if (cardColumn == 0 || cardColumn == 1 || cardColumn == 2 || cardColumn == 3) {
        for (i = 3; i >= 0; i--) stack[i][cardColumn] = 0;
    } else {
        for (i = 3; i >= 0; i--) {
            if (stack[i][cardColumn] != 0) {
                stack[i][cardColumn] = 0;
                break;
            }
        }
    }
}

int main(void) {
    int cards[4][17], i, index;
    char cardsPlayed[14];

    initCards(cards);

    while (1) {
        printf("enter cards played\n");
        scanf("%s", cardsPlayed);

        i = 0;

        while (cardsPlayed[i] != '\0') {
            if (cardsPlayed[i] == 'm') index = 0;
            else if (cardsPlayed[i] == 'h') index = 1;
            else if (cardsPlayed[i] == 'p') index = 2;
            else if (cardsPlayed[i] == 'd') index = 3;
            else if (cardsPlayed[i] == '2') index = 4;
            else if (cardsPlayed[i] == '3') index = 5;
            else if (cardsPlayed[i] == '4') index = 6;
            else if (cardsPlayed[i] == '5') index = 7;
            else if (cardsPlayed[i] == '6') index = 8;
            else if (cardsPlayed[i] == '7') index = 9;
            else if (cardsPlayed[i] == '8') index = 10;
            else if (cardsPlayed[i] == '9') index = 11;
            else if (cardsPlayed[i] == 't') index = 12;
            else if (cardsPlayed[i] == 'j') index = 13;
            else if (cardsPlayed[i] == 'q') index = 14;
            else if (cardsPlayed[i] == 'k') index = 15;
            else if (cardsPlayed[i] == 'a') index = 16;
            else return 0;

            removeCard(cards, index);

            i++;
        }

        showCards(cards);
    }

    return 0;
}

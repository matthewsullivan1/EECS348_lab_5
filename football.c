#include <stdio.h>

void display(int td2pt, int td1pt, int td, int fg, int safety) {
    printf("%d TD + 2pt, %d TD + 1pt, + %d TD, + %d 3pt FG, + %d Safety\n", td2pt, td1pt, td, fg, safety);
}

int main() {
    int score;

    while (1) {
        printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1) {
            break;
        }

        printf("Possible combinations of scoring plays:\n");

        for (int td2pt = 0; td2pt * 8 <= score; td2pt++) {
            for (int td1pt = 0; td1pt * 7 <= score; td1pt++) {
                for (int td = 0; td * 6 <= score; td++) {
                    for (int fg = 0; fg * 3 <= score; fg++) {
                        for (int safety = 0; safety * 2 <= score; safety++) {
                            int sum = td2pt * 8 + td1pt * 7 + td * 6 + fg * 3 + safety * 2;
                            if (sum == score) {
                                display(td2pt, td1pt, td, fg, safety);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}